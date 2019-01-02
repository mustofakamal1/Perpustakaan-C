#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node {
	char title[20];
	char author[20];
	char id[10];
	char tahun[4];
	struct node *next;
} data;
void insert();
void view();
void del();
void swap(data *a, data *b);
void sort();
void txt();

data *head=NULL, *tail=NULL;

void main() 
{
	char pilih;
		
	do {
		printf("\n  Program Perpustakaan\n");
		printf(" _______________________\n\n\n\n");
		printf("--------------------------");
		printf("\n|	   MENU          |\n");
		printf("--------------------------\n");
		printf("|  1. Insert             |\n");
		printf("|  2. View               |\n");
		printf("|  3. Sort               |\n");
		printf("|  4. Delete             |\n");
		printf("|  5. Print to File      |\n");
		printf("|  6. Exit               |\n");
		printf("--------------------------");
		printf("\nPILIH: ");
		scanf("%s",&pilih);
		switch(pilih){
		case '1': 
			insert();
			break;
		case '2':
			view();
			break;
		case '3':
			sort();
			break;
		case '4':
			del();
			break;	
		case '5':
			txt();
			break;
		case '6':
			break;
		default:
			printf("\nInput Salah. Pilih lagi.\n");
		}
	
	}while(pilih!='6');
}

void insert() 
{
	system("cls");
	char title[20];
	char author[20];
	char id[10];
	char tahun[4];
	int letter;
	
	letter=getchar();
	 // To consume a newline char left
	printf("%c",letter);
	printf("\n  Inserting Data\n __________________\n\nTitle\t: ");
	gets(title);
	//scanf("%s", &title);
	printf("Author\t: ");
	gets(author);
	printf("ID\t: ");
	gets(id);
	printf("Tahun\t: ");
	gets(tahun);
	data *link = (data*) malloc(sizeof(data));
	strcpy(link->title,title);
	strcpy(link->author,author);
	strcpy(link->id,id);
	strcpy(link->tahun,tahun);
	link->next = head;
	head = link;
	printf("\n");
	printf("\n\n Data Telah Di Simpan\n");
	printf("\n");
	system("pause");
	system("cls");
}

void view() 
{
	system("cls");
	printf("\nData List (Terbaru ke Lama / Stack)\n");
	data *current = head;
	printf("\nNo.\tTitle\t\t\tAuthor\t\tID\tTahun\n");
	int i=1;
	while(current!=NULL) {
		printf("\n%d\t%s\t\t\t%s\t\t%s\t%s\n", i, current->title, current->author, current->id, current->tahun);
		current = current->next;
		i++;
	}	
	printf("\n");
	system("pause");
	printf("\n");
}

void txt(){
	data *current = head;
	int i=1;
	FILE *fptr;
	fptr = fopen("perpus.txt", "w");
	if(fptr==NULL){
		printf("\n\nFile does not exist\n");
		return;
	}
	while(current!=NULL) {
		fprintf(fptr,"\t%s\t\t\t%s\t\t%s\t%s\n", current->title, current->author, current->id, current->tahun);
		current = current->next;
		i++;
	}	
	fclose(fptr);
}

/*void search() 
{ 
	system("cls");
	int i=1;
	char cari[20];
	printf("Masukan nama yang ingin dicari: ");
	scanf("%s",&cari);
    data *current = head;
    while (current != NULL) 
    { 
    //	strcmp(current->nama,cari)
        if (strcmp(current->title,cari)==0) {
        	printf("\nNama %s ditemukan pada data ke-%d\n",current->title,i); 
        	break;
			}
		current = current->next; 
        i++;
    }
    if(current==NULL){
	printf("\nData Tidak Ditemukan.\n"); 
	}
	printf("\n");
	system("pause");
	printf("\n");
} 
//menghapus sesuai dengan nama yang ingin dihapus
*/
void sort() { 
	data *ptr1;
	data *lptr = NULL;
	data *current = head;
	int swapped, i;
    char temp[20];
    do
    { 
        swapped = 0; 
        ptr1 = current; 
  
        while (ptr1->next != lptr) 
        { 
            if (strcmp(ptr1->title, ptr1->next->title)>0) 
            {	
				strcpy(temp, ptr1->title);
				strcpy(ptr1->title, ptr1->next->title);
				strcpy(ptr1->next->title, temp);
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 

void swap(data *a, data *b) 
{ 
	char temp[20];
	strcpy(temp, a->title);
	strcpy(a->title, b->title);
	strcpy(b->title, temp);
} 

void del() {
	system("cls");
	char hapus[20];
	printf("\n\nMasukan nama yang ingin dihapus: ");
	scanf("%s",&hapus);

  	data *current=head,*temp;

	while (current != NULL && strcmp(current->title,hapus)!=0) 
    { 
        temp = current;
        current = current->next;
    } 
    
    if (current != NULL && strcmp(current->title,hapus)==0) 
    { 
        head = current->next;    
        free(current);
		printf("\nData Ditemukan. Hapus Berhasil.");
		printf("\n");
		printf("\n"); 
		system("pause");
		          
        return;
        
    } 
    
 
   
    if (current == NULL){
		printf("\nData Tidak Ditemukan. Hapus Gagal.");
		printf("\n");
		printf("\n");
		system("pause");
		return; 
  	}
	temp->next = current->next; 
}
