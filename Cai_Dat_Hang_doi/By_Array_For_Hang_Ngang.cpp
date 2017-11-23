//Xay dung hang doi (Queue)
// Xay dung bang mang
#include <stdio.h>
#include <conio.h>
#define MAX 5
typedef int item;
struct Queue
{
	int Front, Rear;
	item Data[MAX];
	int count;
};
struct Queue Q;

void Init()
{
	Q.Front=0;
	Q.Rear=-1;
	Q.count =0;
}


int IsEmpty()
{
	return (Q.count==0);
}

int IsFull()
{
	return (Q.count==MAX);
}

void Push(item x){
	if(IsFull())
		printf(" Hang doi day ! ") ;
	else
	{
		Q.Data[++Q.Rear]=x;
		Q.count++;
	}
}

int Pop()
{	
	item x;
	if(IsEmpty())
		printf("Hang doi rong!");
	else
	{
		x=Q.Data[Q.Front];
		for(int i=Q.Front;i<Q.Rear;i++)
			Q.Data[i]=Q.Data[i+1];
		Q.Rear--;
		Q.count--;
	}
	return x;
}

item Qfront()
{
	if(IsEmpty())
		printf("Hang doi rong !");
	else return Q.Data[Q.Front];
}

void Push_Circular(item x)
{
	if(IsFull())
		printf("Hang doi da day!");
	else
	{
		Q.Data[(++Q.Rear)%MAX]=x;
		Q.count++;
	}
}

int Pop_Circular()
{
	if(IsEmpty())
		printf("Hang doi rong !");
	item x=Q.Data[Q.Front];
	Q.Front=(Q.Front++)%MAX;
	Q.count--;
	return x;
}

int main(){
	
}
