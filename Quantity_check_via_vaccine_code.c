#include "header.h"

void search()
{
	VAC list[10];
	FILE* file;
	char query[10];
	int vaccine_type, loop, str_len,search,result;




	printf("Vaccine enquires.\n\n");
	printf("Enter vaccine code:");
	scanf("%s", query);

	//check for vaccine amount from vaccine_type_amount.txt
	file = fopen("vaccine_type_amount.txt", "r");

	if (file == NULL)
	{
		printf("Error getting Vaccine type amount");
		return;
	}
	else
	{
		fscanf(file, "%d ", &vaccine_type);
		fclose(file);
	}


	//get data and search 
	file = fopen("vaccine.txt", "r");

	if (file == NULL)
		printf("Open file error");
	else
	{
		//get data from vaccine.txt
		for (loop = 0; loop < vaccine_type; loop++)
		{
			fscanf(file, "%d", &str_len);
			fgets(list[loop].vac_name, str_len + 1, file);
			fscanf(file, "%d", &str_len);
			fgets(list[loop].vac_code, str_len + 1, file);
			fscanf(file, "%d", &str_len);
			fgets(list[loop].ori_country, str_len + 1, file);
			fscanf(file, "%d", &list[loop].dos_req);
			fscanf(file, "%f", &list[loop].pop_cov);
			fscanf(file, "%f", &list[loop].quantity);
		}


		//Search and compare existing vaccine
		search = 0;
		while (search < vaccine_type)
		{
			result = strcmp(query, list[search].vac_code);

			if (result == 0)
			{
				break;
			}
			else
			{
				if (search == vaccine_type - 1) //Vaccine not in our system
				{
					printf("The vaccine is not within the system, please try again.\n");
					getchar();
					return;
				}
				else
					search++;
			}
		}
		getchar();
		fclose(file);
	}

	printf("\n#####Vaccine information#####\n\n");
	printf("Vaccine name:");
	printf("%s\n",list[search].vac_name);
	printf("Vaccine code:");
	printf("%s\n", list[search].vac_code);
	printf("Producing country:");
	printf("%s\n", list[search].ori_country);
	printf("Dosage required:");
	printf("%d\n", list[search].dos_req);
	printf("Population covered (%):");
	printf("%.2f\n", list[search].pop_cov);
	printf("Quantity (millions):");
	printf("%.2f\n", list[search].quantity);

	return;
}