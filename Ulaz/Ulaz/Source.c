#include <stdio.h>
#include "Printing.h"
#include <string.h>
#include "infoChange.h"
int LoginCheck(char* name, char* password,int input)
{
	FILE* file;
	char name1[10];
	char password1[10];
	char temp[15];
	if (input==2)
	if (file = fopen("zaposleniLogin.txt", "r"))
	{
		fseek(file, 10, 0); // pomijeranje na mjesto odakle pocinje lista Operatera
		while (fscanf(file, "%s %s", name1, password1) != EOF) {
			if (!(strcmp("Admini:", name1))) return 0;  //vrati 0 ako smo stigli do liste admina
			if (!(strcmp(name, name1)) && !(strcmp(password, password1))) return 1;
		}
	}
	if (input == 1)
	{
		if (file = fopen("zaposleniLogin.txt", "r"))
		{
			while (fscanf(file, "%s", temp) != EOF && strcmp(temp, "Admini:")); // dolazak do liste admina u datoteci
			while (fscanf(file, "%s %s", name1, password1) != EOF)
			{
				if (!(strcmp(name, name1)) && !(strcmp(password, password1))) return 1;
			}
		}

	}
	
	printf("Pogresno korisnicko ime ili lozinka!\nPokusajte ponovo!\n");
	return 0;
}
int main()
{
	//ideja je da program funkcionise na racunaru za kojim operise covjek, a nalazi se u kucici, tako da, imacemo kucicu na ulazu i 
	//izlazu
	int input;
	char d1;
	char name[10],dion[10];
	char password[15];
	printf("******************HIGHWAY2016*******************\n\n\n");
	printf("Unesite ime dionice  na kojoj ce se ovaj softver koristiti(A,B,C,D,E,F):");
	scanf("%s", dion);
	printf("Izaberite neku od ponudjenih opcija:\n");
	do
	{	
		
		printf("1.Ja sam zaposleni!\n");
		printf("2.Ja sam vozac!\n");
		printf("3.Pozovi pomoc na autoput!\n");
		printf("4.Pomoc pri koristenju programa!\n");
		printf("\n\nUnesite redni broj opcije:");
		scanf("%d", &input);
	} while (input > 4 || input < 1);

	if (input == 1)
	{
		printf("1.Admin\n2.Operater\nIzaberite opciju:");
		scanf("%d", &input);
		do {

			printf("Unesite korisnicko ime:");
			scanf("%s", name);
			printf("Unesite lozinku:");
			scanf("%s", password);
		} while (LoginCheck(name, password, input) == 0);
		system("cls");
		printf("USPJESAN LOGIN!\n\n\n");
		printf("MENI:\n\n\n");
		if (input == 1)
		{
			printf("1.Promijeni ogranicenja!\n");
			printf("2.Promijeni stanje na putevima!\n");
			printf("3.Izlistaj trenutna stanja na dionicama!\n");
			do
			{
				printf("Unesite redni broj opcije:");
				scanf("%d", &input);
			} while (input < 1 || input >3);
			if (input == 1)
			{
				char limit[10];
				printf("Unesite novo ogranicenje:");
				scanf("%s", limit);
				changeLimit(limit, dion[0]);
			}
			if (input == 2)
			{	
				char workBool[3];
				char traficBool[3];
				printf("Na dionici %s se odvijaju radovi?(da/ne)", dion);
				scanf("%s", workBool);
				printf("Na dionici %s je moguce nastaviti odvijanje saobracaja?(da/ne)", dion);
				scanf("%s", traficBool);
				changeCondition(workBool, traficBool, dion[0]);
			}
			if (input == 3)
			{
				printD();
			}





		}
	}
	system("pause");

		
  }