#include "header.h"


void inv()
{
	VAC new; //header struct VAC
	FILE* file;
	int length, vaccine_type;

	file = fopen("vaccine.txt", "a");

	if (file == NULL)
	{
		printf("Open file error");
		return;
	}
	else
	{
		printf("This is the vaccine inventory creation.\n\n");
		//info gathering
		printf("Name of Vaccine : ");
		gets(new.vac_name);
		printf("Vaccine Code : ");
		gets(new.vac_code);
		printf("Producing Country : ");
		gets(new.ori_country);
		printf("Dosage Required : ");
		scanf("%d", &new.dos_req);
		printf("Population Covered (%%) : ");
		scanf("%f", &new.pop_cov);
		printf("Initial quantity (millions) : ");
		scanf("%f", &new.quantity);

		//test show
		printf("%s \t", new.vac_name);
		printf("%s \t", new.vac_code);
		printf("%s \t", new.ori_country);
		printf("%d \t", new.dos_req);
		printf("%.2f \t", new.pop_cov);
		printf("%.2f\n", new.quantity); 
		// end test

		//vacc name
		length = strlen(new.vac_name);
		fprintf(file, "%d%s ", length, new.vac_name);
		//vac code
		length = strlen(new.vac_code);
		fprintf(file, "%d%s ", length, new.vac_code);
		// vac country
		length = strlen(new.ori_country);
		fprintf(file, "%d%s ", length, new.ori_country);
		//dos req
		fprintf(file, "%d ", new.dos_req);
		//pop_cov
		fprintf(file, "%.2f ", new.pop_cov);
		//quantity
		fprintf(file, "%.2f\n", new.quantity);

		
		fclose(file);
	}

	//update amount list
	file = fopen("vaccine_type_amount.txt", "r");

	if (file == NULL)
	{
		printf("Error update Vaccine type amount");
		return;
	}
	else
	{


		fscanf(file, "%d ", &vaccine_type);
		vaccine_type++;


		fclose(file);
	}

	file = fopen("vaccine_type_amount.txt", "w");

	if (file == NULL)
		printf("Error update Vaccine type amount");
	else
	{
		fprintf(file, "%d", vaccine_type);
		fclose(file);
	}

	getchar();
	return;

}


