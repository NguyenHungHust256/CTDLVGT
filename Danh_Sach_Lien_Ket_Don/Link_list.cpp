#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef float ElementType;  // dinh nghia kieu float la ElementType
typedef struct PointerType{
	ElementType Inf;
	PointerType *Next;  // cau truc tu tro 
}NodeType;  // dinh nghia kieu nay la NodeType

NodeType *Create_Node(ElementType X){     // ham nay tra ve kieu NodeType
	NodeType *Node;     // Khai bao 1 con tro Node kieu NodeType
	Node=(NodeType*)malloc(sizeof(NodeType));   // cap phat bo nho cho Node
	Node->Inf=X;  // Node chua 2 truong: Truong Inf va Next chi sang cai Node tiep theo
	Node->Next=NULL;   // Node->Next chi den Null, Boi vi khi minh tao ra Node thi minh chua biet No tro di dau
	return Node;     // Tra ve cai Node minh moi tao
}

int Is_Empty(NodeType *First){
	return !First;    // Ham kiem tra xem no co trong hay khong
}
NodeType *Insert_To_Head(NodeType *First,ElementType X){
	NodeType *TempNode;
	TempNode=(NodeType*)malloc(sizeof(NodeType));
	TempNode->Next=First;
	TempNode->Inf=X;
	First=TempNode;
	return First;
}

NodeType *Insert_Middle(NodeType *Pred, ElementType X){
	NodeType *TempNode;
	TempNode =(NodeType*)malloc(sizeof(NodeType));
	TempNode->Inf=X;
	TempNode->Next=Pred->Next;
	Pred->Next=TempNode;
	return Pred;
}

NodeType *Insert_To_Last(NodeType *First,ElementType X){
	NodeType *Pred;
	NodeType *NewNode;
	NewNode=(NodeType*)malloc(sizeof(NodeType));
	Pred=First;
	while(Pred->Next!=NULL){
		Pred=Pred->Next;
	}
	NewNode->Inf=X;
	Pred->Next=NewNode;
	NewNode->Next=NULL;
	return First;
}

NodeType *Delete_First_List(NodeType *First){
	NodeType *Temp;
	Temp = First;
	First = First->Next;
	free(Temp);
	return First;
}

NodeType *Delete_Middle(NodeType *First,NodeType *Pred){
	ElementType X;
	if(Is_Empty(First)==1) printf("\nDanh sach rong!\n");
	
	NodeType *TempNode;
	TempNode=Pred->Next;
	Pred->Next=Pred->Next->Next;
	X=TempNode->Inf;
	free(TempNode);
	return First;
}

ElementType Delete_Last_List(NodeType *First){
	ElementType X;
	NodeType *Last; 
	NodeType *TempNode;
	Last=First;
	while(Last->Next!=NULL){
		TempNode=Last;
		Last=Last->Next;
	}
	X=Last->Inf;
	TempNode->Next=NULL;
	free(Last);
	return X;
}

NodeType *Search(NodeType *First, ElementType X){
	NodeType *TempNode;
	TempNode=First;
	while(TempNode->Inf!=X) TempNode=TempNode->Next;
	return TempNode;
}

NodeType *Make_Null(NodeType *First){
	while(Is_Empty(First)) First=Delete_First_List(First);
	return First;
}

void Print(NodeType *First){
	NodeType *TempNode;
	TempNode=First;
	int count=0;
	while(TempNode!=0){
		printf("%6d",TempNode->Inf); count++;
		TempNode=TempNode->Next;
		if(count%12==0) printf("\n");
		
	}
	printf("\n");
}
int main(){
	NodeType *First;
    First=NULL;
    Create_Node(4);
    Create_Node(5);
    Create_Node(6);
    Insert_To_Head(First,4);
    Insert_To_Head(First,5);
    Insert_To_Last(First,6);
    Print(First);
}









