#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentnode{
	char Name[30];
	struct studentnode *Next;
}NODE;

typedef struct List{
	NODE *pHead;
	NODE *pTail;
}LIST;

void Init(LIST &L){
	L.pHead=L.pTail=NULL;
}

NODE *Create_Node(char *x){
	NODE *p;
	p=(NODE*)malloc(sizeof(NODE));
	if(p==NULL)
		return NULL;
	strcpy(p->Name,x);
	p->Next = NULL;
	return p;
}

void Insert_Last(LIST &L, NODE *p){
	if(L.pHead==NULL)
		L.pHead=L.pTail=p;
	else{
		L.pTail->Next=p;
		L.pTail=p;
	}
}

void InPut(LIST &L){
	int n;
	char x[30];
	printf("Moi ban nhap so hoc sinh n= "); scanf("%d",&n);
	for(int i=1;i<=n;i++){
		printf("\nTen cua hoc sinh thu %i : ",i); fflush(stdin) ;gets(x);
		NODE *p=Create_Node(x);
		Insert_Last(L,p);
	}
}

void OutPut(LIST L){
	printf("\nDanh sach hoc sinh cua lop da cho la: \n");
	for(NODE *p=L.pHead;p!=NULL;p=p->Next)
	{
		printf("%s\n",p->Name);
	}
}

int main(){
	LIST L;
	Init(L);
	InPut(L);
	OutPut(L);
	getch();
}
