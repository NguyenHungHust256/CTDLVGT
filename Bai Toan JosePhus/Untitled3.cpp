#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node
{
	int position;
	struct node *next;
	struct node *prev;

};


void josephus(int,int);
void eliminate(int,int,int);
struct node *head;
struct node *tail;
struct node *temp;
struct node *curr;
struct node *end;
struct node *before;
struct node *after;
struct node *out;


int main()
{
	int soldier;
	int startPos;
	int passby;
	
	
	printf("\n Enter the number of soldiers?(maximun of 50):");
	scanf("%d",&soldier);


	if(soldier>50)
	{
		printf("\n\n\t Invalid entry......\n\n");
		
	}
	printf("\n\n\t Which position would you like to start with?");
	scanf("%d",&startPos);

	printf("\n\n\t How many people do you want to skip each round? ");
	scanf("%d",&passby);

	
	josephus(soldier,startPos);
	eliminate(soldier,passby,startPos);
	scanf("%d",&soldier);
	
	 
return 0;
}
void josephus(int soldier,int startPos)
{

	int x, y=1;
	head = tail = NULL;
	
	for(x = startPos; x < (soldier + startPos);x++)
	{
		if(x == startPos)
		{
			 temp= (struct node *)malloc(sizeof(struct node));
			 temp ->prev =NULL;
			 temp ->next =NULL;
			 temp ->position = x;
			 head = tail = temp;
		}

		else
		{
			temp=(struct node *)malloc(sizeof(struct node));
			curr = head = tail;
			
			while(curr ->next != NULL)
			{
				curr = curr ->next;
			}

			if(x > soldier)
			{
				temp ->position =y;
				temp ->next= NULL;
				temp ->prev =curr;
				curr ->next =temp;
			}
			else
			{
				temp ->position =x;
				temp ->next =NULL;
				temp ->prev =curr;
				curr -> next=temp;
			}
		}
		y++;
	}
	end = head = tail;

	while(end ->next !=NULL)
	{
		end = end ->next;
	}

	end ->next = head = tail;
	head ->prev =end;
	tail ->prev =end;
}

void eliminate(int soldier,int passby,int startPos)
{
	int x,z;
	curr = head = tail;

	for(x =1; x < soldier; x++)
	{
		for(z=1;z <=passby; z++)
		{
			curr = curr ->next;
		}
			out= curr;
			before= curr ->prev;
			after= curr ->next;

			
			printf("\n\n the person who was sitting at seat",out->position );
			before ->next = after;
			after ->prev = before;
			curr = after;
			free(out);
		}
	

		printf("\n\n the last soldier is sitting at seat %d", curr ->next->position);
}
