#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef char item;
typedef struct stack{
	int Top;
	item Data[MAX];
}Stack;

Stack S;
void Init()
{
	S.Top=0;
}

int IsEmpty()
{
	return(S.Top==0); 
}

int IsFull()
{
	return (S.Top==MAX);
}

void Push(item x)
{
	if(!IsFull())
	{
		S.Data[S.Top]=x;
		S.Top++;
	}
	else 
		printf("Xin loi ngan xep da day");
}

item Pop()
{
	if(!IsEmpty())
	{
		item x;
		
		S.Top--;
		return x=S.Data[S.Top];
	}
	
}
item Peak()
{
	return S.Data[S.Top];  // Lay du lieu tai Top
}

int value(char x){
	if(x=='+'||x=='-')
		return 1;
	else if(x=='*'||x=='/')
		return 2;
	else if(x=='^')
		return 3;
    		
}

int Compare(char x, char y)
{
	if(value(x)>value(y)||value(y)==3)
		return 0;
	else return 1;
}

int main(){
	item A[MAX];
	item Start[MAX];
	Init();
	int i,j=0;
	printf("Moi ban nhap bieu thuc: \n");
	fflush(stdin);
	gets(Start);
	for(i=0;i<strlen(Start);i++)
	{
		if(Start[i]=='(')
			Push(Start[i]);
		else if(Start[i]==')')
		{	
		char temp;
			temp=Pop();
			do{
				A[j]=temp;
				j++;
				temp=Pop();
			}while(Pop()!='(');
			
		}
	    else if(Start[i]>=48 && Start[i]<=57)
		{
			A[j]=Start[i];
			j++;
		}
		else{
			if(IsEmpty()) 
				Push(Start[i]);
			else{
				while(Compare(Start[i],S.Data[S.Top-1])==1)
				{	A[j]=Pop();
					j++;
				};
				Push(Start[i]);
			}
		}
		while(i==strlen(Start)-1)
		{
			A[j]=Pop();
			j++;
			if(IsEmpty())
				break;
		}
	}
	for(i=0;i<strlen(Start);i++)
		printf("%c ",A[i]);
	
}
