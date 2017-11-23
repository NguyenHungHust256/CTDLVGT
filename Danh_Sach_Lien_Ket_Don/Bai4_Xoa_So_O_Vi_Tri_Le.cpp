#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct Node{
	int Data;
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
	p->Data=x;
	p->Next=NULL;
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

void Delete_First(LIST &L){
	NODE *p;
	p=L.pHead;
	L.pHead=L.pHead->Next;
	free(p);
}
void Delete(LIST &L,NODE *p)
{ 
	NODE *q;
	q=L.pHead;
	while(q->Next!=p){
		q=q->Next;
	}
	q->Next=q->Next->Next;
	free(p);
}
void InPut(LIST &L){
	int x,n;
	Init(L);
	printf("So phan tu ban muon nhap vao la: "); scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("So thu %d la: ",i+1); scanf("%d",&x);
		NODE *p=Create_Node(x);
		Insert_Last(L,p);
	}
}

void OutPut(List L){
	for(NODE *p=L.pHead;p!=NULL;p=p->Next){
		printf("%4d",p->Data);
	}
}

void Process(LIST &L){
	NODE *p;
	int i=1;
	for(NODE *p=L.pHead;p!=NULL;p=p->Next)
	{
		i=i+1;
		if(i%2 != 0) Delete(L,p);
	}
}

int main(){
	LIST L;
	InPut(L);
	OutPut(L);
	printf("\nSau khi xoa: \n");
	Delete_First(L);
	Process(L);
	OutPut(L);
	getch();
	return 0;
}
