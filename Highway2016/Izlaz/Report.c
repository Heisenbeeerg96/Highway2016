#include "Report.h"

int readReport()
{
	int tmp = 0;
	if (file = fopen("izvjestaj.txt", "r"))
	{
		fscanf(file, "%d", &tmp);
		fclose(file);
	}
	return tmp;
}
void fixReport(int i)
{
	if (file = fopen("izvjestaj.txt", "w"))
	{
		fprintf(file, "%d", i);
		fclose(file);
	}
}

int readSOSReport()
{
	int tmp = 0;
	if (file = fopen("SOSizvjestaj.txt", "r"))
	{
		fscanf(file, "%d", &tmp);
		fclose(file);
	}
	return tmp;
}

void fixSOSReport(int i)
{
	if (file = fopen("SOSizvjestaj.txt", "w"))
	{
		fprintf(file, "%d", i);
		fclose(file);
	}
}
