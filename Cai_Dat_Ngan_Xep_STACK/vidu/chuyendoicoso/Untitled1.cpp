#include <stdio.h>
#include <conio.h>
int main(){
  #define MAX 100
  #define target 2
  int i=0;
  int n=35;
  int a[MAX];
  while(n!=0){
  	a[i]= n% target;
  	n=n/target;
  	i++;
	}
	for(int k=i-1;k>=0;k--)
		printf("%d",a[k]);
}
