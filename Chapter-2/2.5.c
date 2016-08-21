#include "stdio.h"
#include "time.h"
#include "math.h"
#include "linkedlist.h"
#include "stdlib.h"

int forwardListToNumber(struct node *head)
{
	int returnValue = 0;
	int len = findLengthLinkedList(head);
	//find the decimal place value of top node
	//eg: for 2596, len - 1 = 3, thus 1,000 
	//eg: for 9, len - 1 = 0, thus 1
	int decimalValue = 1;
	for(int i = 0; i < len - 1; i++)
	{
		decimalValue *= 10;
	}

	while(head != NULL)
	{
		returnValue += (decimalValue * head->data);
		head = head->next;
		decimalValue /= 10;
	}
	return returnValue;
}

int backwardListToNumber(struct node *head)
{
	int returnValue = 0;
	int decimalValue = 1;
	while(head != NULL)
	{
		returnValue += (decimalValue * head->data);
		head = head->next;
		decimalValue *= 10;
	}
	return returnValue;
}

int main(int argc, char *argv[])
{
	//backwardListToNumber
		//runner to count # decimal places (d)
		//for each node value x in position k, x*10^d-k
	//add
	if(argc != 1)
	{
		printf("Usage: %s\n", argv[0]);
		return 1;
	}

	//create two linked lists with lengths between 1 - 10, then modify data to have single digit values
	int len = 10;
	srand(time(NULL));
	struct node *list1 = createSingleLinkedList(rand()%len);
	struct node *list2 = createSingleLinkedList(rand()%len);
	setListValuesUnder(list1, 10);
	setListValuesUnder(list2, 10);

	int val1 = backwardListToNumber(list1);
	int val2 = backwardListToNumber(list2);

	printf("=== BACKWARDS ===\n");
	printf("We added your two lists %d + %d = %d\n", val1, val2, val1 + val2);
	printf("Here is what your lists look like:\n");
	printf("=== LIST 1 ===\n");
	printLinkedList(list1);
	printf("=== LIST 2 ===\n");
	printLinkedList(list2);

	val1 = forwardListToNumber(list1);
	val2 = forwardListToNumber(list2);
	printf("\n\n=== NOW FORWARDS ===\n");
	printf("We added your two lists %d + %d = %d\n", val1, val2, val1 + val2);
	printf("Here is what your lists look like:\n");
	printf("=== LIST 1 ===\n");
	printLinkedList(list1);
	printf("=== LIST 2 ===\n");
	printLinkedList(list2);	
}