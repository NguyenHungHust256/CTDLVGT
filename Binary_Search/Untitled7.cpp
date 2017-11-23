#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//void Merge(int *A, int left, int mid, int right);
//void Merge_Sort(int *A, int left, int right){
//	if(left<right){
//		int mid=(right+left)/2;
//		Merge_Sort(A,left,mid);
//		Merge_Sort(A,mid+1,right);
//		Merge(A,left,mid,right);
//	}
//}
//
//void Merge(int *A, int left, int mid, int right){
//	int i=left;
//	int j=mid+1;
//	int *B;
//	B=(int*)malloc((right-left+1)*sizeof(int));
//	
//	for(int k=0;k<(right-left);k++){
//		if(A[i]<A[j]){
//			B[k]=A[i];
//			i++;
//		}
//		else {
//			B[k]=A[j];
//			j++;
//		}
//		
//		if(i==mid+1){
//		    while(j<=right){
//		    	    k++;
//		    		B[k]=A[j];
//					j++;
//			}
//		}
//		
//		if(j==right+1){
//			while(i<=mid){
//				k++;
//				B[k]=A[i];
//				i++;
//			}
//		}
//	}
//	for(int k=0;k<=(right-left);k++)
//		A[left+k]=B[k];
//	free(B);
//}
int Search_Binary(int *A,int left,int right,int y){

	int mid=(left+right)/2;
	if(y==A[mid]) return mid;
	else {
		if(y<A[mid]) return Search_Binary(A,left,mid-1,y);
		else 
			return Search_Binary(A,mid+1,right,y);
	}
}

int main(){
	int A[10],n=10;
	int i,y;
	for(i=0;i<9;i++){
		printf("A[%d] = \n",i);
		scanf("%d",&A[i]);
	}
	printf("\nBan can tim y= ");scanf("%d",&y);
//	Merge_Sort(A,0,9);
	printf("\n Vi tri cua y can tim la %d ",Search_Binary(A,0,9,y)); 
	
}
