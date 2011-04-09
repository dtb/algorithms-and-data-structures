#include <stdlib.h>
#include <stdio.h>

typedef struct node node;
typedef enum e_bool {TRUE = 1, FALSE = 0} bool;

struct node 
{
	node* left;
	node* right;
	int data;
};

node* createNode(int data)
{
	node* newNode = malloc(sizeof(node));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;
	
	return newNode;
}

void insert(node* tree, int data)
{
	if(data < tree->data)
	{	
		if(tree->left == NULL)
			tree->left = createNode(data);
		else
			insert(tree->left, data);
	}
	else
	{
		if(tree->right == NULL)
			tree->right = createNode(data);
		else
			insert(tree->right, data);
	}
}

void display(node* tree, int nSpaces, char* lead)
{
	if(tree == NULL)
		return;
		
	display(tree->right, nSpaces + 3, "/");
	
	int i;
	for(i = 0; i < nSpaces - 1; i++)
	{
		printf(" ");
	}
	printf("%s", lead);
	
	printf("%d\n", tree->data);
	
	display(tree->left, nSpaces + 3, "\\");
}

node* find(node* tree, int value, int nComps)
{
	if(tree == NULL)
	{
		printf("%d\n", nComps);
		return NULL;
	}

	if(value == tree->data)
	{
		printf("%d\n", nComps);
		return tree;
	}
	else if(value < tree->data)
	{
		return find(tree->left, value, ++nComps);
	}
	else
	{
		return find(tree->right, value, ++nComps);
	}
}

bool contains(node* tree, int value)
{
	return find(tree, value, 0) != NULL;
}

void delete(node* tree, int value)
{
	
}
int main(int argc, char** argv)
{
	node* tree = createNode(7);
	
	insert(tree, 3);
	insert(tree, 2);
	insert(tree, 8);
	insert(tree, 7);
	insert(tree, 6);
	insert(tree, 10);
	insert(tree, 4);
	insert(tree, 9);
	insert(tree, 13);
	insert(tree, 19);
	insert(tree, 12);
	
	display(tree, 0, "-");
	
	if(contains(tree, 3))
		printf("yes\n");
	else
		printf("no\n");
		
	if(contains(tree, 5))
		printf("no\n");
	else
		printf("yes\n");
		
	if(contains(tree, 9000))
		printf("no\n");
	else
		printf("yes\n");
		
	if(contains(tree, 10))
		printf("yes\n");
	else
		printf("no\n");
		
	if(contains(tree, 6))
		printf("yes\n");
	else
		printf("no\n");
	
	if(contains(tree, 9))
		printf("yes\n");
	else
		printf("no\n");
		
	if(contains(tree, 74))
		printf("no\n");
	else
		printf("yes\n");
	
	
	return 0;
}