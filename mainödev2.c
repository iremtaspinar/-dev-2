#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *dosya; 

struct node{
int no; 
char ad[20]; 
char soyad[20]; 
int final; 
int vize; 

struct node *back; 
struct node *next; 
};

typedef struct node veriler;

int cnt=0;

void verileriDosyayaYaz(veriler *root){

   dosya =fopen("ogrenciOtomasyon.txt", "w"); 
   if(dosya==NULL){
	   printf("DOSYA YOK\n"); 
	   exit(0);
	}
for(veriler *p=root;p!=NULL;p=p->next) {
	fprintf(dosya,"\nAdi:%s\nSoyadi:%s\nNumarasi:%d\nVize Notu:%d\nFinal Notu:%d\n",p->ad,p->soyad,p->no,p->vize,p->final);   
	}
}

veriler *verileriListele(veriler *root) {
	system("cls"); 
	if(root==NULL){
    	printf("Liste Bos,Ogrenci Yok \n"); 
	}
	else{
	veriler*p=root;
		while(p!=NULL){
		printf("%d Numarali Ogrencinin Adi: %s Soyadi: %s Vize Notu: %d Final Notu: %d \n", p->no, p->ad, p->soyad, p->vize, p->final);
		p= p->next;
		}

	}
	return 0;
}
veriler *ogrenciEkle (veriler *root){ 
system("cls"); 

veriler *node= (veriler *) malloc(sizeof(veriler));
printf("verileri girin\n"); 
printf("ogrencinin adi\n:");
scanf("%s",node->ad);
printf("soyadi\n:");
scanf("%s",node->soyad);
printf("ogrenci numarasi\n:");
scanf("%d",&node->no);
printf("ogrenci vize notu:\n");
scanf("%d",&node->vize);
printf("final notu:\n");
scanf("%d",&node->final);

	if (root==NULL) {
	root=node;
	root->next= NULL; 
	root->back= NULL; 
	cnt++;
	printf("%d Numarali Ilk Ogrenci Eklendi \n", node->no);  
	}
	else {	
	node->next=root;
	root->back=node;
	root=node;
	root->back=NULL;
	printf("kayit edildi");
	}
return root;
}
void Okuma(struct node *i)
{
 	printf("\tAdi%s\n",i->ad);
}

int main() 
{
veriler *root=NULL;

int secim; 

while(1) 
{
printf("\t\tIslem Yapmak Istediginiz Numarayi Seciniz\n"); 
printf("\t\t1--> ekle\n"); 
printf("\t\t2--> listele\n"); 
printf("\t\t3--> sil\n"); 
printf("\t\t4--> dosyadan okuma modu\n"); 
printf("\t\t0--> cikis\n"); 

scanf("%d", &secim); 
switch(secim){
	case 1:
		root=ogrenciEkle(root);
		verileriDosyayaYaz(root);
	break;
	
	case 2:
		root=verileriListele(root);
	break;
			
	case 3:
				
	break;
			
	case 4:
		dosya=fopen("ogrenciOtomasyon.txt","r");
		if(dosya==NULL){
			printf("dosya yok !");
			exit (0);
		}
				
		printf("Ogrenci listesi \n");
		while(!feof(dosya)){
			fread(&root,sizeof(struct node),1,dosya);
			Okuma(&root);
		}
	
		fclose(dosya);
		break;
		case 0:
			exit(0);
		break;
			default:
			("hatali secim yaptiniz! \n");
		}
	}
    return 0;
}