#include <stdio.h>
#include <conio.h>

int binarySearch(float array[], int size, int target)
{
	int lower = 0, upper = size - 1, mid;
	while(lower <= upper)
	{
		mid = (upper+lower)/2;
		if(array[mid]>target)
			upper = mid-1;
		else if(array[mid]<target)
			lower = mid + 1 ;
		else 
			return mid;
	}
	return -1;
}

int main(){
	float A[6]={1,2,3,4,5,6};
	printf("%3d",binarySearch(A,6,2));
	getch();
}
