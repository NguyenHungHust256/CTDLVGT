#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Tnode{
	int data;
	struct Tnode *left;
	struct Tnode *right;
};

typedef struct Tnode treeNode;

treeNode *makeTreeNode(int x);
treeNode *RandomInsert(treeNode *tree, int x);
void freeTree(treeNode *tree);
void printPreorder(treeNode *tree);
void printPostorder(treeNode *tree);
void printInorder(treeNode *tree);
int countNodes(treeNode *tree);
int depth(treeNode *tree);

int main(){
	int n;
	int x;
	treeNode *tree=NULL;
	printf("Ban muon nhap vao may node: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("\nNode thu %d la: ", i+1);
		scanf("%d",&x);
		tree = RandomInsert(tree,x);
	}
}

treeNode *makeTreeNode(int x){
	treeNode *p = (treeNode*)malloc(sizeof(treeNode));
	if(p==NULL)
		return NULL;
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

int countNodes(treeNode *tree)
{
	if(tree==NULL) return 0;
	int ld = countNodes(tree->left);
	int rd = countNodes(tree->right);
	return 1+ld+rd;
}

int depth(treeNode *tree)
{
	if(tree==NULL) return 0;
	int ld = depth(tree->left);
	int rd = depth(tree->right);
	return 1+(ld>rd?ld:rd);
}

void freeTree(treeNode *tree)
{
	if(tree==NULL) return ;
	freeTree(tree->left);
	freeTree(tree->right);
	free(tree);
	return ;
}

void printPreorder(treeNode *tree)
{
	if(tree!=NULL){
		printf("%3d",tree->data);
		printPreorder(tree->left);
		printPreorder(tree->right);
	}
}

void printInorder(treeNode *tree)
{
	if(tree!=NULL)
	{
		printInorder(tree->left);
		printf("%3d",tree->data);
		printInorder(tree->right);
	}
}

void printPostorder(treeNode *tree)
{
	if(tree!=NULL)
	{
		printPostorder(tree->left);
		printPostorder(tree->right);
		printf("%3d", tree->data);
	}
}

treeNode *RandomInsert(treeNode *tree, int x)
{
	treeNode *newNode, *p;
	newNode = makeTreeNode(x);
	if(tree==NULL) return newNode;
	if(rand()%2)
	{
		p=tree;
		while(p->left!=NULL)
		{
			p=p->left;
		}
		p->left=newNode;
		printf("Node %d la nut trai cua %d \n", x, p->data);
	}
	else 
	{
		p=tree;
		while(p->right!=NULL)
		{
			p=p->right;
		}
		p->right=newNode;
		printf("Node %d la nut trai cua %d \n",x,p->data);
	}
	return tree;
}
