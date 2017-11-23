#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *Next;
}NODE;

typedef struct List{
	NODE *pHead;
	NODE *pTail;
}LIST;

void Init(LIST &L){
	L.pHead=L.pTail=NULL;
}

NODE *Create_Node(int x){
	NODE *p;
	p=(NODE*)malloc(sizeof(NODE));
	if(p==NULL)
		return NULL;
	else{
		p->data=x;
		p->Next=NULL;
	}
}

void Insert_Last(LIST &L, NODE *p){
	if(L.pHead==NULL)
		L.pHead=L.pTail=p;
	else{
		L.pTail->Next=p;
		L.pTail=p;
	}
	L.pTail->Next=L.pHead;
}

void InPut(LIST &L){
	int i,n,x;
	printf("so so nguyen ban muon nhap vao la : n= ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("\nNhap so: "); scanf("%d",&x);
		NODE *p = Create_Node(x);
		Insert_Last(L,p);
	}
}

void OutPut(LIST L){
	NODE *p=L.pHead;
	do{
		printf("%4d",p->data);
		p=p->Next;
	}while(p!=L.pHead);
}

NODE * Search(LIST L, int k){
	NODE *p;
	p=L.pHead;
	while(p->data!=k){
		p=p->Next;
	}
	return p;
}

void Process(LIST L){
	int k;
	printf("\nBan muon tro den gia tri nao de dem: k= "); scanf("%d",&k);
	int a=0;
	NODE *p=Search(L,k);
	do{
		a=a+1;
		p=p->Next;
	}while(p!=Search(L,k));
	printf("\nSo phan tu trong danh sach: %d ",a); 
}

int main(){
	LIST L;
	Init(L);
	InPut(L);
	OutPut(L);
	Process(L);
	getch();
}
