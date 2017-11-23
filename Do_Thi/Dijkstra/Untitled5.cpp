/*
  Thuat toan dijkstra.
  Dau vao: Bai1.inp
  	6
		1 6
		0 1 2 0 0 0
		1 0 2 2 3 0
		2 2 0 5 4 0
		0 2 5 0 3 2
		0 3 4 3 0 4
		0 0 0 2 4 0
	  
	  +) Voi dong dau tien la n(so dinh)
	  +) Dong thu 2 la 2 dinh dau va dinh cuoi
	  +) Cac dong tiep thep la ma tran trong so.
	
	Dau ra: Tim duong di ngan nhat tu dinh dau den dinh cuoi bang thuat toan Dijkstra
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 10
#define Fileln "Bai1.inp"


void Doc_File(int A[MAX][MAX], int &n, int &D, int &C){
	FILE *f = fopen(Fileln,"rb");
	fscanf(f,"%3d%3d%3d",&n,&D,&C);
	printf("Ma tran lien ket tuong ung.\n");
	printf("%3d\n%3d%3d\n",n,D,C);
	for(int i = 0;i<n;i++){
		for(int j=0; j<n; j++){
			fscanf(f,"%d",&A[i][j]);
			printf("%3d",A[i][j]);
		}
		printf("\n");
	}
	fclose(f);
	D--;C--;
}

void Dijkstra(int A[MAX][MAX], int n, int D, int C) {
 bool chuaxet[MAX];
 int d[MAX], Truoc[MAX], u, min;
 for(int i=0; i<n; i++){
  d[i] = 1000;
  chuaxet[i] = true;
  Truoc[i] = D;
 }
 d[D] = 0;
 chuaxet[D] = false;
 u = D;
 while(u != C){
  for(int j=0; j<n; j++)
   if(A[u][j]>0 && d[j]>A[u][j]+d[u] && chuaxet[j]) {
    d[j] = A[u][j]+d[u];
    Truoc[j] = u;
   }
  min =1000;
  for(int j = 0; j<n; j++)
	  if(min>d[j]&& chuaxet[j]){
	   min = d[j];
	   u = j;
	  }
  chuaxet[u] = false;
 }
  printf("\nDuong di ngan nhat tu D toi C la : %3d\n",d[C]);
  printf("Duong di ngan nhat la: \n\t\t\t");
  printf("%3d %3d",C+1,Truoc[C]+1);
  int c = Truoc[C];
  while(c!=D){
  	c= Truoc[c];
  	printf(" %3d ",c+1);
	}

}
main(){
	int A[MAX][MAX],n,Dau,Cuoi;
  Doc_File(A,n,Dau,Cuoi);
  Dijkstra(A,n,Dau,Cuoi);
	getch();
	
}
