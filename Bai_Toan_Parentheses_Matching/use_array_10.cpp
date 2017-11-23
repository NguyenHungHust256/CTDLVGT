// Giai bai toan Parentheses Matching
// Trong bai toan nay toi chi xet ngoac ()
//Viec phat trien bai toan con lai tuong tu
#include <stdio.h>
#include <conio.h>
#include <conio.h>
#define MAX 7

typedef char item;
typedef struct stack
{
	int Top;
	item Data[MAX];
}Stack;
// Khoi tao Stack
void Init(Stack S)
{
	S.Top=0;
}
//Kiem tra xem ngan xep co rong hay khong;
int IsEmpty(Stack S)
{
	return (S.Top==0);
}
//Kiem tra xem no da day hay chua
int IsFull(Stack S)
{
	return (S.Top==MAX);
}
//Push
void Push(Stack S, item x)
{
	if(!IsFull)
	{
		S.Data[S.Top]=x;
		S.Top++;
	}	
}
//lam xuat hien phan tu trong ngan xep
item Appear(Stack S)
{
	while(!IsEmpty)
	{
		return S.Data[S.Top--];
	}
}
// Thuc hien thao tac Pop
item Pop(Stack S)
{	item x;
	if(!IsEmpty)
	{
		S.Top=S.Top -1;
		x=S.Data[S.Top];	
	}
	return x;
}
int main(){
	Stack S;
	Init(S);
	int i, count=0,a=0;
	char X[MAX]="((()))";
//	printf("Moi ban nhap chuoi ban muon kiem tra: ");
//	gets(X);
	for(i=0;i<MAX-1;i++)
	{
		if(X[i]=='(')
		    
				Push(S,'(');
			
//		else 
//			if(X[i]==')')
//				{
//					if(X[i]==Pop(S))
//						count+=1;
//				}
		printf("%c\n",X[i]);
		
	}
	printf("So phan tu trong ngan xep la %c",Appear(S));
	printf("%d",count);
	if(count==3)
		printf("\nOk, thoa man");
	else
		printf("\nXin loi ban, cai ban nhap dang co van de");
}
