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
void Remove_After(LIST &L,NODE *p){
	NODE *q;
	q=p->Next;
	p->Next=p->Next->Next;
	free(q);
}

void Remove_repeat(LIST &L){
	NODE *p=L.pHead;
	
	while(p!=NULL){
		NODE *q=p->Next;
		NODE *t=p;
		while(q!=NULL){
			if(p->data==q->data){
				Remove_After(L,t);
				q=t->Next;
			}
		else{
			t=q;
			q=q->Next;
		}
	}
	  p=p->Next;
	
	}	
}
void OutPut(LIST L){
	for(NODE *p=L.pHead;p!=NULL;p=p->Next)
	{
		printf("%4d",p->data);
	}
}


int main(){
	LIST L;
	Init(L);
	InPut(L);
	printf("LIST ban dau la: \t\t\t");
	OutPut(L);
	Remove_repeat(L);
	printf("\nSau khi xoa bo cac phan tu ta co: \t");
	OutPut(L);
}
