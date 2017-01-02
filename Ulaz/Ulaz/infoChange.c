#include "infoChange.h"
void changeLimit(char* nlimit,char d)
{
	char temp[10];
	if (file = fopen("infoNaPutevima.txt", "r+"))
	{
		while (fscanf(file, "%s", temp) != EOF && temp[0] != d);

		if(fputs("100", file)!=EOF)
		fclose(file);
	}

}