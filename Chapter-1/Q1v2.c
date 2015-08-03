//Using a bit array:
//(see Q1.c for less space efficient method, with an array)

#include <stdio.h>
 
void isUnique(char* string)
{
	int bitArray = 0;
	char val, i, c;
	//char val, i, c;
	for(i = 0; c = string[i]; i++) {
		//this gives the 0 - 26 value of the lowercase character
		val = c - 'a';
		
		//compares existing 32-bit bitArray to a 32-bit array of 0s, with the *val*th position set to 1
		//if any of the 32 columns between the two rows share a '1' value, there is collision
		if(bitArray & (1 << val)) {
			printf("%s is not unique, collision on %c, at bitArray[%d].\n", string, c, val);
			return;
		}
		
		//sets the bitArray[val] value to 1, indicating that the *val* character has been touched
		printf("printing 1 at bitArray[%d]", val);
		bitArray |= (1 << val);
		printf(", bitArray = %d \n", bitArray);
	}
	
	printf("unique!");
 
}
 
int main(void) {
	//set your string here
	isUnique("hello");
	return 0;
}
