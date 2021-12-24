#include "header.h"
#include "functions.h"
// Main functions
int main()
{
	int selection;
	
	printf("Please select the following : \n");
	printf("1. Inventory Creation \n");
	printf("2. Update vaccine quantities \n");
	printf("3. Search vaccine and its available quantity by using vaccine code\n");
	printf("4. Produce a list of all vaccines and their distributed quantities\n\n");
	printf("Selection: ");
	scanf("%d", &selection);
	getchar();
	directory(selection);

	return 0;
}


