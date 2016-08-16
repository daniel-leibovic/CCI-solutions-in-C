#include <string.h>
#include <stdio.h>

int isAnagram(char *str1, char *str2)
{
	if(strlen(str1) != strlen(str2))
		return 0;
	char c;
	int i;
	int characterCount[256];
	memset(characterCount, 0, sizeof(characterCount));

	//increment characterCount index for each letter in str1
	for(i = 0; str1[i]; i++)
	{
		c = str1[i];
		characterCount[c]++;
	}
	//decrement characterCount index for each letter in str2
	for(i = 0; str2[i]; i++)
	{
		c = str2[i];
		if(--characterCount[c] < 0)
			return 0;
	}
	return 1;
}

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		printf("Invalid arguments.\n");
		printf("Usage: %s some_string1 some_string2\n", argv[0]);
		return 1;
	}
	if(isAnagram(argv[1], argv[2]))
		printf("|%s| and |%s| are anagrams indeed!\n", argv[1], argv[2]);
	else
		printf("|%s| and |%s| are NOT anagrams!\n", argv[1], argv[2]);
	return 0;
}