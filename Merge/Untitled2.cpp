#include <stdio.h>
#include <conio.h>

typedef struct TreeNode
{
	float key;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

TreeNode* makeTreeNode(float value){
	TreeNode* newNode ;
	newNode=(TreeNode*)malloc(sizeof(TreeNode));
	if(newNode==NULL)
		return NULL;
	newNode->key = value;
	newNode->left = NULL;
	newNode->right = NULL
	return newNode;
}

TreeNode* findMin(TreeNode* Node){
	TreeNode* p;
	p=Node;
	while(p!=NULL)
		p=p->left;
	return p;
}

TreeNode* findMax(TreeNode* Node)
{
	TreeNode* p;
	p = Node;
	while(p!=NULL)
		p=p->right;
  return p;
}

void printInorder(TreeNode* Node){
	if(Node!=NULL){
		printInorder(Node->left);
		printf("%3d",Node->key);
		printInorder(Node->right);
	}
}


TreeNode* search(TreeNode* node, float target){
	if(node!=NULL)
	{
		if(target<node->key)
		{
			node = search(node->left, target);
		}
		else if(target>node->key)
		{
			node = search(node->right, target);
		}
	}
	return node;
}

TreeNode* insert(TreeNode* node, float item)
{
	if(node == NULL)
	{
		node = makeTreeNode(item);
	}
	else if (item<node->key){
		node->left = insert(node->left, item);
	}
	else if (item > node->key)
	{
		node->right = insert(node->right, item);
	}
	return node;
}

TreeNode* deleteNode(TreeNode* Tree, float x){
	TreeNode* tmp;
	if(T==NULL)
		return NULL;
	else if(x<Tree->key){
		Tree->left = deleteNode(Tree->left,x);
	else if(x>Tree->key){
		Tree->right = deleteNode(Tree->right, x);
	}
  else
  {
  	if(Tree->left && Tree->right){
  		tmp = findMin(Tree->right);
  		Tree->key = tmp->key ;
  		Tree->right = deleteNode(Tree->right, Tree->key);
		}
		else{
			tmp = Tree;
			if(Tree->left == NULL)
				Tree = Tree->right;
			else if(Tree->right==NULL)
				Tree = Tree->left;
		}
	}
	free(tmp);
	return Tree;
	
	}
}
