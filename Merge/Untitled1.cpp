#include <stdio.h>
#include <conio.h>
int sum=0;
int f(int m,int n ){
	if(n>=m) return 0;
	else {
		++sum;
		f(m,(n+m)/2);
	}
	return sum;
}

int main(){
	int m=-9, n=-10234;
	f(m,n);
	printf("%3d",sum);
	
}
