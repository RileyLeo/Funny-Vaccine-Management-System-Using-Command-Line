#include "header.h";

void update()
{
	VAC list[10];
	FILE* file;
	char query[10];
	int vaccine_type, selection = 3, str_len, loop, result, search, dist_amount;
	float vac_calc;

	printf("Update Vaccine amount.\n\n");
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
	{
		printf("Open file error");
		return;
	}
	else
	{
		//get data from vaccine.txt
		for(loop=0; loop<vaccine_type; loop++) 
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
				if (search  == vaccine_type - 1) //Vaccine not in our system
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


	// dist or retrive cheeck , int search now points to which to tweak
	while (selection != 1 && selection != 2)
	{
		printf("Choose an option 1. Distribution 2. Retrieval\n");
		printf("Option:");
		scanf("%d", &selection);

		if (selection == 1) //distribute
		{
			printf("Distributed quantity(mil):");
			scanf("%f", &vac_calc);
			list[search].quantity = list[search].quantity - vac_calc;

			//Input details into dist.txt
			file = fopen("dist.txt", "a");
			if (file == NULL)
				printf("Error updating dist.txt");
			else
			{
				str_len = strlen(list[search].vac_name);
				fprintf(file, "%d%s ", str_len, list[search].vac_name);
				str_len = strlen(list[search].vac_code);
				fprintf(file, "%d%s ", str_len, list[search].vac_code);
				fprintf(file, "%.2f\n", vac_calc);
				fclose(file);
			}

			//read current dist file amount
			file = fopen("dist_amount.txt", "r");
			if (file == NULL)
			{
				printf("Error getting dist type amount");
				return;
			}
			else
			{
				fscanf(file, "%d ", &dist_amount);
				dist_amount += 1;
				fclose(file);
			}

			//rewrite dist file amount
			file = fopen("dist_amount.txt", "w");
			if (file == NULL)
				printf("Error writing dist amount");
			else
			{
				fprintf(file, "%d", dist_amount);
				fclose(file);
			}
		}
		else if (selection == 2) //receive 
		{
			printf("Recieved quantity(mil):");
			scanf("%f", &vac_calc);
			list[search].quantity = list[search].quantity + vac_calc;
		}
		else
			printf("Invalid selection, try again.");
	}

	//update vacine.txt

	file = fopen("vaccine.txt", "w");
	if (file == NULL)
	{
		printf("Error getting vaccine.txt");
		return;
	}
	else
	{
		for (loop = 0; loop < vaccine_type; loop++)
		{
			//vacc name
			str_len = strlen(list[loop].vac_name);
			fprintf(file, "%d%s ", str_len, list[loop].vac_name);
			//vac code
			str_len = strlen(list[loop].vac_code);
			fprintf(file, "%d%s ", str_len, list[loop].vac_code);
			// vac country
			str_len = strlen(list[loop].ori_country);
			fprintf(file, "%d%s ", str_len, list[loop].ori_country);
			//dos req
			fprintf(file, "%d ", list[loop].dos_req);
			//pop_cov
			fprintf(file, "%.2f ", list[loop].pop_cov);
			//quantity
			fprintf(file, "%.2f\n", list[loop].quantity);
		}
		fclose(file);
	}

	getchar();
	return;
}