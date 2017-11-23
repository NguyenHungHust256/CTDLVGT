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
}Stack;

Stack Init(Stack S){
	S.pHead=S.pTail=NULL;
}

NODE *Create_Node(int x){
	NODE *p;
	p=(NODE*)malloc(sizeof(NODE));
	if(p==NULL) return NULL;
	p->Data=x;
	p->Next=NULL;
	return p;
}

int Is_Empty(Stack S){
	return(S.pHead==NULL);
}

void Push(Stack &S, int x){
	NODE *p=Create_Node(x);
	if(S.pHead==NULL){
		S.pHead=S.pTail=p;
	}
	else{
		p->Next=S.pHead;
		S.pHead=p;
	}

}

int Pop(Stack &S){
	int x;
	NODE *p;
	if(!Is_Empty(S)){
		p=S.pHead;
		x= p->Data;
		S.pHead=p->Next;
		return x;
		free(p);
	}
}

void Nhap(Stack &S){
	int n;
	printf("Moi ban nhap gia tri cua n= "); scanf("%d",&n);
	for(int i=1;i<=n;i++){
		Push(S,i);
	}
}

void Xuat(Stack S){
	for(NODE *p=S.pHead;p!=NULL;p=p->Next){
		printf("%4d",p->Data);
	}
}
int main(){
	Stack S;
	Init(S);
	Nhap(S);
	Xuat(S);
	getch();
	return 0;
}
