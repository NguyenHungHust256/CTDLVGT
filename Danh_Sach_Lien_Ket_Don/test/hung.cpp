#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct nodePtr{
	float data;
	struct nodePtr *next;  // cau truc tu tro 
}Node;  // dinh nghia kieu nay la Node

Node *Create_Node(float X){     // ham nay tra ve kieu Node
	Node *p;     // Khai bao 1 con tro Node kieu Node
	p=(Node*)malloc(sizeof(Node));   // cap phat bo nho cho Node
	p->data=X;  // Node chua 2 truong: Truong Inf va next chi sang cai Node tiep theo
	p->next=NULL;   // Node->next chi den Null, Boi vi khi minh tao ra Node thi minh chua biet No tro di dau
	return p;     // Tra ve cai Node minh moi tao
}

int Is_Empty(Node *Head){
	return !Head;    // Ham kiem tra xem no co trong hay khong
}
Node *Insert_To_Head(Node *Head,float X){
	Node *TempNode;
	TempNode=(Node*)malloc(sizeof(Node));
	TempNode->next=Head;
	TempNode->data=X;
	Head=TempNode;
	return Head;
}

Node *Insert_Middle(Node *Pred, float X){
	Node *TempNode;
	TempNode =(Node*)malloc(sizeof(Node));
	TempNode->data=X;
	TempNode->next=Pred->next;
	Pred->next=TempNode;
	return Pred;
}

Node *Insert_To_Last(Node *Head,float X){
	Node *Pred;
	Node *NewNode;
	NewNode=(Node*)malloc(sizeof(Node));
	Pred=Head;
	while(Pred->next!=NULL){
		Pred=Pred->next;
	}
	NewNode->data=X;
	Pred->next=NewNode;
	NewNode->next=NULL;
	return Head;
}

Node *Delete_Head_List(Node *Head){
	Node *Temp;
	Temp = Head;
	Head = Head->next;
	free(Temp);
	return Head;
}

Node *Delete_Middle(Node *Head,Node *Pred){
	float X;
	if(Is_Empty(Head)==1) printf("\nDanh sach rong!\n");
	
	Node *TempNode;
	TempNode=Pred->next;
	Pred->next=Pred->next->next;
	X=TempNode->data;
	free(TempNode);
	return Head;
}

float Delete_Last_List(Node *Head){
	float X;
	Node *Last; 
	Node *TempNode;
	Last=Head;
	while(Last->next!=NULL){
		TempNode=Last;
		Last=Last->next;
	}
	X=Last->data;
	TempNode->next=NULL;
	free(Last);
	return X;
}

Node *Search(Node *Head, float X){
	Node *TempNode;
	TempNode=Head;
	while(TempNode->data!=X) TempNode=TempNode->next;
	return TempNode;
}

Node *Make_Null(Node *Head){
	while(Is_Empty(Head)) Head=Delete_Head_List(Head);
	return Head;
}

void Print(Node *Head){
	Node *TempNode;
	TempNode=Head;
	int count=0;
	while(TempNode!=NULL){
		printf("%6d",TempNode->data); count++;
		TempNode=TempNode->next;
		if(count%12==0) printf("\n");
		
	}
	printf("\n");
}
int main(){
	  Node *Head;
    Head=NULL;
    Create_Node(4);
    Create_Node(5);
//    Create_Node(6);
    Insert_To_Head(Head,4);
//    Insert_To_Head(Head,5);
//    Insert_To_Last(Head,6);
    Print(Head);
}









