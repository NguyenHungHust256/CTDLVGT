#include <stdio.h>
#include <conio.h>
void chuyen(int n,char a, char b){
	printf("Chuyen coc %c sang coc %c\n",a,b);
}
void Thap_Ha_Noi(int n,char a,char b,char c){
	if(n==1) chuyen(1,a,c);
	else
	{
		Thap_Ha_Noi(n-1,a,c,b);
		chuyen(n,a,c);
		Thap_Ha_Noi(n-1,b,a,c);
	}
}
int main(){
	char a='A',b='B',c='C';
	int n;
	printf("Moi ban nhap n= ");
	scanf("%d",&n);
	Thap_Ha_Noi(n,a,b,c);
}
