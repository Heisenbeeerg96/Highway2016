#include <stdio.h>
#include "Printing.h"
#include <string.h>
#include "infoChange.h"
#include "LoginCheck.h"
#include "AddWorker.h"
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
			printf("4.Dodaj novog zaposlenog!\n");
			printf("5.Odjava!\n");
			do
			{
				printf("Unesite redni broj opcije:");
				scanf("%d", &input);
			
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
			if (input == 4)
			{
				addWorker();
			}
			} while (input < 1 || input >5);





		}
		if (input == 2) {
			printf("1.Izlistaj stanja na dionicama!\n");
			printf("2.Nesto nesto nesto")
		}
	}
	system("pause");

		
  }