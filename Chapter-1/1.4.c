int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Invalid arguments.\n");
		printf("Usage: %s some_string\n", argv[0]);
	}
	replaceSpaces(argv[1]);
	printf("%s\n", argv[1]);
	return 0;
}