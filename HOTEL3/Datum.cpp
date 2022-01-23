#include "Datum.h"

#include <iostream>

Datum::Datum()
{
	this->dan = 1;
	this->mjesec = 1;
	this->godina = 1970;
}

void Datum::setDan()
{
	std::cout << "Unesite dan: ";
	std::cin >> this->dan;
	std::cin.ignore();
}

void Datum::setGodina()
{
	std::cout << "Unesite godinu: ";
	std::cin >> this->godina;
	std::cin.ignore();
}

void Datum::setMjesec()
{
	std::cout << "Unesite mjesec: ";
	std::cin >> this->mjesec;
	std::cin.ignore();
}

int Datum::getDan()
{
	return this->dan;
}

int Datum::getMjesec()
{
	return this->mjesec;
}

int Datum::getGodina()
{
	return this->godina;
}

std::istream& operator>>(std::istream& stream, Datum& d)
{
	d.setDan();
	d.setMjesec();
	d.setGodina();
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Datum& d)
{
	std::cout << "-----------Datum---------" << std::endl;
	std::cout << "Dan: " << d.getDan() << std::endl;
	std::cout << "Mjesec: " << d.getMjesec() << std::endl;
	std::cout << "Godina: " << d.getGodina() << std::endl;
	return stream;
}
