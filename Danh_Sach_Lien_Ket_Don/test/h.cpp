#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentnode{
	char Name[30];
	struct studentnode *Next;
}StudentNode;

typedef struct classnode{
	char name[30];
	struct classnode *Next;
	StudentNode *student;
}ClassNode;


typedef struct cList{
	ClassNode *pcHead;
	ClassNode *pcTail;
}CLIST;
typedef struct sList{
	StudentNode *psHead;
	StudentNode *psTail;
}SLIST;

typedef struct List{
	CLIST cList;
	SLIST sList;
}LIST;

void Init(LIST &L){
	L.cList.pcHead=L.cList.pcTail=NULL;
	L.sList.psHead= L.sList.psTail=NULL;
	
}

ClassNode *Create_Node(char x[30],char y[30]){
	ClassNode *p;
	p=(ClassNode*)malloc(sizeof(ClassNode));
	strcpy(p->name,x);//p->name=x;
	p->Next=NULL;
	strcpy(p->student->Name,y);//p->student->Name=y;
	p->student->Next=NULL;
	return p;
}

void Insert_Last(LIST &L, ClassNode *p){
	if(L.cList.pcHead==NULL)
	{
		L.cList.pcHead=L.cList.pcTail=p;
		if(L.sList.psHead==NULL){
			L.sList.psHead=L.sList.psTail=p->student;
		}
	}
	else{
		L.cList.pcTail->Next=p;
		L.cList.pcTail=p;
		L.sList.psTail->Next=p->student;
		L.sList.psTail=p->student;
	}
}

void InPut(LIST &L){
	int n,k=0,m;
	char x[30],h[30];
	ClassNode*p=L.cList.pcHead;
	printf("Moi ban nhap so lop : n = "); scanf("%d",&n);
	while(k!=n)
	{
		k++;
		printf("\nTen lop thu %d la: ",k); fflush(stdin); gets(h);
		printf("\nMoi ban nhap so hoc sinh cua lop %d: m= ",k); scanf("%d",&m);
		for(int i=1;i<=m;i++){
			printf("Ten cua hoc sinh thu %d la :  ",i); fflush(stdin); gets(x);
			ClassNode *p;
			p=Create_Node(h,x);
			Insert_Last(L,p);
		}
		p=p->Next;
	}
}

void OutPut(LIST L){
	for(ClassNode *p=L.cList.pcHead;p!=NULL;p=p->Next){
		printf("%s",p->name);
	}
}
int main(){
	LIST L;
	Init(L);
	InPut(L);
	OutPut(L);
}
