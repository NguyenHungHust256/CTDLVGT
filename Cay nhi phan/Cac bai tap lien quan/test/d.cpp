#include <stdio.h>

void outPut(int *a,int n){
	for(int i=0;i<n;i++){
		printf("%3d",a[i]);
	}
	printf("\n");
}

void merge(int *a,int l, int m, int r){
	int i=0;
	int b=(l+r-1);
	int temp[b];
	int lr=m-1;
	while(l<lr && m<r){
		if(a[l]<a[m]){
			temp[i++] = a[l++];
		}
		else 
		{
			temp[i++]=a[m++];
		}
	}
	while(l<lr){
		temp[i++] = a[l++];
	}
	
	while(m<r){
		temp[i++] = a[m++];
	}
	
	for(int j=0;j<b;j++){
		a[j]= temp[j];
	}
}

void mergeSort(int *a, int l, int r){
	if(l<r){
		int m=(l+r)/2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,r);
		merge(a,l,m,r);
	}
}

int main(){
	int a[]={1,6,5,4,3};
	mergeSort(a,0,5);
	outPut(a,4);
	return 0;
}
