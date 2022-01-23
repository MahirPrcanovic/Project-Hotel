#include "Radnik.h"

#include <iostream>
#include <fstream>

std::istream& operator>>(std::istream& stream, Radnik& k)
{
    std::cout << "****UNOS KORISNIKA****\n";
    k.setIme();
    k.setPrezime();
    k.setGrad();
    k.setRadnoMjesto();
    std::ofstream ulaz;
    ulaz.open("radnici.txt",std::ios::app);
    ulaz << k.getIme() << "\t\t" << k.getPrezime() << "\t\t" << k.getGrad() << "\t\t" << k.getRadnoMjesto() << std::endl;
    ulaz.close();
    return stream;
}

std::ostream& operator<<(std::ostream& stream, Radnik& k)
{
    std::cout << "****Radnik****\n";
    std::cout << "Ime: " << k.getIme() << std::endl;
    std::cout << "Prezime: " << k.getPrezime() << std::endl;
    std::cout << "Grad: " << k.getGrad() << std::endl;
    std::cout << "Radna pozicija: "<<k.getRadnoMjesto();
    std::cout << std::endl;
    return stream;
}

void Radnik::setRadnoMjesto()
{
    std::cout << "Unesite radno mjesto radnika:";
    std::cin >> this->radnoMjesto;
}

std::string Radnik::getRadnoMjesto()
{
    return this->radnoMjesto;
}
