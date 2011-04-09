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
	
	return head;
}

void insert(node** head, int data)
{
	if((*head)->data > data)
	{
		node* newhead = create(data);
		newhead->next = *head;
		*head = newhead;
	}
	else
	{
		node* next = (*head)->next;
		node* cur = (*head);
		
		while(next && next->data < data)
		{
			cur = next;
			next = cur->next;
		}
		
		cur->next = create(data);
		cur->next->next = next;
	}
	
	//head->next = create(data);
}

void printList(node* head)
{
	while(head->next)
	{
		printf("%d->", head->data);
		
		head = head->next;
	}
	printf("%d", head->data);
}
	
int main(int argc, char * argv[])
{
	node* list = create(5);
	
	insert(&list, 2);
	insert(&list, 3);
	insert(&list, 9);
	insert(&list, 5);
	insert(&list, 6);
	insert(&list, 31);
	insert(&list, 12);
	insert(&list, 39);
	
	printList(list);
	
	return 0;
}