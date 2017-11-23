#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{
	char Name[30];
	struct student *Next;
}StudentNode;

typedef struct classnode{
	char Name[30];
	struct classnode *Next;
	StudentNode *Student;
}ClassNode;

typedef struct List{
	ClassNode *pHead;
	ClassNode *pTail;
}LIST;

void Init(LIST &L){
	L.pHead=L.pTail=NULL;
}

ClassNode *CreateNode(char x[30]){
	ClassNode *p;
	p=(ClassNode*)malloc(sizeof(ClassNode));
	strcpy(p->Name,x);
	p->Next=NULL;
	p->Student=NULL;
	return p;
}

void Insert_Class_Last(LIST &L,ClassNode *p){
	if(L.pHead==NULL)
		L.pHead=L.pTail=p;
	else {
		L.pTail->Next=p;
		L.pTail=p;
	}
}
ClassNode *Insert_Student_Head(ClassNode *classnode,char name[30])
{
	StudentNode *temp;
	temp = (StudentNode *)malloc(sizeof(StudentNode));
	strcpy(temp->Name,name);
	if(classnode->Student==NULL)
		classnode->Student=temp;
	else{
		classnode->Student->Next=temp;
		temp=classnode->Student;
	}
	return classnode;
}
void InPut(LIST &L){
	int n,k=0,m;
	char x[30],ten[30];
	ClassNode *p=L.pHead;
	printf("Moi ban nhap vao so lop: n= "); scanf("%d",&n);
	do{
		
		k++;
		printf("\nTen lop thu %d la: ",k); fflush(stdin); gets(x);
		ClassNode *lop;
		lop=CreateNode(x);
		Insert_Class_Last(L,lop);
		
		printf("\nMoi ban nhap so hoc sinh: "); scanf("%d",&m);
		for(int i=1;i<=m;i++){
			printf("\nTen hoc sinh thu %d la: ",i); fflush(stdin); gets(ten);
			Insert_Student_Head(lop,ten);
		}
	}while(k!=n);
	
}

void Show_Student(ClassNode *classnode)
{
	StudentNode *temp;
	temp = classnode->Student;
	while(temp!=NULL){
		printf("\n 					ten hoc sinh la %s ",temp->Name);
		temp = temp->Next;
	}
}
void Show_Class(LIST L)
{
	ClassNode *temp;
	temp = L.pHead;
	while(temp!=NULL){
		printf("\n lop ten la %s",temp->Name);
		Show_Student(temp);
		temp = temp->Next;
	}
}
int main()
{	
	LIST L;
	Init(L);
	InPut(L);
	Show_Class(L);
}

