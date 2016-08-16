//Daniel Leibovic, August 14, 2016

//Solution A to 1.2 in CTCI 5th edition 
//Two pointers: p1 stays at front, p2 goes to end. p2 prints and decrements until it hits p1.
 
#include <stdio.h>
#include <string.h>

void reverse(char* str)
{
	char *p1;
	char *p2;
	int len = strlen(str);

	if(len == 0) {
		printf("Your string was empty.\n");
	}

	p1 = str;
	p2 = str + len - 1; //p2 points to the last char of the string

	//decrement backwards through non-empty string, printing from p2
	while(1)
	{
		printf("%c", *p2);
		if(p1 == p2--)
			break;

	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Invalid arguments.\n");
		printf("Usage: %s some_string\n", argv[0]);
		return 1;
	}

	reverse(argv[1]);
	return 0;
}