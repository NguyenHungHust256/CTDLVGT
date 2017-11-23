#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void demchim(int *T,int n){
	int *U,A=T[0];
	int j=0;
	U=(int*)malloc(n*sizeof(int));
	
	for(int i=1;i<n;i++)
		if(A<T[i]) A=T[i];
		
	for(int k=0;k<=A;k++)
		U[k]=0;
		
	for(int i=0;i<=A;i++)
		for(int k=0;k<n;k++)
			if(T[k]==i) U[i]=U[i]+1;
		
	for(int k=0;k<=A;k++){
		while(U[k]){
			T[j]=k;
			U[k]=U[k]-1;
			j=j+1;
		}
	}	
	printf("\n Day da sap xep la: \n");
	for(int i=0;i<n;i++)
		printf("%d ",T[i]);
   free(U);
}
int main(){
	int T[]={5,4,3,4,6,7,4,5,6,1,2,5,3,4};
	demchim(T,14);
	
}
