#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

int kthToLast(struct node *head, int k)
{
	struct node *runner = head;
	struct node *kBehind; 
	for(int i = 0; i < k; i++)
		runner = runner->next;
	while(runner->next != NULL)
	{
		runner = runner->next;
		kBehind = kBehind->next;
	}
	return kBehind->data;
}

int main(int argc, char *argv[])
{
	int k = atoi(argv[1]);
	int len = 100;
	if(argc != 2 || k > len - 1 )
	{
		printf("usage: %s (int less than 100)k\n", argv[0]);
		return 1;
	}
	struct node *head = createSingleLinkedList(100);
	int retval = kthToLast(head, k);
	printf("the %dth to last element is %d.\n", k, retval);
	return 0;
}