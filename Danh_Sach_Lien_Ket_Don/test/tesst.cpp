#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tnode{
	char word[20];
	struct Tnode *left;
	struct Tnode *right;
}treeNode;

treeNode *makeTreeNode(char *word);
treeNode *RandomInsert(treeNode* tree,char *word);
void freeTree(treeNode *tree);
void printPreorder(treeNode *tree);
void printPostorder(treeNode *tree);
void printInoder(treeNode *tree);
int countNodes (treeNode *tree);
int depth(treeNode *tree);

treeNode* makeTreeNode(char *word){
	treeNode *newNode;
	newNode =(treeNode*)malloc(sizeof(treeNode));
	if(newNode ==NULL){
		printf("Out of memory\n");
		exit(1);
	}
	else{
		newNode->left=NULL;
		newNode->right=NULL;
		strcpy(newNode->word,word);
	}
	return newNode;
}

int countNodes(treeNode *tree){
	if(tree==NULL) return 0;
	else{
		int ld=countNodes(tree->left);
		int rd=countNodes(tree->right);
		return 1+rd+ld;
	}
}

int depth(treeNode *tree){
	if(tree==NULL) return 0;
	int ld=depth(tree->left);
	int rd=depth(tree->right);
	return 1+(ld>rd ? ld:rd);
}

void freeTree(treeNode *tree)
{
	if(tree==NULL) return ;
	freeTree(tree->left);
	freeTree(tree->right);
	free(tree);
	return;
}

//in ra theo thu tu truoc.
void printPreorder(treeNode *tree){
	if(tree!=NULL)
	{
		printf("%s\n",tree->word);
		printPreorder(tree->left);
		printPreorder(tree->right);
	}
}

//in ra theo thu tu giua
void printInorder(treeNode *tree){
	if(tree!=NULL)
	{
		printInorder(tree->left);
		printf("%s\n",tree->word);
		printInorder(tree->right);
	}
}

//in ra theo thu tu sau
void printPostorder(treeNode *tree){
	if(tree!=NULL){
		printPostorder(tree->left);
		printPostorder(tree->right);
		printf("%s\n",tree->word);
	}
}

// Gan ngau nhien nut noi vao cay
treeNode *RandomInsert(treeNode *tree,char *word){
	treeNode *newNode, *p;
	newNode = makeTreeNode(word);
	if(tree==NULL) return newNode;
	if(rand()%2==0){
		p=tree;
		while(p->left!=NULL) p=p->left;
		p->left=newNode;
		printf("Node %s la node con trai cua %s \n",word,p->word);
	}
	else {
		p=tree;
		while(p->right!=NULL) p=p->right;
		p->right =newNode;
		printf("Node %s la node con phai cua %s\n",word,p->word);
	}
	return tree;	
}
void t1(treeNode *tree){
	if(tree!=NULL){
		printf("%s",tree->word);
		t1(tree->left);
		t1(tree->right);
		printf("%s",tree->word);
	}
}
int main(){
	treeNode *randomTree=NULL;
	char word[20]="a";
	while(strcmp(word,"~")!=0)
	{
		printf("\nEnter item(~ to finish): ");
		scanf("%s",word);
		if(strcmp(word,"~")==0)
			printf("Cham dut nhap thong tin node...\n");
		else 
			randomTree= RandomInsert(randomTree,word);
	}
	
	printf("Thu tu: \n"); t1(randomTree);
//	printf("The tree in preorder:\n"); printPreorder(randomTree);
//	printf("The tree in postorder:\n"); printPostorder(randomTree);
//	printf("The tree in inorder:\n");  printInorder(randomTree);
	printf("The number of nodes is: %d\n",countNodes(randomTree));
	printf("The depth of the tree is: %d\n", depth(randomTree));
	freeTree(randomTree);
	getch(); return 0;
}
