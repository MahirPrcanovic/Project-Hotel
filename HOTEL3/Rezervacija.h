#pragma once
#include "Datum.h"
#include "Osoba.h"
#define _CRT_SECURE_NO_WARNINGS
class Rezervacija
{
public:
	Osoba osoba;
	Datum datumRezervacije;
	Datum datumOdjave;
	float cijena;
	std::string nazivHotela;
	std::string datum1;
	std::string datum2;
	int brDana;
	int zauzetaSoba;
	void setOsoba();
	void setDatumRezervacije();
	void setDatumOdjave();
	void setCijena();
	void setNazivHotela();
	void setZauzetaSoba();
	Osoba& getOsoba();
	Datum& getDatumRezervacije();
	Datum& getDatumOdjave();
	float getCijena();
	std::string getNazivHotela();
	int getZauzetaSoba();
	friend std::istream& operator>>(std::istream& stream, Rezervacija& r);
	friend std::ostream& operator<<(std::ostream& stream, Rezervacija& r);
	~Rezervacija() = default;
};

