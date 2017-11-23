#include <stdio.h>
#include <conio.h>

void xuat(int *&a, int l, int r){
	int i;
	for(i=l;i<=r;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
}

void tron(int *&a, int l, int m, int r){
	int i, length;
	int l_end = m-1;
	i=l;
	length = r-1;
	
	int temp[length];
	while(l<=l_end && m<=r){
		if(a[l]<=a[m]){
			temp[i++]=a[l++];
		}
		else{
			temp[i++]=a[m++];
		}
	}
	
	while(l<=l_end){
		temp[i++] = a[l++];
	}
	
	while(m<=r){
		temp[i++]=a[m++];
	}
	int j;
	for(j=0;j<(l-r+1);j++){
		a[j]=temp[j];
	}
}

void merge_sort(int *&a, int l, int r){
	int m;
	if(l<r){
		m=(l+r)/2;
		merge_sort(a,l,m);
		merge_sort(a,m+1,r);
		tron(a,l,m,r);
	}
}

int main(){
	int n=5;
	int a[]={2,6,3,8,5};
	merge_sort(a,0,n-1);
	xuat(a,0,n-1);
	return 0;
}


