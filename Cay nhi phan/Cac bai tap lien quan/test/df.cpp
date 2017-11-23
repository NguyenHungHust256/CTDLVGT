#include <stdio.h>
#include <conio.h>
void insertionSort(int *A, int n){
	int i,j,a;
	for(i=0;i<n;i++){
		a=A[i];
		j=i;
		while(j>0&&A[j-1]>a){
			A[j]=A[j-1];
			j=j-1;
		}
		A[j]=a;
	}
}

void selectionSort(int *A, int n){
	for(int i=0;i<n-1;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(A[j]<A[min]) min=j;
		}
		int tmp=A[i];
		A[i]=A[min];
		A[min]=tmp;
	}
}

void swap(int &a, int &b){
	int c;
	c=a;
	a=b;
	b=c;
}
void bubbleSort(int *A,int n){
	for(int i=n-1;i>0;i--){
		for(int j=1;j<=i;j++){
			if(A[j-1]>A[j]) swap(A[j],A[j-1]);
		}
	}
}
int main(){
	int A[]={9,8,7,6,5};
	
	bubbleSort(A,5);
//	selectionSort(A,5);
//	insertionSort(A,5);
	for(int i=0;i<5;i++){
		printf("%3d",A[i]);
	}
	
	return 0;
	
}
