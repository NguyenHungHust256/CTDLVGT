#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Tnode{
	int inf;
	struct Tnode *left;
	struct Tnode *right;
}treeNode;
int a=0;
treeNode* makeTreeNode(int word);
treeNode *RandomInsert(treeNode *tree, int inf);
void freeTree(treeNode *tree);
void printPreorder(treeNode *tree);
void printPostorder(treeNode *tree);
void printInorder(treeNode *tree);
int countNodes(treeNode *tree);
int depth(treeNode *tree);
void printEven(treeNode *tree);
void countNodeMore(treeNode *RootTree, int k);
bool isIsomorphic(treeNode* n1, treeNode *n2);
int sumOdd(treeNode *tree);
treeNode *mirrow(treeNode *nodePtr);
int main(){
	printf("\n>>>>>>Tree 1<<<<<<<<\n");
	treeNode *randomTree=NULL;
	int inf=0;
	int k;
	while(inf!=11){
		printf("\nBan muon ket thuc thi an 11: \t");
		scanf("%3d",&inf);
		if(inf==11) printf("\nEm di xa qua.Goodbye\n");
		else{
			randomTree=RandomInsert(randomTree,inf);
		}
	}
	printf("\nThu tu truoc: "); printPreorder(randomTree);
	printf("\nThu tu giua: "); printInorder(randomTree);
	printf("\nThu tu sau: "); printPostorder(randomTree);
	printf("\n\n\nThu tu giua cua nhung so chan: "); printEven(randomTree);
	printf("\n Tiep theo chung toi se dua ra nhung so lon hon so K ma ban dua ra: K= "); scanf("%3d",&k); countNodeMore(randomTree,k);
	printf("\n>>>Tong cac so le trong cay 1 la: <<<<<<<\n");
	printf("%3d",sumOdd(randomTree));
	
	printf("\n\n>>>>>Sau khi da phan xa guong<<<<<<<<");
	mirrow(randomTree);
	
	printf("\nThu tu truoc: "); printPreorder(randomTree);
	printf("\nThu tu giua: "); printInorder(randomTree);
	printf("\nThu tu sau: "); printPostorder(randomTree);
	printf("\n\n\nThu tu giua cua nhung so chan: "); printEven(randomTree);
	printf("\n Tiep theo chung toi se dua ra nhung so lon hon so K ma ban dua ra: K= "); scanf("%3d",&k); countNodeMore(randomTree,k);
	printf("\n>>>Tong cac so le trong cay 1 la: <<<<<<<\n");
	printf("%3d",sumOdd(randomTree));
//	// Tao cay thu 2
//	printf("\n>>>>>>>> Tree 2<<<<<<<<<<\n");
//		treeNode *randomTree2=NULL;
//	int inf2=0;
//	int k2;
//	while(inf2!=11){
//		printf("\nBan muon ket thuc thi an 11: \t");
//		scanf("%3d",&inf2);
//		if(inf2==11) printf("\nEm di xa qua.Goodbye\n");
//		else{
//			randomTree2=RandomInsert(randomTree2,inf2);
//		}
//	}
//	printf("\nThu tu truoc: "); printPreorder(randomTree2);
//	printf("\nThu tu giua: "); printInorder(randomTree2);
//	printf("\nThu tu sau: "); printPostorder(randomTree2);
//	printf("\n\n\nThu tu giua cua nhung so chan: "); printEven(randomTree2);
//	printf("\n Tiep theo chung toi se dua ra nhung so lon hon so K ma ban dua ra: K= "); scanf("%3d",&k2); countNodeMore(randomTree,k2);
//	
//	//So sanh 2 cay co dang cau ha khong
//	printf("\n>>>>>>>>2 Cay nay co dang cau khong <<<<<<<<\n");
//	if(isIsomorphic(randomTree,randomTree2)) printf("Ok. Dang cau day thang ban!");
//	else printf("\nNo. Khong phai dang cau!");
//	//Tinh tong cac so le:
//	printf("\n>>>Tong cac so le trong cay 2 la: <<<<<<<\n");
//	printf("%3d",sumOdd(randomTree2));
	return 0;
}

treeNode *makeTreeNode(int inf){
	treeNode *p;
	p=(treeNode *)malloc(sizeof(treeNode));
	if(p==NULL){
		printf("\nKhong the cap phat bo nho");
		exit(1);
	}
	else
	{
		p->left=NULL;
		p->right=NULL;
		p->inf=inf;
	}
	return p;
}

treeNode *RandomInsert(treeNode *tree, int inf){
	treeNode *newNode,*p;
	newNode = makeTreeNode(inf);
	if(tree == NULL) return newNode;
	if(rand()%2==0){
		p=tree;
		while(p->left!=NULL) p=p->left;
		p->left=newNode;
		printf("Node %d la nut con trai cua %d \n",inf,p->inf);
	}
	else {
		p=tree;
		while(p->right!=NULL) p=p->right;
		p->right=newNode;
		printf("Node %d la Node phai cua %d\n",inf,p->inf);
	}
	return tree;
}

void freeTree(treeNode *tree){
	if(tree==NULL) return;
	freeTree(tree->left);
	freeTree(tree->right);
	free(tree);
	return;
}

int countNodes(treeNode *tree){
	if(tree==NULL) return 0;
	else{
		int l=countNodes(tree->left);
		int r=countNodes(tree->right);
		return 1+l+r;
	}
}

int depth(treeNode *tree){
	if(tree==NULL) return 0;
	int l=depth(tree->left);
	int r=depth(tree->right);
	return 1+(l>r?l:r);
}

void printPreorder(treeNode *tree){
	if(tree!=NULL){
		printf("%3d",tree->inf);
		printPreorder(tree->left);
		printPreorder(tree->right);
	}
}

void printInorder(treeNode *tree){
	if(tree!=NULL){
		printInorder(tree->left);
		printf("%3d", tree->inf);
		printInorder(tree->right);
	}
}

void printPostorder(treeNode *tree){
	if(tree!=NULL){
		printPostorder(tree->left);
		printPostorder(tree->right);
		printf("%3d",tree->inf);
	}
}

void printEven(treeNode *tree){
	if(tree!=NULL){
		printEven(tree->left);
		if(tree->inf %2 ==0)
			printf("%3d",tree->inf);
		printEven(tree->right);
	}
}

void countNodeMore(treeNode *RootTree, int k){
	if(RootTree!=NULL){
		countNodeMore(RootTree->left,k);
		if(RootTree->inf>k)
			printf("%3d",RootTree->inf);
		countNodeMore(RootTree->right,k);
	}
	
}
bool isIsomorphic(treeNode* n1, treeNode *n2)
{

if (n1 == NULL && n2 == NULL)
	return true;

if (n1 == NULL || n2 == NULL)
	return false;

if(!isIsomorphic(n1->left,n2->left)) return false;
if(!isIsomorphic(n1->right,n2->right)) return false;
return true;
}

//Ham tinh tong cac so le :
int sumOdd(treeNode *tree){
	if(tree==NULL) return 0;

	if((tree->inf) % 2!=0)
		a= a+ tree->inf;
	sumOdd(tree->left);
	sumOdd(tree->right);
	return a;
}
treeNode *mirrow(treeNode *nodePtr){
	treeNode *tmp;
	tmp=(treeNode*)malloc(sizeof(treeNode));
  if(nodePtr!=NULL) {
    tmp= nodePtr->left;
    nodePtr->left = nodePtr->right;
    nodePtr->right = tmp;
		
		mirrow(nodePtr->left);
		mirrow(nodePtr->right);
  }
  else return NULL;
  return nodePtr;
}

