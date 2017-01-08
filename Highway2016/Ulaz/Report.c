#include "Report.h"

int readReport()
{
	int tmp = 0;
	if (file = fopen("izvjestaj.txt", "r"))
		fscanf(file, "%d", &tmp);
	return tmp;
}
void fixReport(int i)
{
	if (file = fopen("izvjestaj.txt", "w"))
		fprintf(file, "%d", i);
}