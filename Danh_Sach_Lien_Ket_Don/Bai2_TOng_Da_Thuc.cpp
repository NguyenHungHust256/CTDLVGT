#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct Polynomial{
	int coeff;
	int pow;
	struct Polynomial *Next;
}NODE;

typedef struct list{
 NODE *pHead;
 
}LIST;

void Init(LIST &L){
	L.pHead = NULL;
}

NODE *Create_Node(int heso,int mu){
	NODE *p;
	p=(NODE *)malloc(sizeof(NODE));
	if(p==NULL)
		return NULL;
	p->coeff = heso;
	p->pow = mu;
	p->Next=NULL;
	return p;
}

void Insert_Last(LIST &L,NODE *p)
{
	NODE *K;
	K=(NODE*)malloc(sizeof(NODE));
	K=L.pHead;
	if(L.pHead==NULL)
		L.pHead=p;
	else{
		while(K->Next!=NULL)
			K=K->Next;
		K->Next=p;
		p->Next=NULL;
	}
}

void InPut(LIST &L){
	int n, heso;
	printf("Moi ban nhap vao so mu lon nhat cua da thuc : "); scanf("%d",&n);
	for(int i=n;i>=0;i--){
		printf("He so cua X^%d la : ",i);
		scanf("%d",&heso);
		
		NODE *p;
		p=Create_Node(heso,i);
		Insert_Last(L,p);
	}
}

void Cong_Da_Thuc(LIST L1,LIST L2,LIST &L){
	NODE *p,*q;
//	p= (NODE*)malloc(sizeof(NODE));
//	q= (NODE*)malloc(sizeof(NODE));
	if(L1.pHead->pow > L2.pHead->pow){
		L=L1;
		p=L2.pHead;
	}
	else{
		L=L2;
		p=L1.pHead;
	}
	q=L.pHead;
	while(q->pow > p->pow) q=q->Next;
	while(q!=NULL){
		q->coeff= q->coeff + p->coeff;
		q= q->Next;
		p=p->Next;
	}
}

void OutPut(LIST L){
	for(NODE *p=L.pHead;p!=NULL;p=p->Next){
		printf("%d.X^%d",p->coeff,p->pow);
		if(p->Next==NULL) break;
		if(p->Next->coeff >= 0) printf(" + ");
		else{
			if(p->Next->coeff < 0)
				printf(" ");
		}
	}
}
int main(){
	LIST L1,L2,L;
	Init(L1);
	Init(L2);
	Init(L);
	printf("Nhap da thuc P(x): \n");
	InPut(L1); OutPut(L1);
	printf("\nNhap da thuc Q(x): \n");
	InPut(L2); OutPut(L2);
	printf("\nTong hai da thuc da cho la: ");
	Cong_Da_Thuc(L1,L2,L);
	OutPut(L);
	getch();
	return 0;
}
