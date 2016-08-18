#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include "linkedlist.h"

void push(struct node **headRef, int data)
{
	struct node *newNode = malloc(sizeof(*newNode));
	if(!newNode)
	{
		perror("error: ");
		exit(-1);
	}
	newNode->data = data;
	newNode->next = *headRef;
	*headRef = newNode;
}

struct node* createSingleLinkedList(int len)
{
	if(len == 0)
		return NULL;

	struct node *head = NULL;

	for(int i = 0; i < len; i++)
	{
		push(&head, len-i-1);
	}
	return head;
}

void printLinkedList(struct node *root)
{
	while(root != NULL)
	{
		printf("|%d|->", root->data);
		root = root->next;
	}
	printf("\n");
}

void freeLinkedList(struct node *root)
{
	struct node *temp;
	while((temp = root) != NULL)
	{
		root = root->next;
		free(temp);
	}
}