#include <stdio.h>
#include <string.h>
#include "Printing.h"
#include "infoChange.h"
#include "LoginCheck.h"
#include "AddWorker.h"
#include "PriceCalculation.h"
#include "PasswordFinder.h"
#include "Report.h"
#include "RoadStatisticsChange.h"
int main()
{
	//ideja je da program funkcionise na racunaru za kojim operise covjek, a nalazi se u kucici, tako da, imacemo kucicu na ulazu i 
	//izlazu
	int input = 1, input2, input3 = 1, SOScount = readSOSReport();
	char d1;
	char name[10], dion[10];
	char password[15];
	
	
	char sifra[6];
	BILL ob;
	do
	{
		printf("Unesite sifru vase potvrde:\n");
		scanf("%s", sifra);
		ob = findPassword(sifra);

	} while (ob.year == -1);
	printf("Sifra je pronadjenja:%s\n", ob.password); //pronalaz potvrde!
	scanf("%s", dion);//unosi se dionica na kojoj izlazi!
	finallprice(&ob,dion); //proracun cjene!

	printf("Izmjena na radu!\n");
	printf("Na kojim dionicama se vrsi izmejna:\n");
	char dio1[2], dio2[2];
	scanf("%s %s", dio1, dio2);
	changeStat(dio1, dio2);



	/*
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
									system("CLS");
									printf("******************HIGHWAY2016*******************\n\n\n");
									printD();
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
								printf("3.Naplati!\n");
								printf("4.Odjava!\n");
								printf("Unesite redni broj opcije: ");
								scanf("%d", &input3);
							} while (input3 < 1 || input3 >4);
							if (input3 == 1)
							{
								system("CLS");
								printf("******************HIGHWAY2016*******************\n\n\n");
								printD();
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
								system("CLS");
								printf("******************HIGHWAY2016*******************\n\n\n");
								//ovdje bi trebalo koristiti neku f-ju za kreiranje onih izvjestaja
								printf("Naplaceno!\n");
								system("pause");
							}
							else if (input3 == 4)
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
			printf("Molimo Vas pokazite svoju potvrdu!\n");
			//sad mu izracuna i naplati ili nesto slicno,Floyd bi se trebao ovdje koristiti
			printf("Hvala Vam ste koristili nase usluge!\nSretan put\n");
			system("pause");
			break;
		}
		case(3):
		{
			system("CLS");
			printf("******************HIGHWAY2016*******************\n\n\n");
			printf("Sistem generise SOS signal!\n");
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
	}*/
	system("pause");

}