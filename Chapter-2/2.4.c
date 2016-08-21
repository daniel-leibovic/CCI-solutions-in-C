#include "linkedlist.h"
#include "stdlib.h"
#include "time.h"
#include "stdio.h"

void checkPartition(struct node *head, int partitionValue)
{
	while(head != NULL)
	{
		if(head->data >= partitionValue)
			break;
		head = head->next;
	}
	while(head != NULL)
	{
		if(head->data < partitionValue)
			printf("CHECKING PARTITION FAILED ON NODE %d\n", head->data);
		head = head->next;
	}
	printf("PARTITION CHECKED SUCCESS\n");
	return;
}


int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage: %s (int less than 1000)partitionValue\n", argv[0]);
		exit(-1);
	}
	int partitionValue = atoi(argv[1]);
	int len = 20; //length of the list we will partition

/////////////////////////////////////////////////////////////	
///create linked list of 20 nodes, with random data values///
	struct node *head = createSingleLinkedList(len); //linked list with vals [0, 1, ..., 19]
	struct node *p1 = head;

	//change all data values to random between 0-999
	srand(time(NULL));
	while(1)
	{
		p1->data = rand() % 1000;
		if(p1->next == NULL)
			break; //p1 now points to last node
		p1 = p1->next;
	}
////////////////////////////////////////////////////////////
///Go through the entire list once, moving all nodes exceeding *value* to the tail///
	struct node *tail = p1; //mark the tail
	p1 = head; //set p1 to head
	struct node *previous = malloc(sizeof(*previous));
	previous->next = head; //for later

	for(int i = 0; i < len; i++) //go through the whole list once
	{
		if(p1->data >= partitionValue)
		{
			if(p1 == head){
				head = head->next;
				previous->next = head;
			} else {
				previous->next = p1->next; //take p1 out of the list
			}
			tail->next = p1; //place it at the very tail
			tail = p1; //update tail to point to the last node
			tail->next = NULL; //it is now at the tail

			p1 = previous->next; //move on to the next unread node
		} else {
			previous = p1;
			p1 = p1->next; //move on to the next unread node
		}
	}
	printf("printed list:\n");
	printLinkedList(head);
	printf("\npartitionValue: %d\n", partitionValue);
	checkPartition(head, partitionValue);
	freeLinkedList(head);
	return 0;
}