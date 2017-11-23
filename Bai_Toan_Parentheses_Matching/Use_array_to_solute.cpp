#include <stdio.h>
#include <conio.h>
#include<string.h>

#define MAX 100
typedef char item; 
typedef struct stack
	{
		int Top;
		item Data[MAX];
	} Stack;
Stack S;

void Init()
{
	S.Top=0;
}

int IsEmpty(){
	return (S.Top==0); 
}

int IsFull(){
	return (S.Top==MAX);
}

void Push(item x)
{   
  if(!IsFull()){  
	S.Data[S.Top]=x;
	S.Top++;
  }
}

item Pop(){
	item x;
	if(!IsEmpty())
	{
		x=S.Data[S.Top-1];
		S.Top--;
	}
}

int main(){
	char inputString[100], c;
    int i, length;
    Init();
    printf("Moi ban nhap chuoi ngoac () \n");
    gets(inputString);
    length = strlen(inputString);
    
    for(i = 0; i < length; i++){
        if(inputString[i] == '(')
            Push(inputString[i]);
        else if(inputString[i] == ')')
            Pop();
        else {
            printf("Error : Invalid Character !! \n");
            return 0;
        }
    }
     
    if(IsEmpty())
        printf("ok\n");
    else
        printf("Error\n");
         
    return 0;

}
	
