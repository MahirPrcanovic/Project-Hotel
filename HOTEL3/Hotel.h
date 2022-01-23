
#pragma once
#include <vector>

#include "Soba.h"
#define _CRT_SECURE_NO_WARNINGS
class Hotel
{
public:
	int brSpratova;
	int brSobaPoSpratu;
	std::string naziv;
	int brUposlenih;
	std::vector<Soba> Sobe;
	Hotel();
	Hotel(int brSpr, int brSobaPS, std::string n, int brUpos);
	void setBrSpratova();
	void setBrSobaPoSpratu();
	void setNaziv();
	void setBrUposlenih();
	void setSoba();
	int getBrSpratova();
	int getBrSobaPoSpratu();
	int getBrUposlenih();
	std::string getNaziv();
	std::vector<Soba>& getSobe();
	friend std::istream& operator>>(std::istream& stream, Hotel& h);
	friend std::ostream& operator<<(std::ostream& stream, Hotel& h);
};
