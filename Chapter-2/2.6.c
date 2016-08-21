#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "time.h"
#include "linkedlist.h"

struct node *createCircularLinkedList(int len)
{
	struct node *head = createSingleLinkedList(len);
	struct node *tail = head;
	//place tail at tail
	for (int i = 0; i < len - 1; ++i)
		tail = tail->next;
	srand(time(NULL));
	//place head at some random node in the list
	for (int i = 0; i < (rand() % len); ++i)
		head = head->next;
	//make it circular!
	tail->next = head;
}

int main(int argc, char *argv[])
{
	int len = 20;
	struct node *head = createCircularLinkedList(len);
	//move slow one, fast two
	struct node *slow = head->next;
	struct node *fast = head->next->next;
	while(slow != fast)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	//slow and fast have collided, and are LOOP - k away from circleStart
	slow = head;
	while(slow != fast)
	{
		//they will collide at circleStart
		slow = slow->next;
		fast = fast->next;
		len++;
	}
	printf("The collision point is at node %d!\n", fast->data );
	printf("Here is what the list looks like: (with an extra 3 after circle)\n");
	for (int i = 0; i < len + 3; ++i, head = head->next)
	{
		printf("|%d|->", head->data);
	}
	return 0;
}