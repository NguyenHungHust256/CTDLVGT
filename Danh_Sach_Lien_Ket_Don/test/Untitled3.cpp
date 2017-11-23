#include <stdio.h>
#include <conio.h>
#include <math.h>

int A[20];
int n;
void Result(){
	for(int i=1;i<=n;i++){
		printf("%3d",A[i]);
	}
	printf("\n");
}
int UCV(int j, int k){
	for(int i=1;i<=k-1;i++){
		if(j==A[i]||fabs(k-i)==fabs(j-A[i])) return 0;
	}
	return 1;
}
void Try(int k){
	for(int j=1;j<=n;j++){
		if(UCV(j,k)){
			A[k]=j;
			if(k==n) Result();
			else Try(k+1);
		}
	}
}

int main(){
	printf("Moi ban nhap gia tri cua n: "); scanf ("%d",&n);
	Try(1);
	return 0;
}
