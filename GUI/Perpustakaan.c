#include "raylib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 70
typedef enum GameScreen { LOGO = 0, TITLE, INSERT, DELETE, SORT, VIEW } GameScreen;
typedef struct node {
	char judul[MAX];
	char tahun[MAX];
    char penulis[MAX];
	struct node *next;
} data;

data *head=NULL, *tail=NULL;

static void insert();
static void del();
static void view();
static void first();
static void sort();
static void second();
static void third();
static void fourth();
static void tulis();
static void rtxt();
static void ftxt();
static void clr();

int key;
int letterCount = 0;
int succes= 2;
char name[MAX + 1] = "\0";
char put[MAX + 1] = "\0";
char year[MAX + 1] = "\0";
char x[MAX + 1] = "\0";
char hapus[MAX + 1] = "\0";
char kosong[MAX + 1] = "STATUS: Menunggu Input";
char hasil[MAX + 1] = "\0";
char s1[MAX + 1] = "Berhasil! Buku telah dihapus.";
char s0[MAX + 1] = "Gagal! Buku tidak ditemukan.";

Rectangle textBox0 = { 1024/2 - 100, 340, 225, 50 };//opsi
Rectangle textBox1 = { 200, 205, 225, 30 };//name
Rectangle textBox2 = { 200, 245, 225, 30 };//penulis
Rectangle textBox3 = { 200, 285, 225, 30 };//year
Rectangle textBox4 = { 200, 200, 624, 30 };//delete
int j=0, k=0, l=0, m=1, input=0;
int framesCounter = 0;

