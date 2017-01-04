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
	int input = 1, input2, input3 = 1;
	char d1;
	char name[10],dion[10];
	char password[15];
	system("CLS");
	printf("******************HIGHWAY2016*******************\n\n\n");
	printf("Unesite ime dionice  na kojoj ce se ovaj softver koristiti(A,B,C,D,E,F):");
	scanf("%s", dion);
	while (1)
	{
		system("CLS");
		printf("******************HIGHWAY2016*******************\n\n\n");
		printf("Izaberite neku od ponudjenih opcija:\n");
		do
		{
			system("CLS");
			printf("******************HIGHWAY2016*******************\n\n\n");
			printf("1.Ja sam zaposleni!\n");
			printf("2.Ja sam vozac!\n");
			printf("3.Pozovi pomoc na autoput!\n");
			printf("4.Pomoc pri koristenju programa!\n");
			printf("\n\nUnesite redni broj opcije:");
			scanf("%d", &input);
		} while (input > 4 || input < 1);
		switch (input)
		{
		case(1):
			{
				system("CLS");
				printf("******************HIGHWAY2016*******************\n\n\n");
				printf("1.Admin\n2.Operater\nIzaberite opciju:");
				scanf("%d", &input2);
				int countLogs = 0;
				do {
					printf("Unesite korisnicko ime:");
					scanf("%s", name);
					printf("Unesite lozinku:");
					scanf("%s", password);
					countLogs++;
				} while (LoginCheck(name, password, input2) == 0 && countLogs < 4);
				if(countLogs<4)
				{
					system("CLS");
					printf("******************HIGHWAY2016*******************\n\n\n");
					printf("USPJESAN LOGIN!\n\n\n");
					printf("MENI:\n\n\n");
					switch (input2)
					{
					case(1):
					{
						do
						{
							while(1)
							{
								system("CLS");
								printf("******************HIGHWAY2016*******************\n\n\n");
								printf("1.Promijeni ogranicenja!\n");
								printf("2.Promijeni stanje na putevima!\n");
								printf("3.Izlistaj trenutna stanja na dionicama!\n");
								printf("4.Dodaj novog zaposlenog!\n");
								printf("5.Izlaz iz programa!\n");
								printf("6.Odjava!\n");
								printf("Unesite redni broj opcije:");
								scanf("%d", &input3);
								if (input3 == 1)
								{
									system("CLS");
									printf("******************HIGHWAY2016*******************\n\n\n");
									char limit[10];
									printf("Unesite novo ogranicenje:");
									scanf("%s", limit);
									changeLimit(limit, dion[0]);
								}
								else if (input3 == 2)
								{
									system("CLS");
									printf("******************HIGHWAY2016*******************\n\n\n");
									char workBool[3];
									char traficBool[3];
									printf("Na dionici %s se odvijaju radovi?(da/ne)", dion);
									scanf("%s", workBool);
									printf("Na dionici %s je moguce nastaviti odvijanje saobracaja?(da/ne)", dion);
									scanf("%s", traficBool);
									changeCondition(workBool, traficBool, dion[0]);
								}
								else if (input3 == 3)
								{
									printD();
									system("pause");
								}
								else if (input3 == 4)
								{
									addWorker();
								}
								else if (input3 == 5)
								{
									system("pause");
									return 0;
								}
								else if (input3 == 6)
								{
									system("pause");
									break;
								}
							}
						} while (input3 < 1 || input3 >6);
						break;



					}
					case(2):											//opcije operatera,dovrsiti
					{
						printf("1.Izlistaj stanja na dionicama!\n");
						printf("2.Nesto nesto nesto");
					}
					}
				}
				else
				{
					system("CLS");
					printf("******************HIGHWAY2016*******************\n\n\n");
					printf("Ponovite kasnije!\n");
					system("pause");
				}
				break;
			}
		case(2):
			{
				system("CLS");
				printf("******************HIGHWAY2016*******************\n\n\n");
				printf("Potvrda se stampa!\n");
				printing(dion[0]);
				printf("Preuzmite potvrdu!\n");
				system("pause");
				break;
			}
		case(3):
			{
				system("CLS");
				printf("******************HIGHWAY2016*******************\n\n\n");
				printf("Softver generise SOS signal!\n\nSOS signal uspjesno poslat.\nUkoliko pomoc blagovremeno ne stigne, potrazite najblizi SOS telefon na autoputu.");
				system("pause");
				break;
			}
		case(4):
			{
				system("CLS");
				printf("******************HIGHWAY2016*******************\n\n\n");
				printf("Na pocetku birate jednu od ponudjenih opcija u skladu sa Vasim zahtjevima.Nakon pristupa softveru kao admin ");
				printf("ili kao operater imate mogucnosti uglavnom manipulisanja podacima i/ili uvid u stanje autoputa. Za vise informacija ");
				printf("otvorite HELP sekciju prirucnika!\n");
				system("pause");
				break;
			}
		case(0):
			break;
		}
	}
	system("pause");

		
  }