#include <stdio.h>
#include <string.h>


void reverse(char* string)
{
	int slen = strlen(string), i;
	char temp;
	
	//switch the 1st and last char in the string, the 2nd and 2nd-to-last, etc...
	for(i = 0; 2*i < slen; i++) {
	  //retain copy of i-th char
		temp = string[i];
		//replace the i-th char with the i-th-to-last char
		string[i] = string[slen - i - 1];
		string[slen - i - 1] = temp;
	}
	
	printf("reversed string: %s\n", string);
}

int main(void) {
  //set your desired string here
	char string[] = "hello";
	reverse(string);
	printf("reversed original string: %s\n", string);
	return 0;
}
