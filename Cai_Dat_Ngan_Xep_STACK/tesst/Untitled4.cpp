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

void Process(Stack &S){
	int n,b;
	printf("\nMoi ban nhap gia tri cua n= "); scanf("%d",&n);
	printf("\nBan muon chuyen ve co so b= "); scanf("%d",&b);
	while(n!=0){
		Push(S,n%b);
		n=n/b;
	}
	for(NODE *p=S.pHead;p!=NULL;p=p->Next){
		printf("%4d",Pop(S));
	}
}
int main(){
	Stack S;
	Init(S);
	Process(S);
	getch();
	return 0;
}
