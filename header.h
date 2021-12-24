#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159
#include<stdio.h>
#include<string.h>

struct vaccine
{
	char vac_name[20]; //vaccine name
	char vac_code[3]; // vaccine code
	char ori_country[20]; //producing country
	int dos_req; //dosage required
	float pop_cov; //population covered
	float quantity; //quantity(mil)
};

struct distribution_list //mostly used for calling it out
{
	char vac_name[20]; //vaccine name
	char vac_code[3]; // vaccine code
	float quantity_distributed; //quantity_distributed(mil)
};

typedef struct vaccine VAC;
typedef struct distribution_list DIST;