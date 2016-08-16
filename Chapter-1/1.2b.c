#include <stdio.h>
#include <string.h>


void reverse(char* string)
{
	char *front;
	char *back;
	char buffer;

	front = string;
	back = string + strlen(string) - 1;

	//switch letters at positions front and back until the pointers cross at middle
	while(front < back)
	{
		buffer = *front;
		*front++ = *back;
		*back-- = buffer;
	}
}

int main(int argc, char *argv[]) {
	if(argc != 2)
	{
		printf("Invalid arguments.\n");
		printf("Usage: %s some_string\n", argv[0]);
	}
	char *string = argv[1];
	reverse(string);
	printf("%s\n", string);
	return 0;
}
