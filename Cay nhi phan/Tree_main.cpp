#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Tnode{
	char word[20];
	struct Tnode *left;
	struct Tnode *right;
}treeNode;

treeNode* makeTreeNode(char *word);
treeNode *RandomInsert(treeNode *tree, char *word);
void freeTree(treeNode *tree);
void printPreorder(treeNode *tree);
void printPostorder(treeNode *tree);
void printInorder(treeNode *tree);
int countNodes(treeNode *tree);
int depth(treeNode *tree);

int main(){
	treeNode *randomTree=NULL;
	char word[20]="a";
	while(strcmp(word,"~")!=0){
		printf("\nBan muon ket thuc thi an ~");
		scanf("%s",word);
		if(strcmp(word,"~")==0) printf("\nEm di xa qua.Goodbye\n");
		else{
			randomTree=RandomInsert(randomTree,word);
		}
		
	}
	return 0;
}

treeNode *makeTreeNode(char *word){
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
		strcpy(p->word,word);
	}
	return p;
}

treeNode *RandomInsert(treeNode *tree, char *word){
	treeNode *newNode,*p;
	newNode = makeTreeNode(word);
	if(tree == NULL) return newNode;
	if(rand()%2==0){
		p=tree;
		while(p->left!=NULL) p=p->left;
		p->left=newNode;
		printf("Node %s la nut con trai cua %s \n",word,p->word);
	}
	else {
		p=tree;
		while(p->right!=NULL) p=p->right;
		p->right=newNode;
		printf("Node %s la Node phai cua %s\n",word,p->word);
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

void printPreoder(treeNode *tree){

}

void printInorder(treeNode *tree){
	printInorder(tree->left);
	printf("%3s", tree->word);
	printInorder(tree->right);
}

void printPostorder(treeNode *tree){
	printPostorder(tree->left);
	printPostorder(tree->right);
	printf("%3s",tree->word);
}
