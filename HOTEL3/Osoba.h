#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
class Osoba
{

public:
	std::string ime;
	std::string prezime;
	std::string grad;
	Osoba();
	void setIme();
	void setPrezime();
	void setGrad();
	std::string getIme();
	std::string getPrezime();
	std::string getGrad();
	friend std::istream& operator>>(std::istream& stream, Osoba& o);
	friend std::ostream& operator<<(std::ostream& stream, Osoba& o);
	/*void unosOsobe();
	void ispisOsobe();*/
	~Osoba() = default;
};