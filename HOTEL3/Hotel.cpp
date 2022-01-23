
#include <iostream>
#include "Hotel.h"
#include <fstream>
Hotel::Hotel()
{
	this->naziv = "Untitled";
	this->brSpratova = NULL;
	this->brSobaPoSpratu = NULL;
	this->brUposlenih = NULL;
	
}

Hotel::Hotel(int brSpr, int brSobaPS, std::string n, int brUpos)
{
	this->brSpratova = brSpr;
	this->brSobaPoSpratu = brSobaPS;
	this->naziv = n;
	this->brUposlenih = brUpos;
}

void Hotel::setBrSpratova()
{
	std::cout << "Unesite broj spratova: ";
	std::cin >> this->brSpratova;
	std::cin.ignore();
}

void Hotel::setBrSobaPoSpratu()
{
	std::cout << "Unesite broj soba po spratu: ";
	std::cin >> this->brSobaPoSpratu;
	std::cin.ignore();
}

void Hotel::setNaziv()
{
	std::string nazivHotela;
	std::cout << "Unesite naziv hotela: ";
	std::cin >> nazivHotela;
	for(int i=0;i<nazivHotela.length();i++)
	{
		if(i==0)
		{
			nazivHotela[i] = toupper(nazivHotela[i]);
		}else
		{
			nazivHotela[i] = tolower(nazivHotela[i]);
		}
	}
	this->naziv = nazivHotela;
}

void Hotel::setBrUposlenih()
{
	std::cout << "Unesite broj uposlenih: ";
	std::cin >> this->brUposlenih;
	std::cin.ignore();
}

void Hotel::setSoba()
{
	Soba a;

	this->Sobe.emplace_back(a);
}

int Hotel::getBrSpratova()
{
	return this->brSpratova;
}

int Hotel::getBrSobaPoSpratu()
{
	return this->brSobaPoSpratu;
}

int Hotel::getBrUposlenih()
{
	return this->brUposlenih;
}

std::string Hotel::getNaziv()
{
	return this->naziv;
}

std::vector<Soba>& Hotel::getSobe()
{
	return this->Sobe;
}

std::istream& operator>>(std::istream& stream, Hotel& h)
{
	h.setNaziv();
	h.setBrUposlenih();
	h.setBrSpratova();
	h.setBrSobaPoSpratu();
	std::ofstream file;
	std::string filename = h.getNaziv() + ".txt";
	std::ofstream file2;
	file2.open("hoteli.txt",std::ios::app);
	file.open(filename.c_str(), std::ios::app);
	//SpratSobe BrojSobe CijenaSobe VrstaSobe StatusSobe
	//file.open("sobe.txt", std::ios::app);
	srand(time(0));
	rand();
	int brojac = 1;
	for (int i = 1; i <= h.getBrSpratova(); i++)
	{
		for (int j = 1; j <= h.getBrSobaPoSpratu(); j++)
		{
			int random_br = rand() % 3 + 1;
			int cijena2;
			std::string vrsta;
			std::string status;
			if (random_br == 1) cijena2 = 25, vrsta = "jednosobna", status = "slobodna";
			if (random_br == 2) cijena2 = 40, vrsta = "dvosobna", status = "slobodna";
			if (random_br == 3) cijena2 = 100, vrsta = "suite-room", status = "slobodna";
			file << i << "\t\t" << brojac << "\t\t" << cijena2 << "\t\t" << vrsta << "\t\t" << status << std::endl;

			brojac++;
		}
	}
	file2 << h.naziv << " " << h.brUposlenih << " " << h.brSpratova << " " << h.brSobaPoSpratu << std::endl;
	//file << a.getSpratSobe() << "\t\t" << a.getbrSobe() << "\t\t" << a.getCijenaSobe() << "\t\t" << a.nazivVrste(a.getVrsta()) << "\t\t" << a.nazivStatusa(a.getStatus()) << std::endl;
	file.close();
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Hotel& h)
{
	std::cout << "Naziv hotela: " << h.getNaziv() << " \n";
	std::cout << "Broj uposlenih: " << h.getBrUposlenih() << " \n";
	std::cout << "Broj spratova: " << h.getBrSpratova() << " \n";
	std::cout << "Broj soba po spratu: " << h.getBrSobaPoSpratu() << " \n";
	/*for (auto& soba : h.getSobe())
	{
		std::cout << soba;
	}*/
	return stream;
}

