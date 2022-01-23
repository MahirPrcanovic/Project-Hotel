#include "Rezervacija.h"

#include <iostream>


void Rezervacija::setOsoba()
{

	std::cin >> this->osoba;
}

void Rezervacija::setDatumRezervacije()
{
	std::cin >> this->datumRezervacije;
}

void Rezervacija::setDatumOdjave()
{
	std::cin >> this->datumOdjave;
}

void Rezervacija::setCijena()
{
	std::cout << "Cijena: ";
	std::cin>>this->cijena;
	std::cin.ignore();
}

void Rezervacija::setNazivHotela()
{
	std::cout << "Unesite naziv hotela:";
	std::cin >> this->nazivHotela;
}

void Rezervacija::setZauzetaSoba()
{
	std::cout << "Unesite zauzetu sobu: ";
	std::cin >> this->zauzetaSoba;
	std::cin.ignore();
}

Osoba& Rezervacija::getOsoba()
{
	return this->osoba;
}

Datum& Rezervacija::getDatumRezervacije()
{
	return this->datumRezervacije;
}

Datum& Rezervacija::getDatumOdjave()
{
	return this->datumOdjave;
}

float Rezervacija::getCijena()
{
	return this->cijena;
}

std::string Rezervacija::getNazivHotela()
{
	return this->nazivHotela;
}

int Rezervacija::getZauzetaSoba()
{
	return this->zauzetaSoba;
}


std::istream& operator>>(std::istream& stream, Rezervacija& r)
{
	r.setNazivHotela();
	r.setDatumRezervacije();
	r.setDatumOdjave();
	r.setCijena();
	r.setOsoba();
	r.setZauzetaSoba();
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Rezervacija& r)
{
	std::cout << "-----------REZERVACIJA--------------------" << std::endl;
	std::cout << "Naziv hotela: " << r.getNazivHotela() << std::endl;
	std::cout << "Cijena rezervacije: " << r.getCijena() << std::endl;
	std::cout << "Datum rezervacije: " << r.getDatumRezervacije().dan << " " << r.getDatumRezervacije().mjesec << " " << r.getDatumRezervacije().godina << std::endl;
	std::cout << "Datum odjave: " << r.getDatumOdjave().dan << " " << r.getDatumOdjave().mjesec << " " << r.getDatumOdjave().godina << std::endl;
	std::cout << "Rezervisano na osobu: " << r.getOsoba().getIme() << " " << r.getOsoba().getPrezime() << std::endl;
	std::cout << "Zauzeta soba: " << r.getZauzetaSoba() << std::endl;
	return stream;
}
