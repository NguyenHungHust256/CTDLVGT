#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef int item;
typedef struct Node
{
	item Data;
	Node *Next;
}Node;

typedef struct stack
{
	Node *Top;
} Stack;

// Khoi tao danh sach rong , kiem tra danh sach rong, do dai danh sach

Stack *Init(Stack *S)
{	
	S->Top = NULL;
	return S;
}

//Kiem tra danh sach co rong hay khong
int Isempty(Stack *S)
{
	return(S->Top == NULL);
}

//Thong bao stack full
int Full(){
	printf("\n NO MEMORY! Stack is full");
	getch();
	return 1;
}

//Kiem tra chieu dai cua Stack
int Len(Stack *S)
{
	int i=0;
	Node *P=S->Top;
	while(P->Next!=NULL)
	{
		i++;
		P=P->Next;
	}
	return i;
}

//Chen phan tu vao stack(PUSH)
int Push(Stack *S, item x)
{
	Node *P;
	P=(Node*)malloc(sizeof(Node));
	if(P==NULL) return NULL;
	if(S->Top==NULL){
		S->Top=P;
	}
	else{
		P->Next=S->Top;
		S->Top=P;
	}
	return x;
}

// Lay du lieu tai TOp nhung khong xoa
int Peak(Stack *S)
{
	return S->Top->Data;
}

//Xoa va lay du lieu tai Top (Pop)
int Pop(Stack *&S)
{ 
	Node *node;
	item x;
	if(Isempty(S)){
		return NULL;
	}
	else {
		node=S->Top;
		x = node->Data;
		S->Top=node->Next;
		free(node);
		return x;
	}
}

//Ham hien thi cac phan tu trong Stack
void display(Stack *S){
	Node* node;
	int m;
	printf("\n\n Danh sach cac phan tu cua Stack \n\n");
	if(Isempty(S)){
		printf("\n\n >>>>>>>  Empty Stack   <<<<<<<\n\n");
		getch();
	}
	else{
		node =S->Top;
		do{
			m=node->Data; 
			printf("%8d",m);
			node=node->Next;
		}while(!(node==NULL));
		printf("\n");
	}
}

//Huy ngan xep
void Destroy(Stack *S){
	while(!Isempty(S)){
		Pop(S);
	}
	free(S);
}

void Process(Stack *S){
	int n,b;
	printf("Moi ban nhap so he thap phan n= "); scanf("%d",&n);
	printf("\nBan muon doi sang co so b= "); scanf("%d",&n);
	while(n/b!=0){
		int a=n%b;
		Push(S,a);
		n=n/b;
	}
//	printf("\n\n>>>>>>   Ket qua   <<<<<<<\n\n");
//	while(!Isempty(S)){
//		printf("%d",Pop(S));
//	}
}
int main(){
	Stack *S;
	Init(S);
//	Process(S);
	Push(S,1);
	Push(S,2);
	Push(S,3);
	return 0;
}