int main()
{
    int screenWidth = 1024;
    int screenHeight = 768;
    
	InitWindow(screenWidth, screenHeight, "Library Management");
    ToggleFullscreen();
	SetTargetFPS(60);
    GameScreen currentScreen = LOGO;
    InitAudioDevice();
    Sound tc = LoadSound("resources/coin.wav");
    Music xm = LoadMusicStream("resources/back.xm");
    PlayMusicStream(xm);
    
    Image load = LoadImage("resources/load.png");
    Image home = LoadImage("resources/home.png");
    Image cert = LoadImage("resources/insert.png");
    Image pus = LoadImage("resources/del.png");
    Image pus1 = LoadImage("resources/del1.png");
    Image see = LoadImage("resources/boardn.png");
    Image abc = LoadImage("resources/abc.png");
    Texture2D text1 = LoadTextureFromImage(load);
    Texture2D text2 = LoadTextureFromImage(home);
    Texture2D text3 = LoadTextureFromImage(cert);
    Texture2D text4 = LoadTextureFromImage(pus);
    Texture2D text5 = LoadTextureFromImage(pus1);
    Texture2D text6 = LoadTextureFromImage(see);
    Texture2D text7 = LoadTextureFromImage(abc);
    UnloadImage(load);
    UnloadImage(home);
    UnloadImage(cert);
    UnloadImage(pus);
    UnloadImage(pus1);
    UnloadImage(see);
    UnloadImage(abc);
    
    // Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
        UpdateMusicStream(xm);
        switch(currentScreen) 
        {
            case LOGO: 
            {
             
                framesCounter++;
                
                if (framesCounter > 120)
                {
                    rtxt();
                    currentScreen = TITLE;
                }
            } break;
            case TITLE: 
            {
                if (IsKeyPressed(KEY_ONE))
                {
                    PlaySound(tc);
                    currentScreen = INSERT;
                }
                if (IsKeyPressed(KEY_TWO))
                {
                    PlaySound(tc);
                    currentScreen = DELETE;
                }
                if (IsKeyPressed(KEY_THREE))
                {
                    PlaySound(tc);
                    currentScreen = SORT;
                }
                if (IsKeyPressed(KEY_FOUR))
                {
                    PlaySound(tc);
                    currentScreen = VIEW;
                }

            } break;
            case INSERT:
            { 
                if (IsKeyPressed(KEY_F5))
                {
                    PlaySound(tc);
                    input = 0;
                    m = 1;
                    currentScreen = TITLE;  
                } 
             } break;
            case DELETE: 
            {
                if (IsKeyPressed(KEY_F5))
                {
                    PlaySound(tc);
                    input=0;
                    succes=2;
                    currentScreen = TITLE;
                }  
            } break;
            case SORT:
            {
                
                if (IsKeyPressed(KEY_F5))
                {
                    PlaySound(tc);
                    l=0;
                    currentScreen = TITLE;
                }
            }
            break; 
            case VIEW: 
            {
                if (IsKeyPressed(KEY_F5))
                {
                    PlaySound(tc);
                    currentScreen = TITLE;
                }  
            } break;
            default: break;
        }
	        BeginDrawing();
        
            ClearBackground(RAYWHITE);
            
            switch(currentScreen) 
            {
                case LOGO: 
                {
                    DrawTexture(text1, screenWidth/2 - text1.width/2, screenHeight/2 - text1.height/2, WHITE);
                    DrawText("Library Management", 20, 20, 40, LIGHTGRAY);
                    DrawText("LOADING", 430, 700, 40, LIGHTGRAY);
                    
                } break;
                case TITLE: 
                {
                    ClearBackground(WHITE);
                    DrawTexture(text2, 500, 150, WHITE);

                    DrawRectangle(10, 10, 445, 50, GRAY);
                    DrawText("Library Management", 30, 15, 40, YELLOW);
                    DrawText("Menu", 120, 150, 50, BROWN);
                    DrawText("1. Simpan Buku", 120, 210, 20, ORANGE);
                    DrawText("2. Hapus Buku", 120, 240, 20, ORANGE);
                    DrawText("3. Urut Buku", 120, 270, 20, ORANGE);
                    DrawText("4. Tampilkan Buku", 120, 300, 20, ORANGE);
                    DrawText("Tekan salah satu angka!", 120, 350, 20, RED);
                    DrawText("Tekan ESC untuk keluar.", 40, 720, 20, BLUE);
                } break;
                case INSERT:
                {
                    if (IsKeyPressed(KEY_F5))
                    {
                    while(letterCount>=0){
                        name[letterCount] = '\0';       
                        letterCount--;
                    }
                    if (letterCount < 0) letterCount = 0;
                    while(letterCount>=0){
                        put[letterCount] = '\0';       
                        letterCount--;
                        }
                    if (letterCount < 0) letterCount = 0;
                    while(letterCount>=0){
                            year[letterCount] = '\0';       
                            letterCount--;
                            }
                    if (letterCount < 0) letterCount = 0;    
                    } 
                    ClearBackground(RAYWHITE);
                    DrawTexture(text3, 300, 400, WHITE);
                    DrawText("Tekan F5 untuk kembali.", 40, 720, 20, BLUE);
                    second();
                } break;
                case DELETE: 
                {
                    ClearBackground(WHITE);
                    DrawTexture(text4, 700, 300, WHITE);
                    DrawTexture(text5, 450, 500, WHITE);
                    DrawText("Tekan F5 untuk kembali.", 40, 720, 20, BLUE);
                    third();
                } break;
                case SORT:
                {
                    ClearBackground(RAYWHITE);
                    DrawTexture(text7, 400, 350, WHITE);
                    first();
                }
                break;
                case VIEW: 
                {
                    DrawTexture(text6, 0, 0, WHITE);
                    DrawText("Tekan F5 untuk kembali.", 40, 715, 20, RED);
                    DrawText("Tekan ENTER untuk menyimpan data (overwrite) ke file Database.txt", 40, 745, 20, YELLOW);
                    fourth();      
                } break;
                default: break;
            }
        
        EndDrawing();
    }
    UnloadTexture(text1);
    UnloadTexture(text2);
    UnloadTexture(text3);
    UnloadTexture(text4);
    UnloadTexture(text5);
    UnloadTexture(text6);
    UnloadTexture(text7);
    UnloadMusicStream(xm);
    UnloadSound(tc);
    CloseAudioDevice();
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
//    ftxt();
	return 0;
}

