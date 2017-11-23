#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef int item;
struct Node
{
	item Data;
	Node *Next;
};

struct Queue
{
	struct Node *Front, *Rear;
	int count;
};

struct Queue Q;
//Khoi tao
void Init(){
	Q.Front=Q.Rear=NULL;

	Q.count=0;
}
// Kiem tra rong
int IsEmpty(){
	return (Q.count == 0);
}

Node *MakeNode(item x)
{
	Node *P=(Node*)malloc(sizeof(Node));
	P->Next=NULL;
	P->Data=x;
	return P;
}

//Them phan tu vao cuoi Queue
void Push(item x) //them phan tu vao cuoi Queue
{
    Node *P = MakeNode(x); //Neu Q rong
    if (IsEmpty())
    {
        Q.Front = Q.Rear = P; //dau va cuoi deu tro den P
    }
    else //Khong rong
    { 
        Q.Rear->Next = P;
        Q.Rear = P;
    }
    Q.count ++ ; //tang so phan tu len
}
item Pop(){
	item x;
	
	if(IsEmpty())
		printf("Hang doi dang rong!");
	else {
		x=Q.Front->Data;
		Q.Front=Q.Front->Next;
		Q.count--;
	}
	return x;
}
int main(){
	
}

