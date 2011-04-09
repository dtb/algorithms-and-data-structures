#include <stdlib.h>
#include <stdio.h>

typedef struct node node;

struct node {
	node* next;
	int data;
};


node* create(int data) 
{
	node* head = (node*)malloc(sizeof(node));
	head->data = data;
	head->next = head;
	
	return head;
}

void insert(node* head, int data)
{
	node* tmp = head;
	while(tmp->next && tmp->next != head)
	{
		tmp = tmp->next;
	}
	
	tmp->next = create(data);
	tmp->next->next = head;
}

void printList(node* head)
{
	node* tmp = head;
	while(tmp->next && tmp->next != head)
	{
		printf("%d->", tmp->data);
		
		tmp = tmp->next;
	}
	printf("%d->(wrap)", tmp->data);
	printf("%d\n", tmp->next->data);
}

node* findEnd(node* head)
{
	node* tmp = head;
	while(tmp->next && tmp->next != head)
	{
		tmp = tmp->next;
	}
	
	return tmp;
}

void splitlist(node* orig, int firstB, node** listA, node** listB)
{
	node* tmp = orig;
	while(tmp->next && tmp->next->data != firstB)
	{
		tmp = tmp->next;
	}
	
	if(!tmp->next)
	{
		return;
	}
	
	*listB = tmp->next;
	findEnd(orig)->next = *listB;
	
	*listA = orig;
	tmp->next = *listA;
}
	
int main(int argc, char * argv[])
{
	node* list = create(5);
	
	insert(list, 2);
	insert(list, 7);
	insert(list, 10);
	insert(list, 3);
	insert(list, 9);
	
	printList(list);
	
	node* listA;
	node* listB;
	
	splitlist(list, 10, &listA, &listB);
	
	printList(listA);
	printList(listB);
	
	return 0;
}