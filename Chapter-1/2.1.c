#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include "linkedlist.h"

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("usage: %s (int)length_of_list\n", argv[0]);
	}
	struct node *root = createSingleLinkedList(atoi(argv[1]));
	printLinkedList(root);
	freeLinkedList(root);
	return 0;
}