#pragma once
#include "Osoba.h"
#define _CRT_SECURE_NO_WARNINGS
class Korisnik: public Osoba
{
public:
	std::string username;
	std::string password;
	void setUsername();
	void setPassword();
	std::string getUsername();
	std::string getPassword();
	friend std::istream& operator>>(std::istream& stream, Korisnik& k);
	friend std::ostream& operator<<(std::ostream& stream, Korisnik& k);
	~Korisnik() = default;
};

