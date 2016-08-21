#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include "linkedlist.h"
#include "time.h"
#include "math.h"

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

int pop(struct node**headRef)
{
	int retVal = (*headRef)->data;
	struct node *temp = *headRef;
	*headRef = (*headRef)->next;
	free(temp);
	return retVal;
}

void setListValuesUnder(struct node *head, int max)
{
	while(head != NULL)
	{
		head->data = rand() % max;
		head = head->next;
	}
	
}
int findLengthLinkedList(struct node *head)
{
	int len = 0;
	while(head != NULL)
	{
		len++;
		head = head->next;
	}
	return len;
}

struct node* createSingleLinkedList(int len)
{
	srand(time(NULL));
	if(len == 0)
		return NULL;

	struct node *head = NULL;

	for(int i = 0; i < len; i++)
	{
		push(&head, rand() % 1000);
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