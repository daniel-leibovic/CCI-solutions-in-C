#include <string.h>
#include <stdio.h>
#include <math.h>

void compress(char *str)
{
	int len = strlen(str);
	char temp[len];
	char c;
	int count;
	int i = 0;
	int j = 0;

	while(str[i])
	{
		c = str[i]; //get char from str
		count = 1; 
		while(str[++i] == c) //count adjacent occurences
			count++;
		temp[j++] = c; //writing first character will always be in range
		if(j == len) //if writing the digit will exceed range, return
			return;
		sprintf(temp + j, "%d", count);
		j += floor(log10(count)) + 1; //fails if count==0, which never happens
	}
	temp[j] = '\0'; //null terminate
	strncpy(str, temp, len);
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage: %s some_string\n", argv[0]);
	}
	compress(argv[1]);
	printf("compressed version: %s\n", argv[1]);
	return 0;
}