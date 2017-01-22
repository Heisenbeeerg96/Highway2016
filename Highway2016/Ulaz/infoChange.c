#include "infoChange.h"
#include "AddFirm.h"
#include "Dionica.h"
#include "Person.h"

void changeLimit(char* nlimit,char d)
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
		while (fscanf(file, "%s\n", temp) != EOF )		//kopiramo ostatak
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
	PERSON p;
	FIRM f;
	printf("\n============================================================\n");
	printf("INFORMACIJE O  FIRMAMA  ZADUZENIM  ZA  ODRZAVANJE  PUTEVA\n");
	printf("=============================================================\n");
	printf("Dio Firma        Ime radnika  Prezime radnika Aktivnost firme\n");
	printf("=== ============ ============ =============== ===============\n");
	char pom[1];
	file = fopen("firma.txt", "r");
	if (file)
	{
	while ((pom[0] = fgetc(file)) && (fscanf(file,"\n%s\n%s\n%s\n",f.name, p.name, p.surname) != EOF))
	{

	printf("%c   ", pom[0]);
	printf("%-13s", f.name);
	printf("%-13s", p.name);
	printf("%-13s   ", p.surname);
	if (!strcmp(d.workBool, "da"))
	printf("Aktivna\n");
	else printf("Neaktivna\n");
	}
	}
	fclose(file);
	printf("\n=== ============ ============ =============== ===============\n");
}
