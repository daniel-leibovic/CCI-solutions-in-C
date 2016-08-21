#include "stdlib.h"
#include "stdio.h"
#include "string.h"

struct stack
{
	int head; //array index of beginning of stack
	int tail; //index of last item
	int max; //index of last slot assigned to this stack (max+1 is head of next array, or exceeds total array len)
	int len; //tail - head + 1
	struct array *array;
};

struct array
{
	char *head;
	int len;
};

char *growArray(struct stack *stack)
{
	int newArrayLen = stack->array->len + stack->len;
	char *newArray = malloc(sizeof(*newArray) * newArrayLen);
	memset(newArray, 0, sizeof(*newArray) * newArrayLen);

	int stackHead = stack->head;
	int i = 0;
	//copy until you reach beginning of the growing stack
	for(; i < stackHead; i++)
		newArray[i] = array[i];
	//copy the growing stack for existing values
	int stackTail = stack->tail;
	for(; i <= stackTail; i++)
		newArray[i] = array[i];
	//jump past the empty section of growing array, to the beginning of next stack
	for(int j = i + stack->len + 1; i < *arrayLen; i++, j++)
		newArray[j] = array[i];
	
	//update values
	*arrayLen = newArrayLen;
	stack->len *= 2;
	stack->max = stack->head + stack->len - 1;
	free(array);
	return newArray;
}

char *push(struct stack *stack, int data, char **array, int *arrayLen)
{
	if(stack->tail == stack->max)
		*array = growArray(stack, *array, arrayLen);
	*array[++stack->tail] = data;
	return *array;
}

void printArray(char *array, int arrayLen)
{
	for (int i = 0; i < arrayLen; ++i)
	{
		printf("|%d|->", array[i]);
	}
}
int main(int argc, char *argv[])
{
	int arrayLen = 3;
	char *array = malloc(sizeof(*array) * arrayLen);
	memset(array, 0, arrayLen);

	struct stack *stackA = malloc(sizeof(*stackA));
	struct stack *stackB = malloc(sizeof(*stackB));
	struct stack *stackC = malloc(sizeof(*stackC));

	stackA->head = 0;
	stackA->tail = 0;
	stackA->max = 0;
	stackA->len = 1;

	stackB->head = 1;
	stackB->tail = 1;
	stackB->max = 1;
	stackB->len = 1;

	stackC->head = 2;
	stackC->tail = 2;
	stackC->max = 2;
	stackC->len = 1;

	array = push(stackA, 1, &array, &arrayLen);

	printf("===PRINTING ARRAY===\n");
	printArray(array, arrayLen);

	return 0;
}