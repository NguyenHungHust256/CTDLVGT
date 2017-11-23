#include <stdio.h>
#include <conio.h>
void insertionSort(int a[],int n){
	int i,j,last;
	for(i=1;i<n;i++){
		last=a[i];
		j=i;
		while((j>0)&&(a[j-1]>last)){
			a[j]=a[j-1];
			j=j-1;
		}
		a[j]=last;
	}
}
int main(){
	int A[]={1,2,3,9,8,7,6};
	insertionSort(A,6);
	for(int i=0;i<6;i++){
		printf("%3d",A[i]);
	}
	
}