void clr(){//bersihkan input
    while(letterCount>=0){
        x[letterCount] = '\0';       
        letterCount--;
        }
    if (letterCount < 0) letterCount = 0;
}

void second(){
    DrawRectangle(10, 5, 250, 30, RED);
    DrawText("Library Management", 30, 10, 20, ORANGE);
    DrawText(FormatText("DATA-%d", m), 40, 140, 50, BROWN);
    DrawText("Judul Buku   : ", 40, 210, 20, BLUE);       
    DrawText("Penulis        : ", 40, 250, 20, BLUE);
    DrawText("Tahun         : ", 40, 290, 20, BLUE);
     
    DrawRectangleRec(textBox1, LIGHTGRAY);
    DrawText(name, textBox1.x + 5, textBox1.y + 8, 20, MAROON);
    DrawRectangleRec(textBox2, LIGHTGRAY);
    DrawText(put, textBox2.x + 5, textBox2.y + 8, 20, MAROON);
    DrawRectangleRec(textBox3, LIGHTGRAY);
    DrawText(year, textBox3.x + 5, textBox3.y + 8, 20, MAROON);

    framesCounter++;
    switch(input){
        case 0: clr();
                input=1; 
                break;
        case 1: if (((framesCounter/20)%2) == 0) DrawRectangleLines(textBox1.x, textBox1.y, textBox1.width, textBox1.height, RED);
                tulis();
                strcpy(name, x);
                if(IsKeyPressed(KEY_ENTER)){
                    clr();
                    input=2;
                        }
                break;
        case 2: if (((framesCounter/20)%2) == 0) DrawRectangleLines(textBox2.x, textBox2.y, textBox2.width, textBox2.height, RED);
                tulis();
                strcpy(put, x);                    
                if(IsKeyPressed(KEY_ENTER)){
                    clr();
                    input=3;
                        }
                break;
        case 3: if (((framesCounter/20)%2) == 0)DrawRectangleLines(textBox3.x, textBox3.y, textBox3.width, textBox3.height, RED);
                tulis();
                strcpy(year, x);                    
                if(IsKeyPressed(KEY_ENTER)){
                    clr();
                    input=0;
                    insert();
                    m++;
                    }
                break;                    
        }
        
 }

void tulis(){
        key = GetKeyPressed();
        int min=32,max=125;
        if(input==3) {min=48; max=57;}
        if ((key >= min) && (key <= max)&&(letterCount < MAX))
            {
               //panggil fungsi
                x[letterCount] = (char)key;
                letterCount++;
            }
        if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                x[letterCount] = '\0';       
                if (letterCount < 0) letterCount = 0;
            }
}

void third(){
    DrawText("Hapus Buku", 20, 20, 50, BLACK);
    DrawText("Masukkan Judul Buku yang ingin dihapus: ", 20, 100, 40, DARKBLUE);
    
    DrawRectangleRec(textBox4, LIGHTGRAY);
    DrawText(hapus, textBox4.x + 5, textBox4.y + 8, 20, MAROON);    
    DrawText(hasil, 20, 400, 40, DARKBLUE);
    framesCounter++;
    if (((framesCounter/20)%2) == 0) DrawRectangleLines(textBox4.x, textBox4.y, textBox4.width, textBox4.height, RED);
    tulis();
    if(input==0){
        clr();
        input++;
    }
    strcpy(hapus, x);
    if(IsKeyPressed(KEY_ENTER)){
        clr();
        del();
        }
    if(succes==1){
        strcpy(hasil,s1);
    }
    else if(succes==0){
        strcpy(hasil,s0);
    }
    else{
        strcpy(hasil,kosong);
    }
}
 
void fourth(){
    view();
}

