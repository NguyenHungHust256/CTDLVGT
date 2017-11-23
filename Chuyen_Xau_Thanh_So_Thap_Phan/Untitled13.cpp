#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdlib.h>

typedef char item;
struct Node {
	item Data;
	Node *Next;
};

struct Queue{
	struct Node *Front;
	struct Node *Rear;
	item count;
};

struct Queue Q;

void Init()
{
	Q.Front=Q.Rear=NULL;
	Q.count=0;
}

int IsEmpty(){
	return(Q.count==0);
}

Node *MakeNode(item x){
	Node *P;
	P=(Node*)malloc(sizeof(Node));
	P->Data=x;
	P->Next=NULL;
	return P;
}

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

int Pop(){
	int x;
	if(!IsEmpty()){
		x=(int)(Q.Front->Data);
		Q.Front=Q.Front->Next;
		Q.count--;
	}
	else 
		printf("Error! Queue is empty! ");
	return x;
}

void Printf_All_Queue(){
	item x;
	
	while(Q.Front!=NULL)
	{
		x=Q.Front->Data;
		Q.Front=Q.Front->Next;
		printf("%c ",x);
	};
	if(IsEmpty())
		printf("Hang doi dang rong!");
}

item Printf_Front(){
	item x;
	if(!IsEmpty()){
		x=Q.Front->Data;
	}
	else 
		printf("Khong co phan tu nao!");
	return x;
}
int main(){
	char s[100];
	Init();
	int len,i,n=0;
	printf("Moi ban nhap chuoi so: ");
	fflush(stdin);
	gets(s);
	len = strlen(s);
	for(i=0;i<strlen(s);i++){
		if(s[i]!=' ')
			Push(s[i]);
		else continue;
	}
	while(!IsEmpty())
	{	int t,k;
		t=Pop();
		switch(t){
			case '1': k=1; break;
			case '2': k=2; break;
			case '3': k=3; break;
			case '4': k=4; break;
			case '5': k=5; break;
			case '6': k=6; break;
			case '7': k=7; break;
			case '8': k=8; break;
			case '9': k=9; break;
		}
		n=10*n + k;
		
	}
	printf("%d",n);
}

