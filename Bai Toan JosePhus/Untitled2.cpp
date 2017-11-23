#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct node{
	char info[25];
	struct node *NEXT;
};
struct node *HEAD;
struct node *TAIL;
char name[25];
void myInit()
{
	HEAD=(struct node *) malloc(sizeof(struct node));
	TAIL=(struct node *) malloc(sizeof(struct node));
	HEAD->NEXT=TAIL;
	TAIL->NEXT=HEAD;
}
void myInsert()
{
	struct node *TEMP;
	TEMP=(struct node*)malloc(sizeof(struct node));
	strcpy(TEMP->info,name);
	TEMP->NEXT=HEAD->NEXT;
	HEAD->NEXT=TEMP;
}
void myRemove()
{
	struct node *TEMP;
	TEMP=(struct node*) malloc(sizeof(struct node));
	TEMP=HEAD->NEXT;
	HEAD->NEXT=HEAD->NEXT->NEXT;
	strcpy(name,TEMP->info);
}
int main()
{
    system("cls");
	int numSol, counter;
	myInit();
	printf("Enter the number of soldier: ");
	scanf("%d",&numSol);
	for(int i=1;i<=numSol; i++)
	{
		printf("Pls. Type a Name: ");
		scanf("%s",&name);
		myInsert();
	}
	printf("Value for Counter: ");
	scanf("%d",&counter);
	for(int j=1;j<=numSol;j++)
	{
	for(int k=1;k<=counter;k++)
	{
	myRemove();
	if(k==counter){
	puts(name);
	getch();}
	}
	}
}