void insert() {
    if(strcmp(name, "\0")==0) strcpy(name, "???");
    data *link = (data*) malloc(sizeof(data));
    strcpy(link->judul, name);    
    strcpy(link->penulis, put);
    strcpy(link->tahun, year);
    link->next = head;
    head = link;
    
    j++;
    if(j>2){j=0;}

    while(letterCount>=0){
        name[letterCount] = '\0';       
        letterCount--;
    }
    if (letterCount < 0) letterCount = 0;
    while(letterCount>=0){
        put[letterCount] = '\0';       
        letterCount--;
    }
    if (letterCount < 0) letterCount = 0;
    while(letterCount>=0){
        year[letterCount] = '\0';       
        letterCount--;
    }
    if (letterCount < 0) letterCount = 0;    
}

void del() {
  	data *current=head,*temp=NULL;
    if (current != NULL && strcmp(current->judul,hapus)==0) 
    { 
        head = current->next;    
        free(current);               
        succes=1;
        return; 
    }
    while (current != NULL && strcmp(current->judul,hapus)!=0) 
    { 
        temp = current;
        current = current->next;
        succes=1;
        } 
    if (current == NULL) {
        succes=0;
        return; 
    }
    temp->next = current->next; 
}

void ftxt(){
	data *current = head;
	int i=1;
	FILE *fp;
	fp = fopen("resources/Database.txt", "w");
/*	if(fp==NULL){
		return;
	}*/
	while(current!=NULL) {
        if(i!=1) fprintf(fp, "\n");
		fprintf(fp,"%s\n%s\n%s", current->judul, current->penulis, current->tahun);
		current = current->next;
		i++;
	}	
    i=1;
	fclose(fp);
}

void rtxt(){
    FILE* fp;

    fp = fopen("resources/Database.txt", "r");
    int r=1;
    while(fgets(x, MAX+1, fp)) {
        strtok(x, "\n");
        if(r==1) {
            strcpy(name, x);
        }
        else if(r==2) {
            strcpy(put, x);
        }
        else if(r==3) {
            strcpy(year, x);
            insert();
        }
        r++;
        if(r>3) r=1;
    }
    sort();
    fclose(fp);
}

void view() {
	data *current = head;
    int i=0;
    DrawText("No.   Judul Buku                                               Penulis                              Tahun", 50, 100+(20*i), 20, RAYWHITE);
    while(current!=NULL) {
        DrawText(FormatText("\t%d", i+1), 50, 150+(20*i), 20, RAYWHITE);
        DrawText(current->judul, 110, 150+(20*i), 20, RAYWHITE);
        DrawText(current->penulis, 600, 150+(20*i), 20, RAYWHITE);
        DrawText(current->tahun, 915, 150+(20*i), 20, RAYWHITE);
        
        current = current->next;
        i++;
    }
    if(IsKeyPressed(KEY_ENTER)) ftxt();
}

void sort(){
    data *ptr1;
	data *lptr = NULL;
	data *current = head;
	int swapped;
    char tmp[20];
    if(current==NULL) return;
    do
    { 
        swapped = 0; 
        ptr1 = current; 
  
        while (ptr1->next != lptr) 
        { 
            if (strcmp(ptr1->judul, ptr1->next->judul)>0) 
            {	
				strcpy(tmp, ptr1->judul);
				strcpy(ptr1->judul, ptr1->next->judul);
				strcpy(ptr1->next->judul, tmp);
                
                strcpy(tmp, ptr1->penulis);
				strcpy(ptr1->penulis, ptr1->next->penulis);
				strcpy(ptr1->next->penulis, tmp);
                
                strcpy(tmp, ptr1->tahun);
				strcpy(ptr1->tahun, ptr1->next->tahun);
				strcpy(ptr1->next->tahun, tmp);
                swapped = 1;
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
}

void first(){
    DrawText("Daftar Buku telah diurutkan. Tekan F5 untuk kembali ke menu utama.", 30, 30, 20, ORANGE);
    DrawText("Daftar Buku diurutkan berdasarkan judul buku (Ascending).", 30, 60, 20, ORANGE);
    if(l==0){
        sort();
        l++;
    }
}