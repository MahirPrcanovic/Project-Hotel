#include "Osoba.h"
#include <iostream>
#include <fstream>
Osoba::Osoba()
{
	this->ime = "ime";
	this->prezime = "prezime";
	this->grad = "grad";
}

void Osoba::setIme()
{
	std::cout << "Unesite ime osobe: ";
	getline(std::cin, this->ime);
}

void Osoba::setPrezime()
{
	std::cout << "Unesite prezime osobe: ";
	getline(std::cin, this->prezime);
}

void Osoba::setGrad()
{
	std::cout << "Unesite grad osobe: ";
	getline(std::cin, this->grad);
}

std::string Osoba::getIme()
{
	return this->ime;
}

std::string Osoba::getPrezime()
{
	return this->prezime;
}

std::string Osoba::getGrad()
{
	return this->grad;
}

//void Osoba::unosOsobe()
//{
//	std::cout << "\n****UNOS OSOBE****\n";
//	this->setIme();
//	this->setPrezime();
//	this->setGrad();
//}
//
//void Osoba::ispisOsobe()
//{
//	std::cout << "\n****OSOBA****\n";
//	std::cout << "Ime: " << this->getIme();
//	std::cout << "\nPrezime: " << this->getPrezime();
//	std::cout << "\nGrad: " << this->getGrad();
//}

std::istream& operator>>(std::istream& stream, Osoba& o)
{
	std::cout << "\n****UNOS OSOBE****\n";
	o.setIme();
	o.setPrezime();
	o.setGrad();
	std::ofstream file;
	file.open("osobe.txt", std::ios::app);
	file << o.getIme() << " " << o.getPrezime() << " " << o.getGrad() << std::endl;
	file.close();
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Osoba& o)
{
	stream << "\n****OSOBA****\n";
	stream << "Ime: " << o.getIme();
	stream << "\nPrezime: " << o.getPrezime();
	stream << "\nGrad: " << o.getGrad();
	stream << "---------------------------------------------" << std::endl;
	return stream;
}
