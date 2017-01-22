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
int main()
{
	//ideja je da program funkcionise na racunaru za kojim operise covjek, a nalazi se u kucici, tako da, imacemo kucicu na ulazu i 
	//izlazu

	int input = 1, input2, input3 = 1, SOScount = readSOSReport();
	char d1;
	char name[10], dion[10];
	char password[15];
	char sifra[6];
	//ovo dio sam koristio za testiranje,ali po ovome mozete vidjet kako funkcionise,nemorate zalazit dublje u kod
	/*Podatak tipa BILL sluzi da se ucita(nadje) potvrdu vozacu kada dodje na izlaz,OVO TREBA VIDA KORISTIT ZA MUP
	 jer se ovim prestavlja potvrda,po pravilu izlaz bi se trebao da se realziuje da pita vozaca da unese sifu pa onda
	 dionicu na kojoj izlazi,ili obrnuto samo sacuvajte te podatke i posaljite u ove funkcije dole!!!*/
	/*speedTicket je za pisanje kaznje,mislim slanje potvrde MUPU,kako smo na proslom sastanku pricla MIlan je rekao da se potvrda 
	 jedino moze sacuvaj kada admin se odjavi,e neka to i sa ovim djelom koda uradi
	 pod 3,napravio sam da ufunkciji speedticet otvara dadoteku u rezimu ,,a",neka se to promjeni(mislim ako se treba neka se promjenii) da bude u skladu kao 
	 sa onim dadotekama kako se stapaju na ulazu...u SpeedTicket saljemo potvrdu(to je potvrda o vozacu koji je usao na dionicu,a dion je dionica na kojoj je izasao
	 pa uklopite to*/
	//speedTicket(&ob, dion);

	
	
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
									printf("Izmjena na radu!\n");/*ovaj dio koda sluzi za izmjene na putu,unese se dionice koje su direkno povezane i onda imas mogucnost
																 promjene brzine,stanja itd...,na ulazi i izlaz stavit mogucnost promjene na putu*/
									printf("Na kojoj putanji se vrsi izmjena(putanja oznacava dvije dionice):\n");
									char dio1[2], dio2[2];
									scanf("%s %s", dio1, dio2);//trazi da uneses dvije dionice da pormenis njhova stanja!!
									changeStat(dio1, dio2);
								}
								else if (input3 == 3)
								{
									system("CLS");
									printf("******************HIGHWAY2016*******************\n\n\n");
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
								scanf("%d", &input3);
							} while (input3 < 1 || input3 >4);
							if (input3 == 1)
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
							else if (input3 == 3)
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
			printf("Sistem generise SOS signal!\n");
			SOScount++;
			system("pause");
			break;
		}
		case(3):
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