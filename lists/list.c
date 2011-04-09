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

void insert(node* head, int data)
{
	while(head->next){
		head = head->next;
	}
	
	head->next = create(data);
}

void deleteFirst(node** head, int delete)
{
	if((*head)->data == delete)
	{
		node* next = (*head)->next;
		*head = next;
	}
	else
	{
		node* tmp = *head;
		while(tmp->next && tmp->next->data != delete)
		{
			tmp = tmp->next;
		}
		if(tmp->next)
		{
			tmp->next = tmp->next->next;
		}
	}
}

void printList(node* head)
{
	if(!head)
	{
		printf("(empty)");
		return;
	}
		
	while(head->next)
	{
		printf("%d->", head->data);
		
		head = head->next;
	}
	printf("%d\n", head->data);
}
	
int main(int argc, char * argv[])
{
	node* list = create(5);
	
	insert(list, 2);
	insert(list, 3);
	insert(list, 9);
	printList(list);
	
	deleteFirst(&list, 2);
	printList(list);
	
	deleteFirst(&list, 5);
	printList(list);
	
	deleteFirst(&list, 2);
	printList(list);
	
	deleteFirst(&list, 3);
	printList(list);
	
	deleteFirst(&list, 9);
	printList(list);
	
	return 0;
}