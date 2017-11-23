#include<stdio.h>
#include <conio.h>
int A[20];
int n;
void Result(){
	for(int i=1;i<=n;i++){
		printf("%3d",A[i]);
	}
	printf("\n");
}

void Try(int k){
	for(int j=0;j<=1;j++){
		A[k]=j;
		if(k==n) Result();
		else Try(k+1);
	}
}
int main(){
	printf("Moi ban nhap gia tri cua n= "); scanf("%d",&n);
	Try(1);
	return 0;
}
