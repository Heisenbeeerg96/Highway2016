#include <stdio.h>
#include "Printing.h"
#include <string.h>
#include "infoChange.h"
#include "LoginCheck.h"
#include "AddWorker.h"
#include "Report.h"
#include "AddFirm.h"
#include "RoadStatisticsChange.h"

int main()
{
	//ideja je da program funkcionise na racunaru za kojim operise covjek, a nalazi se u kucici, tako da, imacemo kucicu na ulazu i 
	//izlazu
	int input = 1, input2, input3 = 1, SOScount = readSOSReport();
	int enteringCount;
	enteringCount = readReport();
	char d1, category[5];
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
				do
				{
					system("CLS");
					printf("******************HIGHWAY2016*******************\n\n\n");
					printf("1.Admin\n2.Operater\n3.Izlaz\nIzaberite opciju:");
					scanf("%d", &input2);
				} while (input2 < 1 || input2>3);
				int countLogs = 0;
				if (input2 == 3)break;
				else
				{
					do
					{
						system("CLS");
						printf("******************HIGHWAY2016*******************\n\n\n");
						printf("Unesite korisnicko ime:");
						scanf("%s", name);
						printf("Unesite lozinku:");
						scanf("%s", password);
						countLogs++;
					} while (LoginCheck(name, password, input2) == 0 && countLogs < 4);
					if (countLogs < 4)
					{
						system("CLS");
						printf("******************HIGHWAY2016*******************\n\n\n");
						switch (input2)
						{
						case(1):
						{
							do
							{
								while (1)
								{
									system("CLS");
									printf("******************HIGHWAY2016*******************\n\n\n");
									printf("MENI:\n\n");
									printf("2.Promijeni stanje na putevima!\n");
									printf("3.Izlistaj trenutna stanja na dionicama!\n");
									printf("4.Dodaj novog zaposlenog!\n");
									printf("5.Izlaz iz programa!\n");
									printf("6.Odjava!\n");
									printf("Unesite redni broj opcije:");
									scanf("%d", &input3);
									 if (input3 == 2)
									{
										system("CLS");
										printf("******************HIGHWAY2016*******************\n\n\n");
										char workBool[3];
										char traficBool[3];
										printf("Na dionici %s se odvijaju radovi?(da/ne)", dion);
										scanf("%s", workBool);
										if (!strcmp(workBool, "da"))
										{
											add_maintanceWorker(dion[0]);
										}
										printf("Na kojoj putanji se vrsi izmjena(putanja oznacava dvije dionice):\n");
										char dio1[2], dio2[2];
										scanf("%s %s", dio1, dio2);//trazi da uneses dvije dionice da pormenis njhova stanja!!
										changeStat(dio1, dio2);
									}
									else if (input3 == 3)
									{
										system("CLS");
										printf("******************HIGHWAY2016*******************\n\n\n");
										printD();
										printf("\n");
										printRoadStat();
										system("pause");
									}
									else if (input3 == 4)
									{
										system("CLS");
										printf("******************HIGHWAY2016*******************\n\n\n");
										addWorker();
									}
									else if (input3 == 5)
									{
										fixReport(enteringCount);
										fixSOSReport(SOScount);
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
							while (1)
							{
								do
								{
									system("CLS");
									printf("******************HIGHWAY2016*******************\n\n\n");
									printf("MENI:\n\n");
									printf("1.Izlistaj stanja na dionicama!\n");
									printf("2.Provjeri da li ima zahtjeva za pomoc!\n");
									printf("3.Odjava!\n");
									printf("Unesite redni broj opcije: ");
									scanf("%d", &input3);
								} while (input3 < 1 || input3 >3);
								if (input3 == 1)
								{
									system("CLS");
									printf("******************HIGHWAY2016*******************\n\n\n");
									printD();
									printf("\n");
									printRoadStat();
									system("pause");
								}
								else if (input3 == 2)
								{
									system("CLS");
									printf("******************HIGHWAY2016*******************\n\n\n");
									if (SOScount == 0)
									{
										printf("Nema zahtjeva!\n");
										system("pause");
									}
									else
									{
										printf("Pomoc poslata!\n");
										SOScount--;
										system("pause");
									}
								}
								else if (input3 == 3)
								{
									system("pause");
									break;
								}
							}
						}
						}
					}
					else
					{
						system("CLS");
						printf("******************HIGHWAY2016*******************\n\n\n");
						printf("Pokusajte ponovo kasnije!\n");
						system("pause");
					}
					break;
				}
}
		case(2):
			{
				system("CLS");
				printf("******************HIGHWAY2016*******************\n\n\n");
				printf("Unesite kategoriju vozila:\n");
				printf("Automobil - A\n");
				printf("Autobus   - B\n");
				printf("Kamion    - K\n");
				printf("Motocikl  - M\n");
				scanf("%s", category);
				printf("Potvrda se stampa!\n");
				enteringCount++;
				printing(dion[0], enteringCount, category[0]);
				printf("Preuzmite potvrdu!\nMolimo vas zapamtite sifru: %05d\n",enteringCount);
				system("pause");
				break;
			}
		case(3):
			{
				system("CLS");
				printf("******************HIGHWAY2016*******************\n\n\n");
				printf("Softver generise SOS signal!\n\nSOS signal uspjesno poslat.\nUkoliko pomoc blagovremeno ne stigne, potrazite najblizi SOS telefon na autoputu.");
				SOScount++;
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