#include "Osoba.h"
class Radnik :
    public Osoba
{
   

public:
    std::string radnoMjesto;
	void setRadnoMjesto();
    std::string getRadnoMjesto();
    friend std::istream& operator>>(std::istream& stream, Radnik& k);
    friend std::ostream& operator<<(std::ostream& stream, Radnik& k);
};