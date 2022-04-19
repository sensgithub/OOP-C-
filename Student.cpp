#include <iostream>
#include <string>
#include "Source.cpp"
#include "class.cpp"
using namespace std;

class CStudent :
	public CPerson {
private:
	string m_FN;
	CAdress m_adress;

public:
//set get
	CStudent() : CPerson(),
		m_FN("8888") {}
	CStudent(const string& name,
		const Gender& gender,
		const string& EGN, const string& FN,	
		const CAdress& a) :
		CPerson(name, gender, EGN),
		m_FN(FN), m_adress(a) {}
	CStudent(const string& name,
		const Gender& gender,
		const string& EGN,/* const string& FN*/
		const CAdress& a) :
		CPerson(name, gender, EGN),
		m_FN("8888"), m_adress(a) {}


	CStudent(const CStudent& a) :
		m_FN(a.m_FN),
		m_adress(a.m_adress) {}
	ostream& Output(ostream& out)const;
	//kum trite klasa da ima output funkcii D.R.
};

int main() {
	CAdress a1,
		a2("Dubrovnik 18", "9010"),
		a3("Jeleznivrata 10", "9010", " Varna"),
		a4(a2);
	cout << a1.GetStreet() << "  "
		<< a1.GetPCode() << "  "
		<< a1.GetTown() << endl;
	a1.Output(cout);
	CStudent pesho,
		ivan("Ivan", Gender::Male, "0041506070", "19621326", a2);
		//gosho(ivan);




		system("pause");
	return 0;
}

ostream& CStudent::Output(ostream& out) const {
	out << m_FN << " , ";
	m_adress.Output(out);out << endl;
	return out;
}