#include "InfoChange.h"
#include "Dionica.h"
void changeLimit(char* nlimit, char d)
{
	FILE* tmp;                   //pomocna datoteka
	char temp[10];
	tmp = fopen("temp.txt", "w");
	if (file = fopen("infoNaPutevima.txt", "r"))
	{
		while (fscanf(file, "%s\n", temp) != EOF && temp[0] != d)     //upisujemo sve dok ne dodjemo do dionice koju mijenjamo
		{
			fputs(temp, tmp);
			fputs("\n", tmp);
		}
		fputs(temp, tmp);								//upisujemo ime dionice
		fputs("\n", tmp);
		fputs(nlimit, tmp);								//novo ogranicenje
		fputs("\n", tmp);
		fseek(file, 3, 1);								//preskacemo staro ogranicenje u originalu
		while (fscanf(file, "%s\n", temp) != EOF)		//kopiramo ostatak
		{
			fputs(temp, tmp);
			fputs("\n", tmp);
		}

	}
	fclose(tmp);
	fclose(file);
	remove("infoNaPutevima.txt");					//brisemo original
	rename("temp.txt", "infoNaPutevima.txt");		//preimenujemo pomocnu datoteku

}
void changeCondition(char* workBool, char* traficBool, char d)
{
	FILE* tmp;
	char temp[10];
	tmp = fopen("temp.txt", "w");
	if (file = fopen("infoNaPutevima.txt", "r"))
	{
		while (fscanf(file, "%s\n", temp) != EOF && temp[0] != d)
		{
			fputs(temp, tmp);
			fputs("\n", tmp);
		}
		fputs(temp, tmp);
		fputs("\n", tmp);
		fgets(temp, 5, file);
		fputs(temp, tmp);
		fputs(traficBool, tmp);
		fputs("\n", tmp);
		fputs(workBool, tmp);
		fputs("\n", tmp);
		fseek(file, 6, 1);
		while (fscanf(file, "%s\n", temp) != EOF)
		{
			fputs(temp, tmp);
			fputs("\n", tmp);
		}

	}
	fclose(tmp);
	fclose(file);
	remove("infoNaPutevima.txt");
	rename("temp.txt", "infoNaPutevima.txt");


}
void printD()
{
	file = fopen("infoNaPutevima.txt", "r");
	DIONICA d;
	printf("\n\n********INFORMACIJE O DIONICAMA:********\n\n");
	printf("Ime      Ogranicenje Radovi        Saobracanje\n");
	printf("======== =========== ============= ================\n");
	if (file)
	{
		while (fscanf(file, "%s\n%s\n%s\n%s\n", d.name, d.limit, d.workBool, d.traficBool) != EOF)
		{
			printf("%-9s", d.name);
			printf("%-12s", d.limit);
			printf("%-12s", d.workBool);
			printf("%-17s\n", d.traficBool);

		}
		printf("\n======== ============= ================\n");
	}
}