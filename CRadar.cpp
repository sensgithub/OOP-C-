#include <iostream>
#include <fstream>
#include <iterator>
#include <list>
#include <algorithm>
#include <string>
#define FILE_EXCEPTION 0
#define FILE_ERROR 1
using namespace std;

class cRadar 
{
private:
	string reg_no;
	int m_speed;
public:

	cRadar() :
		reg_no("BMW"),
		m_speed(131) {}

	cRadar(const string& number, const int& speed) :
		reg_no(number), m_speed(speed)
	{}

	cRadar(const cRadar& a) :
		reg_no(a.reg_no),
		m_speed(a.m_speed) {}

	const int& get_speed()const {
		return m_speed;
	}
	void setregnumber(const string& reg) {
		reg_no = reg;
	}
	const string& get_regnumber()const {
		return reg_no;
	}
	void setspeed(const int& speed) {
		m_speed = speed;
	}
	bool operator == (const cRadar& obj) {
		return reg_no == obj.get_regnumber();
	}

	ostream& Output(ostream& out)const;
	istream& Input(istream& in);

	friend istream& operator >> (istream& in, cRadar& obj);
	friend ostream& operator << (ostream& out, const cRadar& obj);

};

ostream& cRadar::Output(ostream& out)const {
	out << reg_no << " " << m_speed;
	return out;
}

istream& cRadar::Input(istream& in) {
	if (&in == &cin) {
		cout << "Enter reg number: ";
		cin >> reg_no;
		cout << "Enter speed: ";
		cin >> m_speed;
	}
	else {
		in >> reg_no >> m_speed;
	}
	return in;
}

ostream& operator << (ostream& out, const cRadar& obj) {
	obj.Output(out);
	return out;
}

istream& operator >> (istream& in, cRadar& obj) {
	obj.Input(in);
	return in;
}
class CRadarCollection : cRadar
{
private:
	list <cRadar> database;
public:
	CRadarCollection(const list<cRadar>& l) {
		database = l;
	}
	void Car_Register(const char* filename) {
		fstream ifile(filename, ios_base::in);
		if (ifile.good()) {
			copy(istream_iterator<cRadar>(ifile), istream_iterator<cRadar>(), back_inserter(database));
		}
		else
			throw FILE_ERROR;
	}
	string owner_to_PN(const string& own) {
		cRadar fake_car("",1);
		auto it = find(database.begin(), database.end(), fake_car);
		if (it != database.end())
			return (*it).get_regnumber();
		else
			return "Not found. ";
	}
	friend ostream& operator <<(ostream& out, const Car_Register& obj) {
		copy(obj.database.begin(), obj.database.end(), ostream_iterator<cRadar>(out, "\n"));
		return out;
	}
	friend istream& operator >>(istream& in, Car_Register& obj) {
		copy(istream_iterator<cRadar>(in), istream_iterator<cRadar>(), back_inserter(obj.database));
		return in;
	}
};

int main()
{

}