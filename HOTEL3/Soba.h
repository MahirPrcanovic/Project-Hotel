#pragma once
#include <ostream>
#include <string>
enum Vrsta { jednosobna = 1, dvosobna, suite };
enum Status { slobodna = 1, zauzeta, rezervisana };
class Soba
{
public:
	int brSobe;
	int spratSobe;
	float cijenaSobe;
	Vrsta vrstaSobe;
	Status statusSobe;
	Soba();
	Soba(int broj, int sprat, float cijena);
	//SETTERI----------------
	void setBrSobe();
	void setVrsta();
	void setStatus();
	void setSpratSobe();
	void setCijena();
	//------------------------
	//GETTERI ------------------
	int getbrSobe();
	Vrsta getVrsta();
	Status getStatus();
	int getSpratSobe();
	float getCijenaSobe();
	//---------------------------
	//POMOCNE--------------------
	std::string nazivVrste(int broj);
	std::string nazivStatusa(int broj);
	//-----------------------------
	//OPERATORI--------------------
	friend std::istream& operator>>(std::istream& stream, Soba& s);
	friend std::ostream& operator<<(std::ostream& stream, Soba& s);
	//-----------------------------
	//~Soba() = default;
};
