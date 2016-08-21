#include "stdio.h"
#include "stdlib.h"
#include "../Chapter-2/linkedlist.h"
#include "string.h"

int main(int argc, char *argv[])
{
	char op[10];
	int data;
	struct node *pushStack = NULL;
	struct node *popStack = NULL;

	printf("Usage: \"push\" some_int ||OR|| \"pop\"\n");
	while(1)
	{
		scanf("%9s", op);
		if(strncmp(op, "push", 4) == 0)
		{
			scanf("%d", &data);
			if(pushStack == NULL)
			{
				if(popStack != NULL) //we were popping from the "queue" so we need to switch to pushing mode
				{
					while(popStack != NULL) //transfer all from popstack to pushstack
					{
						push(&pushStack, pop(&popStack));
					}
				}
			}
			push(&pushStack, data);
		} else if(strncmp(op, "pop", 3) == 0)
		{
			if(popStack == NULL)
			{
				if(pushStack != NULL) //we were pushing to "queue" so we need to switch to pop mode
				{
					while(pushStack != NULL) // transfer all from pushStack to popStack
					{
						push(&popStack, pop(&pushStack));
					}
				}
			}
			if(popStack == NULL) //could still be null if there was nothing to transfer from pushstack
				printf("Queue is empty. You have nothing to pop.\n");
			else
				printf("Popped queue: %d\n", pop(&popStack));
		} else {
			printf("Invalid usage.\n");
			printf("Usage: \"push\" some_int ||OR|| \"pop\"\n");
		}
	}
	return 0;
}