#include "stdio.h"
#include "stdlib.h"
struct node 
{
  struct node *left;
  struct node *right;
  int info;
};
//PADDING AND STRUCTURE are print functions
//TAKEN FROM USER NARUE ON https://www.daniweb.com/programming/software-development/threads/146112/printing-a-binary-tree
void padding ( char ch, int n )
{
  int i;
  for ( i = 0; i < n; i++ )
    putchar ( ch );
}

void structure ( struct node *root, int level )
{
  int i;
  if ( root == NULL ) {
    padding ( '\t', level );
    puts ( "~" );
  }
  else {
    structure ( root->right, level + 1 );
    padding ( '\t', level );
    printf ( "%d\n", root->info );
    structure ( root->left, level + 1 );
  }
}

struct node *buildBST(int *array, int start, int end)
{
	int mid = (end - start) / 2 + start;
	struct node *returnNode = malloc(sizeof(*returnNode));
	returnNode->info = array[mid];
	if((end - start) == 0) //we have one array item
	{
		returnNode->left = NULL;
		returnNode->right = NULL;
	} else if((end - start) == 1) //we have two array items
	{
		returnNode->left = NULL;
		returnNode->right = buildBST(array, end, end);
	} else {
		returnNode->left = buildBST(array, start, mid - 1);
		returnNode->right = buildBST(array, mid + 1, end);
	}
	return returnNode;
}



int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Usage: %s {int_num_elements}\n", argv[0] );
		return 1;
	}
	int len = atoi(argv[1]);
	int *array = malloc(sizeof(*array) * len);
	for(int i = 0; i < len; i++)
		array[i] = i;
	struct node *root = buildBST(array, 0, len - 1);
	structure(root, 0);
	free(array);
	return 0;
}