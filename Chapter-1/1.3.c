#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
#define ALPHABET_SIZE 256
 
void strToArr(char* arr, char* str, int len) {
	unsigned char c;
	for(int i = 0; i < len; i++) {
		
		c = str[i];
		arr[c]++;
	}
	return;
}

bool subtractStrFromArr(char* arr, char* str, int len) {
	unsigned char c;
	for(int i = 0; i < len; i++) {
		c = str[i];
		if(--arr[c] < 0){
			printf("not permutations! in subtractStrFromArr\n");
			return false;
		};
	}

	printf("%d %d %d\n", arr['h'], arr['l'], arr['q']);
	return true ;
}

bool checkArr(char* arr, int len) {
	for(int i = 0; i < len; i++) {
		if(arr[i] != 0) {
			printf("not permutation! in checkArr\n");
			return false;
		}
	}
	return true;
}

int main(void) {
	printf("HERE FOR FIRST");
	char *str1 = "hello";
	char *str2 = "olleq";
	int len = strlen(str1);
 
	char arr[ALPHABET_SIZE] = {0};

	strToArr(arr, str1, len);
	
	printf("before subtractStrFromArr :: %d %d %d\n", arr['h'], arr['l'], arr['q']);
	
	if(!subtractStrFromArr(arr, str2, len)) return 0;

	if(!checkArr(arr, ALPHABET_SIZE)) return 0;

	printf("\"%s\" and \"%s\" are permutations!\n", str1, str2 );
	return 0;
}
 
