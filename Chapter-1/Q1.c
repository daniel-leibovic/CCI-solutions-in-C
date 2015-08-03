//Using an array
#include <stdio.h>
 
int isUnique(char* string)
{
	//create array representing each of 256 possible ASCII chars, initialize all to 0
	int ASCII[256] = {0};
	int i;
	char c;
	
	//place each char in your string into its unique place in ASCII array
	//could optimize space by making ASCII array value type boolean
	for(i = 0; c = string[i]; i++) {
		printf("decimal value of %c: %d \n", c, c);
		
		//this character has been encountered before, and placed in ASCII array
		if(ASCII[c]) {
			printf("not unique!, ASCII[%d] = %d", c, c);
			return;
		}
		
		//set ASCII array value to char value
		ASCII[c] = c;
	}
	printf("unique!");
}
int main(void) {
	isUnique("0hello");
	return 0;
}
