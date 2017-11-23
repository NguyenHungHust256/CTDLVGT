#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef long ElementType;
struct PointerType{
	ElementType Inf;
	PointerType *Next;
};
typedef PointerType NodeType;

NodeType *Insert_To_Head(NodeType *First,ElementType X){
	NodeType *TempNode;
	TempNode=(NodeType*)malloc(sizeof(NodeType));
	TempNode->Next=First;
	TempNode->Inf=X;
	First=TempNode;
	return First;
}

NodeType *Insert_Middle(NodeType *Pred,ElementType X){
	NodeType *TempNode;
	TempNode = (NodeType*)malloc(sizeof(NodeType));
	TempNode->Inf=X;
	TempNode->Next=Pred->Next;
	Pred->Next=TempNode;
	return TempNode;

}

NodeType *Delete_Head(NodeType *First)
{
	NodeType *TempNode;
	TempNode=First->Next;
	free(TempNode);
	return First;
	
}

ElementType Delete(NodeType *Pred){
	ElementType X;
	NodeType *TempNode;
	TempNode=Pred->Next;
	Pred->Next=Pred->Next->Next;
	X=TempNode->Inf;
	free(TempNode);
	return X;
}

void Print(NodeType *First){
	NodeType *TempNode;
	TempNode=First;
	int count=0;
	while(TempNode->Next!=NULL){
		printf("%6d",TempNode->Inf);
		count++;
		TempNode=TempNode->Next;
		if(count%12==0) printf("\n");
	}
	printf("\n");
}

int Is_Empty(NodeType *First){
	return !First;
}

NodeType *MakeNull(NodeType *First){
	while (!Is_Empty(First)) First=Delete_Head(First);
	return First;
}

int main(){
	NodeType *S1, *S2, *S3, *V1, *V2, *V3;
	ElementType a; 
	int i,n;
	system("clr");
//	randomize();
	S1=NULL;
	//Tao phan tu dau tien
	a=-100+random()%30000;
	S1=Insert_To_Head(S1,a);
	printf("Nhap vao so luong phan tu n= ");
	scanf("%i",&n);
	printf("\n");
	//Tao ngau nhien danh sach va dua ra man hinh
	V1=S1;
	for(i=2;i<=n;i++){
		a=-100+random(201);
		V1=Insert_Middle(V1,a);
	}
	printf("====> Danh sach ban dau: \n"); Print(S1);
	printf("\n");
	
	
	V1=S1;S2=NULL;S3=NULL;
	while(V1){
		if(V1->Inf>0)
			if(!S2){
				S2=Insert_To_Head(S2,V1->Inf);V2=S2;
			}
			else {
				Insert_Middle(V2,V1->Inf);V2=V2->Next;
			}
		if(V1->Inf<0)
			if(!S3){
				S3=Insert_To_Head(S3,V1->Inf);V3=S3;
			}
			else{
				Insert_Middle(V3,V1->Inf); V3=V3->Next;
			}
		V1=V1->Next;
	}
	printf("=======>Danh sach so duong:  \n");
	Print(S2);
	printf("\n");
	printf("=====> Danh sach so am: \n");
	Print(S3);
	printf("\n");
	getch();
}



