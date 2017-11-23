#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct TreeNodeRec
{
	float key;
	struct TreeNodeRec *left;
	struct TreeNodeRec *right;
};
typedef struct TreeNodeRec TreeNode;

TreeNode* makeTreeNode(float x);
TreeNode* insert(TreeNode *node, float x);
TreeNode* search(TreeNode *node, float x);
TreeNode* search(TreeNode *node, float x);

void printPreorder(TreeNode *node);
void printInorder(TreeNode* node);
void printPostorder(TreeNode* node);

int main(){
	
}

TreeNode* makeTreeNode(float x){
	TreeNode* p;
	p=(TreeNode*)malloc(sizeof(TreeNode));
	if(p==NULL)
		return NULL;
	p->key = x;
	p->left =NULL;
	p->right = NULL;
	return p;
}

TreeNode* find_min(TreeNode *T)
{
	if(T==NULL)
		return NULL;
	if(T->left==NULL)
		return T;
	else 
		return(find_min(T->left));
}

TreeNode* find_max(TreeNode* T)
{
	if(T!=NULL)
	{
		while(T->right!=NULL)
			T=T->right;
	}
	return T;
}

void printInorder(TreeNode* node){
	if(node!=NULL){
		printInorder(node->left);
		printf("%3d",node->key);
		printInorder(node->right);
	}
}

void printPreorder(TreeNode* node){
	if(node!=NULL){
		printf("%3d",node->key);
		printPreorder(node->left);
		printPreorder(node->right);
	}
}

void printPostorder(TreeNode* node){
	if(node!=NULL){
		printPostorder(node->left);
		printPostorder(node->right);
		printf("%3d", node->key);
	}
}

TreeNode* search(TreeNode* node, float target)
{
	if(node!=NULL)
	{
		if(target < node->key)
		{
			node = search(node->left,target);
		}
		else if(target>node->key)
		{
			node = search(node->right,target);
		}
		return node;
	}
}

TreeNode* insert(TreeNode *node, float x){
	if(node==NULL)
	{
		node = makeTreeNode(x);
	}
	else if(x<node->key)
	{
		node->left = insert(node->left,x);
	}
	else if(x>node->key){
		node->right = insert(node->right,x);
	}
	return node;
}
