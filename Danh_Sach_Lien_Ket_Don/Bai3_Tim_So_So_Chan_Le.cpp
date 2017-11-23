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
	for(NODE *p=L.pHead;p!=NULL;p=p->Next)
	{
		printf("%4d",p->data);
	}
}

void Ham_Xu_Ly(LIST L)
{
	int a=0,b=0;
	for(NODE *p=L.pHead;p!=NULL;p=p->Next){
		if(p->data%2 == 0) a=a+1;
		else b++;
	}
	printf("\nCac so chan la: %d",a);
	printf("\nCac so le la: %d ", b);
}
int main(){
	LIST L;
	Init(L);
	InPut(L);
	OutPut(L);
	Ham_Xu_Ly(L);
}
