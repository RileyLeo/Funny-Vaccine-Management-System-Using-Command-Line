#include "header.h"
#include "functions.h"

void directory(int selection)
{
	switch (selection)
	{
	case 1:
		inv();
		break;

	case 2:
		update();
		break;

	case 3:
		search();
		break;

	case 4:
		list();
		break;

	default:
		printf("Invalid selection, please try again.");
		getchar();
	}

	return;

}