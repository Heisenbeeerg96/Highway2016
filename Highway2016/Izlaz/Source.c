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
#include "TicketForSpeedLow.h"
#include "AddFirm.h"
int main()
{
	//ideja je da program funkcionise na racunaru za kojim operise covjek, a nalazi se u kucici, tako da, imacemo kucicu na ulazu i 
	//izlazu

	int log, SOScount = readSOSReport();
	char d1, input[2], input2[2], logInput[2];
	char name[10], dion[10];
	char password[15];
	char sifra[6];
		
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
			printf("2.Pozovi pomoc na autoput!\n");
			printf("3.Pomoc pri koristenju programa!\n");
			printf("\n\nUnesite redni broj opcije:");
			scanf("%s", input);
			{
				if (strcmp(input, "1") == 0)
				{
					do
					{
						system("CLS");
						printf("******************HIGHWAY2016*******************\n\n\n");
						printf("1.Admin\n2.Operater\n3.Izlaz\nIzaberite opciju:");
						scanf("%s", input2);
					} while (strcmp(input2, "1") < 0 || strcmp(input2, "3") > 0);
					int countLogs = 0;
					if (strcmp(input2, "3") == 0)break;
					else
					{
						do
						{
							system("CLS");
							printf("******************HIGHWAY2016*******************\n\n\n");
							if (strcmp(input2, "1") == 0)
								log = 1;
							else log = 2;
							printf("Unesite korisnicko ime:");
							scanf("%s", name);
							printf("Unesite lozinku:");
							scanf("%s", password);
							countLogs++;
						} while (LoginCheck(name, password, log) == 0 && countLogs < 4);
						if (countLogs < 4)
						{
							system("CLS");
							printf("******************HIGHWAY2016*******************\n\n\n");
							switch (log)
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
										printf("1.Promijeni stanje na putevima!\n");
										printf("2.Izlistaj trenutna stanja na dionicama!\n");
										printf("3.Dodaj novog zaposlenog!\n");
										printf("4.Izlaz iz programa!\n");
										printf("5.Odjava!\n");
										printf("Unesite redni broj opcije:");
										scanf("%s", logInput);
										if (strcmp(logInput, "1") == 0)
										{
											system("CLS");
											printf("******************HIGHWAY2016*******************\n\n\n");
											printf("Izmjena na radu!\n");/*ovaj dio koda sluzi za izmjene na putu,unese se dionice koje su direkno povezane i onda imas mogucnost
																		 promjene brzine,stanja itd...,na ulazi i izlaz stavit mogucnost promjene na putu*/
											printf("Na kojoj putanji se vrsi izmjena(putanja oznacava dvije dionice):\n");
											char dio1[2], dio2[2];
											scanf("%s %s", dio1, dio2);//trazi da uneses dvije dionice da pormenis njhova stanja!!
											int gg=changeStat(dio1, dio2);
											if (gg == 1)
												add_maintanceWorker(dio1[0], dio2[0]);

										}
										else if (strcmp(logInput, "2") == 0)
										{
											system("CLS");
											printf("******************HIGHWAY2016*******************\n\n\n");
											printRoadStat();
											printD();
											system("pause");
										}
										else if (strcmp(logInput, "3") == 0)
										{
											system("CLS");
											printf("******************HIGHWAY2016*******************\n\n\n");
											addWorker();
										}
										else if (strcmp(logInput, "4") == 0)
										{
											fixSOSReport(SOScount);
											system("pause");
											return 0;
										}
										else if (strcmp(logInput, "5") == 0)
										{
											system("pause");
											break;
										}
									}
								} while (strcmp(logInput, "5") != 0 && (strcmp(logInput, "1") < 0 || strcmp(logInput, "5") > 0));
								break;



							}
							case(2):
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
										scanf("%s", logInput);
									} while (strcmp(logInput, "4") != 0 && (strcmp(logInput, "1") < 0 || strcmp(logInput, "4") > 0));
									if (strcmp(logInput, "1") == 0)
									{
										system("CLS");
										printf("******************HIGHWAY2016*******************\n\n\n");
										printD();
										printf("\n");
										printRoadStat();
										system("pause");
									}
									else if (strcmp(logInput, "2") == 0)
									{
										system("CLS");
										printf("******************HIGHWAY2016*******************\n\n\n");
										printRoadStat();
										{
											printf("Pomoc poslata!\n");
											SOScount--;
											system("pause");
										}
									}
									else if (strcmp(logInput, "3") == 0)
									{
										system("CLS");
										printf("******************HIGHWAY2016*******************\n\n\n");
										char sifra[6];
										BILL ob;
										do
										{
											printf("Unesite sifru vozaceve potvrde:\n");
											scanf("%s", sifra);//sifra prestavlja sifru potvrde koju dobije korisnik na pocetku
											ob = findPassword(sifra); //trazi sifru u dadoteci potvrda,i kada nadje samo inicilazuje podatak u mainu

										} while (ob.year == -1);//ovo koristim ako vozac slucajno unese pogresnu sifru,pa da ima mogucnost opet unosa
										printf("Sifra je pronadjenja:%s\n", ob.password); //pronalaz potvrde!
										finallprice(&ob, dion); //proracun cjene!
										speedTicket(&ob, dion);
										printf("Hvala Vam ste koristili nase usluge!\nSretan put\n");//ispis na displeju sa vanjske strane kucice
										system("pause");
									}
									else if (strcmp(logInput, "4") == 0)
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

				else if (strcmp(input, "2") == 0)
				{
					system("CLS");
					printf("******************HIGHWAY2016*******************\n\n\n");
					printf("Sistem generise SOS signal!\n");
					SOScount++;
					system("pause");
					break;
				}
				else if (strcmp(input, "3") == 0)
				{
					system("CLS");
					printf("******************HIGHWAY2016*******************\n\n\n");
					printf("Na pocetku birate jednu od ponudjenih opcija u skladu sa Vasim zahtjevima.\nNakon pristupa softveru kao admin ");
					printf("ili kao operater imate mogucnosti uglavnom \nmanipulisanja podacima i/ili uvid u stanje autoputa. \nZa vise informacija ");
					printf("otvorite HELP sekciju prirucnika!\n\n\n\n\n");
					system("pause");
					break;
				}
				else
					break;
			}
		}while (strcmp(input, "1")<0 || strcmp(input, "3")>0);
	}
	system("pause");

}