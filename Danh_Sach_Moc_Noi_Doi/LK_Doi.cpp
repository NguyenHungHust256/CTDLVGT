#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef int item;

typedef struct Node{
	item Data;
	Node *Left;
	Node *Right;
};

struct Dlist{
	Node *Head;
	Node *Tail;
};

//Khoi tao va kiem tra Rong

void Init(Dlist L){
	L.Head=NULL;
	L.Tail=NULL;
}

int Isempty(Dlist L)
{
	return (L.Head==NULL);
}

//Do dai danh sach
int Len(Dlist L){
	Node *PH=L.Head, *PT=L.Tail;
	int i=0;//bien dem
	if(PH!=NULL) i=1;
	while(PH!=NULL){
		if(PH==PT) break;
		PH=PH->Right;
		i++;
		if(PH==PT) break;
		PT=PT->Left;
		i++;
	}
	return i;
}

Node *Make_Node(item x)  //Tao 1 Node chua thong tin la x;
{
	Node *P=(Node *)malloc(sizeof(Node));
	P->Data=x;
	P->Left=NULL;
	P->Right=NULL;
	return P;
}

//Chen phan tu vao vi tri dau tien
void Insert_first(Dlist L, item x) 	// chen x vao vi tri dau tien trong danh sach
{
	Node *P;
	P=Make_Node(x);
	if(Isempty(L))
	{
		L.Head=P;
		L.Tail=P;
	}
	else
	{
		P->Right=L.Head;
		L.Head->Left=P;
		L.Head=P;
	}
}

//Chen phan tu vao cuoi danh sach tuong tu nhu dau danh sach
void Insert_last(Dlist L, item x)
{
	Node *P;
	P=Make_Node(x);
	if(Isempty(L))
	{
		L.Head=P;
		L.Tail=P;
	}
	else
	{
		L.Tail->Right=P;
		P->Left=L.Tail;
		L.Tail=P;
	}
}

//Chen phan tu vao vi tri k
void Insert_k(Dlist L, item x, int k)
{
	Node *PH=L.Head, *PT, *R;
	int i=1, l=Len(L);
	if(k<1||k>l+1)	printf("Vi tri chen khong hop le!");
	else 
	{
		R=Make_Node(x); //tao 1 Node P
		if(k==1) Insert_first(L,x); //chen vao vi tri dau tien
		else 
		{
			if(k==l+1)	Insert_last(L,x);
			else
			{
				while(PH!=NULL&&i!=k-1)
				{
					i++;
					PH=PH->Right;
				}
				PT=PH->Right;
				R->Right=PT;
				R->Left=PH;
				PH->Right=R;
				PT->Left=R;
			}
		}
	}
}
// Xoa phan tu dau cuoi danh sach
//Lay gia tri can xoa ra , sau do bo qua 1 Node dau tien
void Del_first(Dlist L, item x)
{
	if(!Isempty(L))
	{
		x=L.Head->Data;
		L.Head=L.Head->Right;	
	}
}

//Lay gia tri can xoa ra,sau do bo 1 node cuoi
void Del_last(Dlist L, item x)
{
	if(!Isempty(L)){
		x=L.Tail->Data;
		L.Tail=L.Tail->Left;
		L.Tail->Right=NULL;
	}
}
void Del_k(Dlist L, item x, int k)
{
	Node *PH=L.Head;
	Node *PT;
	int i=1, l=Len(L);
	if(k<1||k>l) printf("Vi tri xoa khong hop le!");
	else 
	{
		if(k==1) Del_first(L,x);
		else
			if(k==l) Del_last(L,x);
			else // xoa vi tri 1<k<k+1
			{
				while(PH!=NULL&& i!=k-1)
				{
					i++;
					PH=PH->Right;
				}
				x=PH->Right->Data;
				PT=PH->Right->Right;
				PH->Right=PT;
				PT->Left=PH;
			}
	}
}
//Tim phan tu x trong danh sach
int Search(Dlist L, item x)
{
	Node *P=L.Head;
	int i=1;
	while(P!=NULL &&P->Data!=x){
		P=P->Right;
		i++;
	}
	if(P!=NULL) return i; // tra ve vi tri tim thay
	else return 0; // Khong tim thay
}

// Xoa phan tu x trong danh sach
void Del_x(Dlist L, item x)
{
	int l=Search(L,x);
	while(1)
	{
		Del_k(L,x,l);
		l= Search(L,x);
	}
}
int main(){
	
}
