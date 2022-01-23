
#include <iostream>

#include "Hotel.h"
#include "Soba.h"
#include <fstream>;

#include "Korisnik.h"
#include "Pomocna.h"
#include "Osoba.h"
#include "Radnik.h"
#include "Rezervacija.h"
#include <ctime>
#define _CRT_SECURE_NO_WARNINGS
std::string toLower(std::string rijec)
{
	std::string ime = rijec;
	std::string noviString = "";
	for(int i=0;i<ime.length();i++)
	{
		if(i==0)
		{
			noviString += toupper(ime[i]);
		}else
		{
			noviString += tolower(ime[i]);
		}
		
	}
	return noviString;
}

int main()
{/*
	Soba a;
	std::cin >> a;
	std::cout << a;*/
	//SPREMANJE PODATAKA IZ OSOBA
	std::vector<Osoba> osobe;
	Osoba A;
	std::ifstream osobeUlaz;
	osobeUlaz.open("osobe.txt");
	while (true)
	{
		osobeUlaz >> A.ime >> A.prezime >> A.grad;
		if (osobeUlaz.eof()) break;
		osobe.push_back(A);
	}
	//////////////////////////////////////////////////////////
	//////UNOS PODATAKA HOTELI/////
	std::vector<Hotel> hoteli;
	std::ifstream hoteliUlaz;
	hoteliUlaz.open("hoteli.txt");
	Hotel hotel1;
	while (true)
	{
		hoteliUlaz >> hotel1.naziv >> hotel1.brUposlenih >> hotel1.brSpratova >> hotel1.brSobaPoSpratu;
		if (hoteliUlaz.eof()) break;
		hoteli.push_back(hotel1);

	}

	auto izbor = std::make_shared<int>();

	Hotel novi_hotel;
	std::string lowerImeHotela;
	std::string imeHotela;
	std::string trazenoImeHotela;
	std::string pregled;
	std::ofstream file;
	std::ofstream ulaz;
	std::ofstream ulaz2;
	std::ofstream ulaz3;
	std::ifstream file2;
	std::ifstream noviFajl;
	std::vector<std::string> imenaHotela;
	std::string ime;
	std::string imeProba;
	Osoba Osoba1;
	std::string pomocni;
	bool nasao = false;
	int izborMijenanje;
	int izborbrSobe;
	int izborM;
	Pomocna pomoc;
	int broj;
	Radnik noviRadnik;
	std::vector<Pomocna> pomocniVektor;
	std::vector<Radnik> vektorRadnik;
	std::vector<Hotel> vektorHotela;
	std::string rezervacijaString;
	std::vector<Korisnik> vektorKorisnici;
	std::vector<Rezervacija> vektorRezervacije;
	Rezervacija rezervacija;
	int a;
	int glavniIzbor;
	Korisnik novi_korisnik;
	std::string username;
	std::string password;
	bool loginan = false;
	std::string tempUsername;
	std::string tempPassword;
	int brSobe;
	int zadnjiIzbor;
	int dan;
	int godina;
	int mjesec;
	std::string noviString;
	std::string tempIme;
	std::string tempPrezime;
	Rezervacija nova_rezervacija;
	std::string str;
	int ab;
	file2.open("imenaHotela.txt");
ponovo:do
{
	
	std::cout << "1.Admin" << std::endl;
	std::cout << "2.Pregled hotela" << std::endl;
	std::cout << "3.Rezervacija" << std::endl;
	std::cin >> glavniIzbor;
	std::cin.ignore();
} while (glavniIzbor < 0 || glavniIzbor>3);
switch (glavniIzbor)
{
case 1:
	std::cout << "Username: ";
	std::cin >> tempUsername;
	std::cout << "Password: ";
	std::cin >> tempPassword;
	if(tempUsername=="admin" && tempPassword=="admin123")
	{
	do
	{
		std::cout << "1.Unesi novi hotel" << std::endl;
		std::cout << "2.Ispisi sve hotele" << std::endl;
		std::cout << "3.Promijeni podatke o hotelu" << std::endl;
		std::cout << "4.Ispisi podatke o sobama" << std::endl;
		std::cout << "5.Unesi novog radnika" << std::endl;
		std::cout << "6.Ispis svih radnika" << std::endl;
		std::cout << "7.Ispis rezervacija" << std::endl;
		std::cout << "99.Exit" << std::endl;
		std::cin >> *izbor;
		std::cin.ignore();
		switch (*izbor)
		{
		case 1:
			std::cin >> novi_hotel;
			hoteli.push_back(novi_hotel);
			file.open("imenaHotela.txt", std::ios::app);
			file << novi_hotel.getNaziv() << std::endl;
			file.close();
			break;
		case 2:
			for (int i = 0; i < hoteli.size(); i++)
			{
				std::cout << hoteli[i] << std::endl;
			}
			break;
		case 3:
			nasao = false;
			while (std::getline(file2, ime))
			{
				imenaHotela.push_back(ime);
				if (file2.eof()) break;
			}
			file2.close();
			std::cout << "Unesi ime hotela za kojeg zelis promijeniti podatke: ";
			std::cin >> imeHotela;
			for (int i = 0; i < imenaHotela.size(); i++)
			{
				//std::cout << imenaHotela[i];
				lowerImeHotela = toLower(imenaHotela[i]);
				trazenoImeHotela = toLower(imeHotela);
				if (lowerImeHotela == trazenoImeHotela)
				{
					nasao = true;
					break;
				}
			}
			if (nasao)
			{
				std::cout << "Taj hotel postoji!" << std::endl;
				pomocni = "";
				pomocni = trazenoImeHotela + ".txt";
				noviFajl.open(pomocni.c_str());
				std::cout << "Unesite broj sobe: ";
				std::cin >> izborbrSobe;
				std::cin.ignore();
				pomocniVektor.erase(pomocniVektor.begin(), pomocniVektor.end());
				while (true) {
					noviFajl >> pomoc.sprat >> pomoc.broj >> pomoc.cijena >> pomoc.vrsta >> pomoc.status;
					pomocniVektor.push_back(pomoc);
					if (noviFajl.eof()) break;
				}
				for (int i = 0; i < pomocniVektor.size(); i++)
				{
					if (pomocniVektor[i].broj == izborbrSobe)
					{
						std::cout << "Broj sprata" << "\t" << "Broj sobe" << "\t" << "Cijena sobe" << "\t" << "Vrsta sobe" << "\t" << "Status sobe" << std::endl;
						std::cout << pomocniVektor[i].sprat << "\t\t" << pomocniVektor[i].broj << "\t\t" << pomocniVektor[i].cijena << "\t\t" << pomocniVektor[i].vrsta << "\t" << pomocniVektor[i].status << std::endl;
						std::cout << "Mijenjanje statusa" << std::endl;
						std::cout << "1.Slobodna" << std::endl;
						std::cout << "2.Zauzeta" << std::endl;
						std::cout << "3.Rezervisana" << std::endl;
						std::cin >> izborM;
						std::cin.ignore();
						if (1 == izborM)
						{
							pomocniVektor[i].status = "Slobodna";
						}
						else if (izborM == 2)
						{
							pomocniVektor[i].status = "Zauzeta";
						}
						else
						{
							pomocniVektor[i].status = "Rezervisana";
						}
					}

				}
				noviFajl.close();
				file.open(pomocni.c_str());
				for (int i = 0; i < pomocniVektor.size() - 1; i++)
				{
					file << pomocniVektor[i].sprat << "\t\t" << i + 1 << "\t\t" << pomocniVektor[i].cijena << "\t\t" << pomocniVektor[i].vrsta << "\t\t" << pomocniVektor[i].status << std::endl;
				}
				file.close();

			}
			break;
		case 4:
			nasao = false;
			//imenaHotela.erase(imenaHotela.begin(), imenaHotela.end());
			//file2.open("imenaHotela.txt");
			while (std::getline(file2, ime))
			{
				imenaHotela.push_back(ime);
				if (file2.eof()) break;
			}
			file2.close();
			std::cout << "Unesi ime hotela za kojeg zelis pregledati podatke: ";
			std::cin >> imeHotela;
			for (int i = 0; i < imenaHotela.size(); i++)
			{
				std::cout << imenaHotela[i];
				lowerImeHotela = toLower(imenaHotela[i]);
				trazenoImeHotela = toLower(imeHotela);
				if (lowerImeHotela == trazenoImeHotela)
				{
					nasao = true;
					break;
				}
			}
			if (nasao)
			{
				pomocni = "";
				pomocni = trazenoImeHotela + ".txt";
				noviFajl.open(pomocni.c_str());
				pomocniVektor.erase(pomocniVektor.begin(), pomocniVektor.end());
				while (true) {
					noviFajl >> pomoc.sprat >> pomoc.broj >> pomoc.cijena >> pomoc.vrsta >> pomoc.status;
					pomocniVektor.push_back(pomoc);
					if (noviFajl.eof()) break;
				}
				std::cout << "Koju vrstu zelite pregledati?" << std::endl;
				std::cout << "1.Samo slobodne" << std::endl;
				std::cout << "2.Samo zauzete" << std::endl;
				std::cout << "3.Samo rezervisane" << std::endl;
				std::cout << "4.Sve" << std::endl;
				std::cin >> broj;
				std::cin.ignore();
				if (broj == 1) pregled = "slobodna";
				if (broj == 2) pregled = "Zauzeta";
				if (broj == 3) pregled = "Rezervisana";
				if (broj == 4) pregled = "sve";
				std::cout << "Sprat sobe" << "\t" << "Broj sobe" << "\t" << "Cijena sobe" << "\t" << "Vrsta sobe" << "\t" << "Status sobe" << std::endl;
				for (int i = 0; i < pomocniVektor.size() - 1; i++)
				{
					if(pregled=="sve")
					{
						std::cout << pomocniVektor[i].sprat << "\t\t" << pomocniVektor[i].broj << "\t\t" << pomocniVektor[i].cijena << "\t\t" << pomocniVektor[i].vrsta << "\t" << pomocniVektor[i].status << std::endl;
					}
					if (pomocniVektor[i].status == pregled)
					{
						std::cout << pomocniVektor[i].sprat << "\t\t" << pomocniVektor[i].broj << "\t\t" << pomocniVektor[i].cijena << "\t\t" << pomocniVektor[i].vrsta << "\t" << pomocniVektor[i].status << std::endl;
					}
				}
			}
			noviFajl.close();
			break;
		case 5:
			std::cin >> noviRadnik;
			std::cout << noviRadnik << std::endl;
			break;
		case 6:
			file2.close();
			file2.open("radnici.txt");
			vektorRadnik.erase(vektorRadnik.begin(), vektorRadnik.end());
			while (true)
			{
				file2 >> noviRadnik.ime >> noviRadnik.prezime >> noviRadnik.grad >> noviRadnik.radnoMjesto;
				if (file2.eof()) break;
				vektorRadnik.push_back(noviRadnik);
			}
			for (int i = 0; i < vektorRadnik.size(); i++)
			{
				std::cout << vektorRadnik[i].getIme() << "\t" << vektorRadnik[i].getPrezime() << "\t" << vektorRadnik[i].getGrad() << "\t" << vektorRadnik[i].getRadnoMjesto() << std::endl;
			}
			file2.close();
			break;
		case 7:
			std::cout << "-----------ISPIS REZERVACIJA-----------" << std::endl;
			file2.close();
			file2.open("rezervacije.txt");
			vektorRezervacije.erase(vektorRezervacije.begin(), vektorRezervacije.end());
			while(true)
			{
				file2 >> nova_rezervacija.nazivHotela >> nova_rezervacija.osoba.ime >> nova_rezervacija.osoba.prezime >> nova_rezervacija.cijena >> nova_rezervacija.zauzetaSoba >> nova_rezervacija.datum1 >> nova_rezervacija.datum2;
				if (file2.eof()) break;
				vektorRezervacije.push_back(nova_rezervacija);
			}
			std::cout << "Naziv hotela" << "\t" << "Ime osobe" << "\t" << "Prezime osobe \t Cijena Rezervacije \t Zauzeta Soba \t Datum rezervisanja \t Datum odjave" << std::endl;
			for(int i=0;i<vektorRezervacije.size();i++)
			{
				std::cout << vektorRezervacije[i].nazivHotela << "\t\t" << vektorRezervacije[i].osoba.ime << "\t\t" << vektorRezervacije[i].osoba.prezime << "\t\t" << vektorRezervacije[i].cijena << "\t\t    " << vektorRezervacije[i].zauzetaSoba << "\t\t     " << vektorRezervacije[i].datum1 << "\t\t     "<<vektorRezervacije[i].datum2 << std::endl;
				std::cout << std::endl;
			}
			break;
		case 99:
			goto ponovo;
			break;
		default:
			break;
		}
	} while (*izbor > 0 && *izbor < 8);
	break;
		}else
		{
		std::cout << "Username i password su netacni!"<<std::endl;
		goto ponovo;
		}
case 2:
	std::cout << "--------PREGLED-HOTELA----------" << std::endl;
	file2.close();
	file2.open("hoteli.txt");
	while (true)
	{
		file2 >> novi_hotel.naziv >> novi_hotel.brUposlenih >> novi_hotel.brSpratova >> novi_hotel.brSobaPoSpratu;
		if (file2.eof()) break;
		vektorHotela.push_back(novi_hotel);
	}
	std::cout << "Ime hotela " << "\t" << "Broj uposlenih" << "\t" << "Broj spratova" << "\t" << "Broj soba po spratu" << std::endl;
	for (int i = 0; i < vektorHotela.size(); i++)
	{
		std::cout << vektorHotela[i].naziv << "\t\t\t" << vektorHotela[i].brUposlenih << "\t\t" << vektorHotela[i].brSpratova << "\t\t" << vektorHotela[i].brSobaPoSpratu << std::endl;
	}
	goto ponovo;
	break;
case 3:
	glavniIzbor = 0;
ponovo1:do {
	std::cout << "Molimo prijavite se za nastavak!" << std::endl;
	std::cout << "1.Kreiraj novi racun" << std::endl;
	std::cout << "2.Login u vec postojeci" << std::endl;
	std::cout << "99.Exit" << std::endl;
	std::cin >> glavniIzbor;
	std::cin.ignore();
	if(glavniIzbor==99)
	{
		goto ponovo;
	}
} while (glavniIzbor < 0 || glavniIzbor>2);
std::cout << glavniIzbor << std::endl;
switch (glavniIzbor)
{
case 1:
	std::cin >> novi_korisnik;
	std::cout << "Nalog uspjesno stvoren!" << std::endl;
	std::cout << "Molimo login za nastavak!" << std::endl;
	goto ponovo1;
	break;
case 2:
	std::cout << "Username: ";
	std::cin >> username;
	std::cout << "Password: ";
	std::cin >> password;
	file2.close();
	file2.open("korisnici.txt");
	vektorKorisnici.erase(vektorKorisnici.begin(), vektorKorisnici.end());
	while (true)
	{
		file2 >> novi_korisnik.ime >> novi_korisnik.prezime >> novi_korisnik.grad >> novi_korisnik.username >> novi_korisnik.password;
		if (file2.eof()) break;
		vektorKorisnici.push_back(novi_korisnik);
	}
	loginan = false;
	file2.close();
	for (int i = 0; i < vektorKorisnici.size(); i++)
	{
		if (vektorKorisnici[i].username == username && vektorKorisnici[i].password == password)
		{
			std::cout << "Login uspjesan!" << std::endl;
			loginan = true;
			tempIme = vektorKorisnici[i].ime;
			tempPrezime = vektorKorisnici[i].prezime;
			tempUsername = username;
			tempPassword = password;
		}
	}
	if (!loginan) {
		std::cout << "Login nije uspjesan!" << std::endl;
		goto ponovo;
	}
		if (loginan)
	{
		ponovo4:do
		{
			std::cout << "1.Pogledaj svoje rezervacije" << std::endl;
			std::cout << "2.Rezervisi" << std::endl;
			std::cout << "99.Exit" << std::endl;
			std::cin >> ab;
			std::cin.ignore();
			if (ab == 99) goto ponovo;
		} while (ab < 0 || ab>2);
		switch(ab)
		{
		case 1:
			str = "";
			str = tempIme + "_" + tempPrezime + ".txt";
			file2.close();
			file2.open(str.c_str());
			vektorRezervacije.erase(vektorRezervacije.begin(), vektorRezervacije.end());
			while (true)
			{
				file2 >> nova_rezervacija.nazivHotela >> nova_rezervacija.osoba.ime >> nova_rezervacija.osoba.prezime >> nova_rezervacija.cijena >> nova_rezervacija.zauzetaSoba >> nova_rezervacija.datum1 >> nova_rezervacija.datum2;
				if (file2.eof()) break;
				vektorRezervacije.push_back(nova_rezervacija);
			}
			
			if(vektorRezervacije.size()==0)
			{
				std::cout << "Nemate rezervisanih soba!" << std::endl;
				system("pause");
				goto ponovo4;
			}else
			{
				std::cout << "Naziv hotela" << "\t" << "Ime osobe" << "\t" << "Prezime osobe \t Cijena Rezervacije \t Zauzeta Soba \t Datum rezervisanja \t Broj dana" << std::endl;
			for (int i = 0; i < vektorRezervacije.size(); i++)
			{
				std::cout << vektorRezervacije[i].nazivHotela << "\t\t" << vektorRezervacije[i].osoba.ime << "\t\t" << vektorRezervacije[i].osoba.prezime << "\t\t" << vektorRezervacije[i].cijena << "\t\t    " << vektorRezervacije[i].zauzetaSoba << "\t\t     " << vektorRezervacije[i].datum1 << "\t\t     " << vektorRezervacije[i].datum2 << std::endl;
				std::cout << std::endl;
			}
			
			}
			goto ponovo4;
			break;
		case 2:
			for (int i = 0; i < hoteli.size(); i++)
			{
				std::cout << hoteli[i] << std::endl;
			}
			std::cout << "Unesite ime hotela u kojem zelite rezervaciju:";
			std::cin >> rezervacijaString;
			file2.close();
			file2.open("imenaHotela.txt");
			imenaHotela.erase(imenaHotela.begin(), imenaHotela.end());
			while (true) {
				file2 >> pomocni;
				if (file2.eof()) break;
				imenaHotela.push_back(pomocni);
			}
			bool nasao3 = false;
			for (int i = 0; i < imenaHotela.size(); i++)
			{

				if (toLower(rezervacijaString) == toLower(imenaHotela[i]))
				{
					nasao3 = true;
					str = imenaHotela[i];
					std::cout << "Nasao sam ga!" << std::endl;
					file2.close();
					pomocni = "";
					pomocni = toLower(rezervacijaString) + ".txt";
					file2.open(pomocni.c_str());
					pomocniVektor.erase(pomocniVektor.begin(), pomocniVektor.end());
					while (true) {
						file2 >> pomoc.sprat >> pomoc.broj >> pomoc.cijena >> pomoc.vrsta >> pomoc.status;
						pomocniVektor.push_back(pomoc);
						if (file2.eof()) break;
					}
					izborMijenanje = 0;
					do {
						std::cout << "Koju vrstu sobe trazite?" << std::endl;
						std::cout << "1.Jednosobna" << std::endl;
						std::cout << "2.Dvosobna" << std::endl;
						std::cout << "3.Suite" << std::endl;
						std::cin >> izborMijenanje;
						std::cin.ignore();
					} while (izborMijenanje < 0 || izborMijenanje>3);
					ime = "";
					if (izborMijenanje == 1) ime = "jednosobna";
					if (izborMijenanje == 2) ime = "dvosobna";
					if (izborMijenanje == 3) ime = "suite-room";
					std::cout << "Sprat sobe" << "\t" << "Broj sobe" << "\t" << "Cijena sobe" << "\t" << "Vrsta sobe" << "\t" << "Status sobe" << std::endl;
					for (int i = 0; i < pomocniVektor.size() - 1; i++)
					{
						if (pomocniVektor[i].vrsta == ime && pomocniVektor[i].status == "slobodna")
						{
							std::cout << pomocniVektor[i].sprat << "\t\t" << pomocniVektor[i].broj << "\t\t" << pomocniVektor[i].cijena << "\t\t" << pomocniVektor[i].vrsta << "\t" << pomocniVektor[i].status << std::endl;
						}
					}
					std::cout << "Unesite broj sobe koju zelite rezervisati: ";
					std::cin >> brSobe;
					bool uspjesno = false;
					for (int i = 0; i < pomocniVektor.size() - 1; i++)
					{
						if (pomocniVektor[i].broj == brSobe && pomocniVektor[i].status=="slobodna" && pomocniVektor[i].vrsta==ime)
						{
							std::cout << "Sprat sobe" << "\t" << "Broj sobe" << "\t" << "Cijena sobe" << "\t" << "Vrsta sobe" << "\t" << "Status sobe" << std::endl;
							std::cout << pomocniVektor[brSobe - 1].sprat << "\t\t" << pomocniVektor[brSobe - 1].broj << "\t\t" << pomocniVektor[brSobe - 1].cijena << "\t\t" << pomocniVektor[brSobe - 1].vrsta << "\t" << pomocniVektor[brSobe - 1].status << std::endl;
							uspjesno = true;
						}
					}
					file2.close();
					zadnjiIzbor = 0;
					if(uspjesno)
					{
						int brDana;
						std::cout << "Koliko dana? : ";
						std::cin >> brDana;
						std::cin.ignore();
					do
					{
						std::cout << "Potvrda" << std::endl;
						std::cout << "1.DA" << std::endl;
						std::cout << "2.NE" << std::endl;
						std::cin >> zadnjiIzbor;
						std::cin.ignore();
					} while (zadnjiIzbor < 0 || zadnjiIzbor>2);
					switch (zadnjiIzbor)
					{
					case 1:
					{
						struct tm newtime;
						time_t now = time(0);
						localtime_s(&newtime, &now);
						mjesec = 1 + newtime.tm_mon;
						godina = 1900 + newtime.tm_year;
						dan = newtime.tm_mday;
						file2.close();
						file2.open(pomocni.c_str());
						ulaz2.close();
						ulaz2.open("rezervacije.txt",std::ios::app);
						ulaz3.close();
						noviString = "";
						noviString = tempIme + "_" + tempPrezime + ".txt";
						ulaz3.open(noviString.c_str(), std::ios::app);
						pomocniVektor.erase(pomocniVektor.begin(), pomocniVektor.end());
						while (true) {
							file2 >> pomoc.sprat >> pomoc.broj >> pomoc.cijena >> pomoc.vrsta >> pomoc.status;
							if (file2.eof()) break;
							pomocniVektor.push_back(pomoc);
						}
						
						for (int i = 0; i < pomocniVektor.size(); i++)
						{
							if (pomocniVektor[i].broj == brSobe && pomocniVektor[i].status=="slobodna" && pomocniVektor[i].vrsta==ime)
							{
								pomocniVektor[i].status = "Rezervisana";
								nova_rezervacija.osoba.ime = tempIme;
								nova_rezervacija.osoba.prezime = tempPrezime;
								nova_rezervacija.cijena = pomocniVektor[i].cijena*brDana;
								nova_rezervacija.zauzetaSoba = pomocniVektor[i].broj;
								nova_rezervacija.datumRezervacije.dan = dan;
								nova_rezervacija.datumRezervacije.mjesec = mjesec;
								nova_rezervacija.datumRezervacije.godina = godina;
								nova_rezervacija.brDana = brDana;
								ulaz2 << str << "\t" << nova_rezervacija.osoba.ime << "\t" << nova_rezervacija.osoba.prezime << "\t" << nova_rezervacija.cijena << "\t" << nova_rezervacija.zauzetaSoba << "\t" << nova_rezervacija.datumRezervacije.dan << "_" << nova_rezervacija.datumRezervacije.mjesec << "_" << nova_rezervacija.datumRezervacije.godina << "\t" << nova_rezervacija.brDana<< std::endl;
								ulaz3 << str << "\t" << nova_rezervacija.osoba.ime << "\t" << nova_rezervacija.osoba.prezime << "\t" << nova_rezervacija.cijena << "\t" << nova_rezervacija.zauzetaSoba << "\t" << nova_rezervacija.datumRezervacije.dan << "_" << nova_rezervacija.datumRezervacije.mjesec << "_" << nova_rezervacija.datumRezervacije.godina << "\t" << nova_rezervacija.brDana<< std::endl;
								std::cout << "Rezervacija uspjesna!" << std::endl;
							}
						}
						ulaz3.close();
						ulaz2.close();
						ulaz.open(pomocni.c_str());
						for (int j = 0; j < pomocniVektor.size(); j++)
						{
							ulaz << pomocniVektor[j].sprat << "\t\t" << pomocniVektor[j].broj << "\t\t" << pomocniVektor[j].cijena << "\t\t" << pomocniVektor[j].vrsta << "\t\t" << pomocniVektor[j].status << std::endl;
						}
						ulaz.close();
						file.close();
						goto ponovo4;
					}
					break;
					case 2:
					{
						break;
					}
					}
					}
					else
					{
						std::cout << "Datu sobu nije moguce rezervisati!" << std::endl;
						break;
					}
				}
			}
			if(!nasao3)
			{
				std::cout << "Hotel sa datim imenom ne postoji!" << std::endl;
				goto ponovo4;
			}
			break;
		}
	
	}
	break;
}



}
	return 0;
}