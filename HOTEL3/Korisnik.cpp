#include "Korisnik.h"
#include <fstream>
#include <iostream>
#include <vector>

void Korisnik::setUsername()
{
	std::string pomocna;
	ponovo:std::cout << "Molimo unesite zeljeni username: ";
	std::cin >>pomocna;
	std::ifstream ulaz;
	ulaz.open("korisnici.txt");
	std::string ime;
	std::string prezime;
	std::string grad;
	std::string username;
	std::string password;
	Korisnik novi_korisnik;
	bool nasao = false;
	while (true)
	{
		ulaz >> ime >> prezime >> grad >> username >>password;
		if (ulaz.eof()) break;
		if(username==pomocna)
		{
			std::cout << "Korisnik sa datim username-om vec postoji!" << std::endl;
			std::cout << "Molimo unesite opet!"<<std::endl;
			nasao = true;
			goto ponovo;
		}
	}
	
	if (!nasao) this->username = pomocna;
	ulaz.close();
}

void Korisnik::setPassword()
{
	std::cout << "Unesite zeljeni password: ";
	std::cin >> this->password;
}

std::string Korisnik::getUsername()
{
	return this->username;
}

std::string Korisnik::getPassword()
{
	return this->password;
}

std::istream& operator>>(std::istream& stream, Korisnik& k)
{
	Osoba o;
	std::cin >> o;
	k.setUsername();
	k.setPassword();
	std::ofstream ulaz;
	ulaz.open("korisnici.txt", std::ios::app);
	ulaz << o.getIme() << "\t" << o.getPrezime() << "\t" << o.getGrad() << "\t\t" << k.username << "\t" << k.password << std::endl;
	ulaz.close();
	ulaz.close();
	std::string pomocni;
	pomocni = "";
	pomocni = o.getIme() + "_" + o.getPrezime() + ".txt";
	ulaz.open(pomocni.c_str(), std::ios::app);
	return stream;
	
	
}

std::ostream& operator<<(std::ostream& stream, Korisnik& k)
{
	std::cout << "------Ispis Korisnika------" << std::endl;
	std::cout << "Ime: " << k.getIme() << std::endl;
	std::cout << "Prezime: " << k.getPrezime() << std::endl;
	std::cout << "Grad: " << k.getGrad() << std::endl;
	std::cout << "Username: " << k.getUsername() << std::endl;
	return stream;
}
