#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void Merge(int *A, int left, int mid, int right);
void Merge_Sort(int *A, int left, int right){
	if(left<right){
		int mid=(right+left)/2;
		Merge_Sort(A,left,mid);
		Merge_Sort(A,mid+1,right);
		Merge(A,left,mid,right);
	}
}

void Merge(int *A, int left, int mid, int right){
	int i=left;
	int j=mid+1;
	int *B;
	B=(int*)malloc((right-left+1)*sizeof(int));
	
	for(int k=0;k<(right-left);k++){
		if(A[i]<A[j]){
			B[k]=A[i];
			i++;
		}
		else {
			B[k]=A[j];
			j++;
		}
		
		if(i==mid+1){
		    while(j<=right){
		    	    k++;
		    		B[k]=A[j];
					j++;
			}
		}
		
		if(j==right+1){
			while(i<=mid){
				k++;
				B[k]=A[i];
				i++;
			}
		}
	}
	for(int k=0;k<=(right-left);k++)
		A[left+k]=B[k];
	free(B);
}
int main(){
	int a[10],n=10,i;
	for(i=0;i<n;i++)
	{
		printf("Nhap so a[%d]=  ",i);
		scanf("%d",&a[i]);
	}
	Merge_Sort(a,0,9);
	for(i=0;i<n;i++)
		printf(" %d ",a[i]);
    getch();
}
