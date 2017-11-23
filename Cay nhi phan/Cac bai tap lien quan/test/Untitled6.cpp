#include <stdio.h>
#include <conio.h>
#include <string.h>
int main(){
	char S[]="hung";
	printf("%c",S[0]);
	if(S[0]='h') S[0]='m';
	printf("\n%s",S);
	return 0;
}
