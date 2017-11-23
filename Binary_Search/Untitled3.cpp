#include <stdio.h>
#include <conio.h>

int binarySearch(int A[],int size,int target)
{
	int lower = 0, upper =size-1, mid;
	while(lower<=upper){
		mid = (upper+lower)/2;
		if(A[mid]==target) return mid;
		else if(A[mid]<target)
		{
			lower = mid +1;
		}
		else
		{
			upper = mid - 1;
		}
	}
	return -1;
}

int main(){
	int A[6]={1,2,3,4,5,6};
	printf("vi tri: %d",binarySearch(A,6,0));
	
}
