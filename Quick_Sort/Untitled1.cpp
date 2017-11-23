#include <stdio.h>
#include <conio.h>

void swap(int &a, int &b){
	int temp;
	temp = a;
	a = b;
  b = temp;
}
int Partition_head(int a[], int left, int right){
	int i,j,pivot;
	i=left; j = right +1; pivot = a[left];
	while(i<j){
		i++;
		while(i<=right && a[i]<pivot ) i++;
		j--;
		while(j>= left && a[j]>pivot) j--;
		swap(a[i],a[j]);
	}
	swap(a[i],a[j]); swap(a[j],a[left]);
	return j;
}

int Partition_Mid(int A[], int left, int right){
	int i=left; 
	int j = right;
	int pivot = A[(left+right)/2];
	while(i<j){
		while(A[i]<pivot) i++;
		while(A[j]>pivot) j--;
		if(i<j){
			swap(A[i], A[j]);
			i++;
			j--;
		}
	}
}

void quick_Sort(int A[], int left, int right){
	int pivot;
	if(left<right){
//		pivot = Partition_head(A,left,right);
	  pivot = Partition_Mid(A,left,right);
		if(left < pivot) quick_Sort(A, left, pivot - 1);
		if(right > pivot) quick_Sort(A, pivot+1, right);
	}
}

int main(){
	int A[] = {6,7,3,5,9,1,2};
	quick_Sort(A,0,6);
	for(int i=0;i<7;i++){
		printf("%3d",A[i]);
	}
	getch();
	
}

