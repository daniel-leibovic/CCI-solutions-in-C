#ifndef _linkedlist_h
#define _linkedlist_h

struct node
{
	struct node *next;
	int data;
};

void freeLinkedList(struct node *root);
void printLinkedList(struct node *root);
struct node* createSingleLinkedList(int len);
void push(struct node **headRef, int data);

#endif