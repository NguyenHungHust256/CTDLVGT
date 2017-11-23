/* 
Xet cau truc du lieu mo ta danh sach noi don
 struct Node{
 			int Inf;
 			struct Node *Next;
 		  }
 	typedef struct Node LIST;
 	Hay viet chuong trinh con tren C:
 	LIST *OddList(LIST *linp);
 	nhan dau vao la danh sach thu duoc tu danh sach dau vao boi viec '
	loai bo cac phan tu voi truong inf la so chan
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct TypeNode{
	int data;
	struct TypeNode *Next;
}NODE;

typedef struct List{
	NODE *pHead;
}LIST;

void Init(LIST L){
	L.pHead =NULL;
}

NODE *Create_Node(int x){
	NODE *p;
	p=(NODE*)malloc(sizeof(NODE));
	if(p==NULL)
		return NULL;
	p->data=x;
	p->Next = NULL;
	return p;
}

NODE *Insert_Last(LIST &L,NODE *p){
	NODE *K;
	K=(NODE*)malloc(sizeof(NODE));
	K=L.pHead;
	if(L.pHead==NULL)
	{
		L.pHead = p;
	}
	else 
	{
		while((K->Next)!=NULL)
		{
			K=K->Next;
		}
		K->Next=p;
		p->Next=NULL;
	}
}

void InPut(LIST &L)
{
	int n;
	int x;
	Init(L);
	printf("\n Ban muon nhap bao nhieu so nguyen: ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		
		printf("\nNhap so: ");
		scanf("%d",&x);
		
		NODE *p = Create_Node(x);
		Insert_Last(L,p);
	}
}

void OutPut(LIST L){
	for(NODE *p=L.pHead;p!=NULL;p=p->Next)
		printf("%4d",p->data);
	printf("\n");
}
void Xu_Ly(LIST L){
	printf("So chan la : \n");
	for(NODE *p=L.pHead;p!=NULL;p=p->Next)
	{
		if(p->data %2==0)
			printf("%4d",p->data);
	}
}
int main(){
	LIST L;
	InPut(L);
	OutPut(L);
	Xu_Ly(L);
	getch();
	return 0;
}
