#include "LoginCheck.h"

int LoginCheck(char* name, char* password, int input)
{
	FILE* file;
	char name1[10];
	char password1[10];
	char temp[15];
	if (input == 2)
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