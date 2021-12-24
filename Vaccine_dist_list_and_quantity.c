#include "header.h"
#include "functions.h"

void list()
{
	DIST list[100];
	FILE* file;
	int dist_amount, loop1, loop2, str_len;
	char temp[20];

	//check for distribution dist_amount.txt
	file = fopen("dist_amount.txt", "r");
	if (file == NULL)
	{
		printf("Error getting Distribution amount");
		return;
	}
	else
	{
		fscanf(file, "%d ", &dist_amount);
		fclose(file);
	}

	//get data from dist.txt
	file = fopen("dist.txt", "r");

	if (file == NULL)
	{
		printf("Error getting data from dist.txt");
		return;
	}
	else
	{
		
		//get data from vaccine.txt
		for (loop1 = 0; loop1 < dist_amount; loop1++)
		{
			fscanf(file, "%d", &str_len);
			fgets(list[loop1].vac_name, str_len + 1, file);
			fscanf(file, "%d", &str_len);
			fgets(list[loop1].vac_code, str_len + 1, file);
			fscanf(file, "%f", &list[loop1].quantity_distributed);
		}

		fclose(file);
	}


	//bubble sort
	for (loop1 = 0; loop1 < dist_amount - 1; loop1++)
	{
		for (loop2 = 0; loop2 < dist_amount - loop1 - 1; loop2++)
		{
			if (list[loop2].quantity_distributed < list[loop2 + 1].quantity_distributed)
			{
				strcpy(temp, list[loop2].vac_name);
				strcpy(list[loop2].vac_name, list[loop2 + 1].vac_name);
				strcpy(list[loop2 + 1].vac_name, temp);
				//swap using pointers
				swap(&list[loop2].vac_code, &list[loop2 + 1].vac_code);
				swap(&list[loop2].quantity_distributed, &list[loop2 + 1].quantity_distributed);
			}
		}
	}

	// print the result
	printf("-------------------------------------------------------------\n");
	printf("Vaccine name\t\t");
	printf("Vaccine code\t");
	printf("Distributed amount\n");
	printf("-------------------------------------------------------------\n");
	for (loop1 = 0; loop1 < dist_amount; loop1++)
	{

		if (strlen(list[loop1].vac_name) < 8) // length check for tab usage (tidy)
		{
			printf("%s\t\t\t", list[loop1].vac_name);
		}
		else
		{
			printf("%s\t\t", list[loop1].vac_name);
		}
		printf("%s\t\t", list[loop1].vac_code);
		printf("%.2f\n", list[loop1].quantity_distributed);
	}

	return;

}