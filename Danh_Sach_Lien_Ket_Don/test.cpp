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

void Tich_Hai_Da_Thuc(LIST &L1,LIST &L2,LIST &L){
	NODE *p1,*p2,*p;
	int a,b;
	p=(NODE *)malloc(sizeof(NODE));
	Init(L);
	p1=L1.pHead;
	while(p1!=NULL){
		for(p2=L2.pHead;p2!=NULL;p2=p2->Next){
			a= p1->coeff * p2->coeff;
			b= p1->pow+p2->pow;
			p=Create_Node(a,b);
			Insert_Last(L,p);
		}
		p1=p1->Next;
	}
}
void Ham_Rut_Gon_Tich(LIST L,LIST &R){
	NODE *p=L.pHead;
	int n,a=0;
	printf("\nTong cua 2 so mu lon nhat la bao nhieu? n = "); scanf("%d",&n);
	for(int i=0;i<=n;i++){
		for(p=L.pHead;p!=NULL;p=p->Next){
			if(p->pow==i){
				a= a + p->coeff;
			}
	  }
		NODE *q=Create_Node(a,i);
		Insert_Last(R,q);
		a=0;
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
	LIST L1,L2,L,R;
	Init(L1);
	Init(L2);
	Init(L);
	Init(R);
	printf("Nhap da thuc P(x): \n");
	InPut(L1); OutPut(L1);
	printf("\nNhap da thuc Q(x): \n");
	InPut(L2); OutPut(L2);
	printf("\nTich hai da thuc da cho la: ");
	Tich_Hai_Da_Thuc(L1,L2,L);
	OutPut(L);
	printf("\nSau khi rut gon ta co: ");
	Ham_Rut_Gon_Tich(L,R);
	OutPut(R);
	getch();
	return 0;
}
