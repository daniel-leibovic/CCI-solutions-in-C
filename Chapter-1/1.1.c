//Using an array:
//See Q1v2.c for a space efficient version using bit-array

#include <stdio.h>
#include <stdbool.h>
#include <string.h> 
// int isUnique(char* string)
// {
// 	char mask[32];
// 	//Rule of thumb: Never hardcode [data sizes]. 
// 	memset(mask, 0, sizeof(mask));

// }
bool isUnique(char* str){
    int i = 0;
    char mask[32];
    char c = 0;
    char maskSpot = 0; //to represent spots 0 - 31 of the mask

    memset(mask, 0, sizeof(mask));

 	while(c = str[i++]) {
 		//check if current letter has already been consumed, if bit (0-255) is flipped in bitArray
 		
 		//which maskSpot does the character belong to (maskSpots 0 - 31 represent bits 0 - 255)
 		maskSpot = c / 8; 
 		if ((mask[maskSpot] & (1 << (c % 8))) != 0)
 			return false;
 		else 
 			mask[maskSpot] |= (1 << (c % 8));
 	}

 	//all characters are unique. null strings also return 1.
 	return true;
    
}

int main(int argc, char *argv[]) {
	if(argc != 2) {
		printf("Invalid arguments\n");
		printf("Usage: %s test_string\n", argv[0]);
		return 1;
	}
	bool testret = isUnique(argv[1]);
	if(testret == true)
		printf("\"%s\" has all unique characters!\n", argv[1]);
	else
		printf("\"%s\" does not have all unique characters!\n", argv[1]);
	return 0;
}
