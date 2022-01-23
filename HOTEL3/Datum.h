#pragma once
#include <fstream>
class Datum
{
public:
	int dan;
	int mjesec;
	int godina;
	Datum();
	void setDan();
	void setGodina();
	void setMjesec();
	int getDan();
	int getMjesec();
	int getGodina();
	friend std::istream& operator>>(std::istream& stream, Datum& d);
	friend std::ostream& operator<<(std::ostream& stream, Datum& d);
	~Datum() = default;
};

