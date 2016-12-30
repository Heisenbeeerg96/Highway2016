#include <stdio.h>
#include "Printing.h"
#include <string.h>
int LoginCheck(char* name, char* password)
{
	FILE* file;
	char name1[10];
	char password1[10];
	if (file = fopen("zaposleniLogin.txt", "r"))
	{
		while(fscanf(file, "%s %s", name1, password1)!=EOF)
		if (!(strcmp(name, name1)) && !(strcmp(password, password1))) return 1;
	}
	fclose(file);
	printf("Pogresno korisnicko ime ili lozinka!\nPokusajte ponovo!\n");
	return 0;
}
int main()
{
	int input;
	char d1;
	char name[10];
	char password[15];
	printf("******************HIGHWAY2016*******************\n\n\n");
	printf("Izaberite neku od ponudjenih opcija:\n");
	do
	{
		printf("1.Stampaj potvrdu!\n");
		printf("2.Uloguj se kao zaposleni!\n");
		printf("3.Pozovi pomoc na autoput!\n");
		printf("4.Pomoc pri koristenju programa!\n");
		printf("\n\nUnesite redni broj opcije:");
		scanf("%d", &input);
	} while (input > 4 || input < 1);
	if (input == 1) {
		printf("Odaberite dionicu kojom putujete(A,B,C,D,E,F):\n");
		printf("Startna:");
		scanf("%c", &d1);
		scanf("%c", &d1);
		printing(d1); //poziva funkciju za stampanje potvrde
		printf("Preuzmite potvrdu!\n\nHVALA NA POVJERENJU!");

	}
	if (input == 2)
	{
		do {

			printf("Unesite korisnicko ime:");
			scanf("%s", name);
			printf("Unesite lozinku:");
			scanf("%s", password);
		} while (LoginCheck(name, password) == 0);
		//ne znak kakve funkcionalnosti ovdje da zaposleni ima, ne znam ni koji ce djavo zaposleni u kutiji koja stampa potvrde al aj
		//nastaviti ovdje ono sto mislite da treba


		


	}
	system("pause");

		
}