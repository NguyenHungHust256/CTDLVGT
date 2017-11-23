// C program to check whether a given Binary Tree is full or not
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*  Tree node structure */
struct Node
{
    int key;
    struct Node *left, *right;
};

/* Helper function that allocates a new node with the
   given key and NULL left and right pointer. */
struct Node *newNode(char k)
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->key = k;
    node->right = node->left = NULL;
    return node;
}
int height(Node *tree){
	if(tree==NULL) return 0;
	int lh=height(tree->left);
	int rh=height(tree->right);
	return 1+(lh>rh?lh:rh);
}
/* This function tests if a binary tree is a full binary tree. */
bool isBalancedTree (struct Node* tree)
{
  if(tree==NULL) return true;
	if(abs(height(tree->left)-height(tree->right))>1) 
		return false;

	if(!(isBalancedTree(tree->left))) return false;
	if(!(isBalancedTree(tree->right))) return false;
	return true;
}
//

// Driver Program
int main()
{
    struct Node* root = NULL;
    root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);

   
    root->left->left = newNode(50);
    


    root->left->left->left = newNode(80);
    root->left->left->right = newNode(90);
//    root->left->right->left = newNode(80);
//    root->left->right->right = newNode(90);
//    root->right->left->left = newNode(80);
//    root->right->left->right = newNode(90);
//    root->right->right->left = newNode(80);
//    root->right->right->right = newNode(90);

    if (isBalancedTree(root))
        printf("The Binary Tree is balanced Tree\n");
    else
        printf("The Binary Tree is not balanced Tree\n");

    return(0);
}
