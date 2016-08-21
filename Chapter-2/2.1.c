	//this has seg faults not fixed yet

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include "linkedlist.h"

int main(int argc, char *argv[])
{
	//creates a linked list of length 10,000 with random data values ranging 1 - 1000, then removes duplicates
	//create list, then for each node i with value Ki, run through all nodes after i, removing nodes with value Ki
	//this takes n^2 time, but avoids using temporary buffer (and i don't want to write a hash implementation in C)
	if(argc != 1)
	{
		printf("usage: %s\n", argv[0]);
		return 1;
	}
	struct node *root = createSingleLinkedList(10000);
	// printLinkedList(root);

	struct node *iterator = root;
	struct node *runner;
	struct node *temp;
	int val;
	int count = 1;

	while(iterator != NULL)
	{
		val = iterator->data;
		runner = iterator->next;
		while(runner != NULL) //run until end of list
		{
			if(runner->data == val) //found a duplicate
			{
				//erase data of current runner node by making it equivalent to runner->next
				//then erase runner->next
				temp = runner->next;
				if(temp == NULL)
				{
					free(runner);
					runner = NULL;
					break;
				}
				runner->data = temp->data;
				runner->next = temp->next;
				free(temp);
			} else {
				runner = runner->next;
			}
		}
		iterator = iterator->next;
	}
	freeLinkedList(root);
	return 0;
}