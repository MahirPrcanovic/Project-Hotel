#include "Soba.h"

#include <iostream>

Soba::Soba()
{
	this->brSobe = 13;
}

Soba::Soba(int broj, int sprat, float cijena)
{
	this->cijenaSobe = cijena;
	this->spratSobe = sprat;
	this->brSobe = broj;
}

void Soba::setBrSobe()
{
	std::cout << "Unesite broj sobe: ";
	std::cin >> this->brSobe;
	std::cin.ignore();
}

void Soba::setVrsta()
{
	auto izbor = std::make_shared<int>();
	do
	{
		std::cout << "-----------VRSTA SOBE-------------\n";
		std::cout << "1.JednoKrevetna\n";
		std::cout << "2.Dvokrevetna\n";
		std::cout << "3.Suite\n";
		std::cout << "Unesite vrijednost (1-3):";
		std::cin >> *izbor;
	} while (*izbor < 1 || *izbor>3);
	this->vrstaSobe = Vrsta(*izbor);
}

void Soba::setStatus()
{
	auto izbor = std::make_shared<int>();
	do
	{
		std::cout << "-----------STATUS SOBE-------------\n";
		std::cout << "1.Slobodna\n";
		std::cout << "2.Zauzeta\n";
		std::cout << "3.Rezervisana\n";
		std::cout << "Unesite vrijednost (1-3):";
		std::cin >> *izbor;
		std::cout << "___________________________________________________\n";
	} while (*izbor < 1 || *izbor>3);
	this->statusSobe = Status(*izbor);
}

void Soba::setSpratSobe()
{
	std::cout << "Unesite sprat na kojem se nalazi soba: ";
	std::cin >> this->spratSobe;
	std::cin.ignore();
}

void Soba::setCijena()
{
	std::cout << "Unesite cijenu sobe: ";
	std::cin >> this->cijenaSobe;
	std::cin.ignore();
}

int Soba::getbrSobe()
{
	return this->brSobe;
}

Vrsta Soba::getVrsta()
{
	return this->vrstaSobe;
}

Status Soba::getStatus()
{
	return this->statusSobe;
}

int Soba::getSpratSobe()
{
	return this->spratSobe;
}

float Soba::getCijenaSobe()
{
	return this->cijenaSobe;
}

std::istream& operator>>(std::istream& stream, Soba& s)
{
	s.setBrSobe();
	s.setVrsta();
	s.setStatus();
	s.setSpratSobe();
	s.setCijena();
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Soba& s)
{
	std::cout << "Broj sobe: " << s.getbrSobe() << "\n";
	std::cout << "Vrsta sobe: " << s.nazivVrste(static_cast<int>(s.getVrsta())) << "\n";
	std::cout << "Status sobe: " << s.nazivStatusa(static_cast<int>(s.getStatus())) << "\n";
	std::cout << "Sprat sobe: " << s.getSpratSobe() << "\n";
	std::cout << "Cijena sobe: " << s.getCijenaSobe() << "\n";
	return stream;
}
std::string Soba::nazivStatusa(int broj)
{
	switch (broj)
	{
	case 1:
		return "slobodna";
		break;
	case 2:
		return "zauzeta";
		break;
	case 3:
		return "rezervisana";
		break;
	default:
		return "nepoznato";
	}
}
std::string Soba::nazivVrste(int broj)
{
	switch (broj)
	{
	case 1:
		return "jednosobna";
		break;
	case 2:
		return "dvosobna";
		break;
	case 3:
		return "suite";
		break;
	default:
		return "nepoznato";
	}
}