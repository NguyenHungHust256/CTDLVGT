#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *pNext;
}NODE;

typedef struct List
{
	NODE *pHead;
	NODE *pTail;
}LIST;

void Init(LIST L)
{
	L.pHead = L.pTail=NULL;
}

NODE *Create_Node(int x){
	NODE *p;
	p=(NODE*)malloc(sizeof(NODE));
	if(p==NULL)
	{
		return NULL;
	}
	p->data=x;   
	p->pNext=NULL;
	return p;
}
void Add_Head(LIST L, NODE *p){
	if(L.pHead==NULL)
	{
		L.pHead=L.pTail=p;
	}
	else
	{
		p->pNext=L.pHead;
		L.pHead=p;
	}
}

void Add_Tail(LIST &L, Node *p){
	if(L.pHead==NULL)
	{
		L.pHead=L.pTail=p;
	}
	else
	{
		L.pTail->pNext=p;
		L.pTail=p;
	}
}

void InPut(LIST &L)
{
	int n;
	Init(L);
	printf("\n Ban muon nhap bao nhieu so nguyen: ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		printf("\nNhap so: ");
		scanf("%d",&x);
		
		NODE *p = Create_Node(x);
		Add_Tail(L,p);
	}
}
void OutPut(LIST L){
	for(NODE *p=L.pHead;p!=NULL;p=p->pNext)
	{
		printf("%4d",p->data);
	}
}

void Xu_Ly(LIST L){
	printf("\n So le la: \n\t\t");
	for(NODE *p=L.pHead;p!=NULL;p=p->pNext){
		if(p->data %2!=0){
			printf("%5d",p->data);
		}
	}
}
int main(){
	
	LIST L1;
	LIST L2;
	
	InPut(L1);
	OutPut(L1);
	
	InPut(L2);
	OutPut(L2);
	
	Xu_Ly(L1);
	
	Xu_Ly(L2);
	getch();
	return 0;
}
