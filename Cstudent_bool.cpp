#include <iostream>
#include <string>
using namespace std;

class CAddress {
private:
	string m_street;
	string m_pcode;
	string m_town;
public:
	//set get
	void setstreet(const string& street) {      //za da pestim pamet predavame samo 1 adress prashtame stoinosta i q kopirame pri nas stava s referenciq vmesto da pishem * (snimka imam)
		//const durji da ne se promeni street promenqiki setstreet
		m_street = street;
	} //promenqme
	const string& getstreet()const {
		return m_street;
	} //samo vrushtame
	const string& getpcode()const {
		return m_pcode;
	}
	const string& gettown()const {
		return m_town;
	}
	/*CAdress(){
		m_street="studentska1";
		m_pcode="9010";     //variant e 1
		m_town="varna";}*/
	CAddress() :           //default constructor
		m_street("studentska1"),
		m_pcode("9010"),   //variant 2 po bburz i po-malko pamet
		m_town("varna") {}
	CAddress(const string& street,      //explicit constrictor
		const string& pcode,
		const string& town = "varna") :
		m_street(street),
		m_pcode(pcode),
		m_town(town) {}
	CAddress(const CAddress& a) :
		m_street(a.m_street),
		m_pcode(a.m_pcode),
		m_town(a.m_town) {}

	ostream& Output(ostream& out)const {
		out << m_street << " "
			<< m_pcode << " "
			<< m_town << endl;
		return out;
	}
	istream& Input(istream& in) {
		if (&in == &cin) {
			cout << "steet"; cin >> m_street;
			cout << "pcode:"; cin >> m_pcode;
			cout << "town:"; cin >> m_town;
		}
		else {    //fail
			in >> m_street >> m_pcode >> m_town;
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, const CAddress& obj) {
		obj.Output(out);
		return out;
	}
	friend istream& operator>>(istream& in, CAddress& obj) {
		return obj.Input(in);
	}
};
enum Gender {
	//    0    1       2
	male, female, unknown
};
class CPerson {
private:
	string m_strName;
	string m_strGender;
	string m_strEGN;
public:
	void SetName(string name)
	{
		m_strName = name;
	}
	void SetGender(string gender)
	{
		m_strGender = gender;
	}
	string GetName() {
		return m_strName;
	}
	string GetGender()
	{
		return m_strGender;
	}
	void SetEGN(string EGN)
	{
		m_strEGN = EGN;
	}
	string GetEGN()
	{
		return m_strEGN;
	}
	CPerson(const string& name, const Gender& gender, const string& EGN)
	{
		m_strName = name;
		m_strGender = gender;
		m_strEGN = EGN;
	}
	CPerson() {
		m_strName = "N/A";
		m_strGender = "unknown";
	}
	istream& Input(istream& in) {
		if (&in == &cin) {
			cout << "Name"; cin >> m_strName;
			cout << "Gender:"; cin >> m_strGender;
			cout << "EGN:"; cin >> m_strEGN;
		}
		return in;
	}
	ostream& CPerson::Output(ostream& out) const {
		out << m_strName << "  " << m_strGender << " " << m_strEGN << endl;
		return out;
	}
	~CPerson()
	{};
};
	/*bool isCorrectDateOfEGN(string yymmdd)
	{
		if (yymmdd.length() != 6)
			return false;

		int dayspermon[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int month, day, year;

		year = atoi(yymmdd.substr(0, 2).c_str());
		month = atoi(yymmdd.substr(2, 2).c_str());
		day = atoi(yymmdd.substr(4, 2).c_str());

		if (!(year != 0 && month != 0 && day != 0))
			return false;

		if (year < 0 || month < 1 || day < 1)
		{
			return false;
		}

		if (month > 13 && month < 20)
		{
			return false;
		}

		else if (month > 21 && month < 32)
		{
			month = month - 20;
		}

		else if (month > 33 && month < 40)
		{
			return false;
		}

		else if (month > 41 && month < 52)
		{
			month = month - 40;
		}

		else if (month > 52)
		{
			return false;
		}
		if (month == 2)

			if ((year % 4) == 0)

				dayspermon[2] = 29;

		if (day > dayspermon[month - 1])
		{
			return false;
		}
		return true;
	}

	bool chechEGN(string egn)

	{
		int ctrSum = 0;
		int ctrField = 0;
		int teglo[] = { 2, 4, 8, 5, 10, 9, 7, 3, 6 };

		if (egn.length() != 10)

			return false;
		long long tmpEgn = atoi(egn.c_str());

		if (tmpEgn == 0)

			return false;
		if (!isCorrectDateOfEGN(egn.substr(0, 6)))
		{

		return false;

		}
		for (int i = 0; i < egn.length() - 1; ++i)

			ctrSum += teglo[i] * atoi(egn.substr(i, 1).c_str());

		ctrField = (ctrSum % 11) % 10;

		if (ctrField != atoi(egn.substr(9, 1).c_str()))

			return false;

		else return true;
	}
};*/

class CStudent :
	public CPerson {
private:
	string m_FN;
	CAddress m_adress;

public:
	//set get
	CStudent() : CPerson(),
		m_FN("8888") {}
	CStudent(const string& name,
		const Gender& gender,
		const string& EGN, const string& FN,
		const CAddress& a) :
		CPerson(name, gender, EGN),
		m_FN(FN), m_adress(a) {}
	CStudent(const string& name,
		const Gender& gender,
		const string& EGN,/* const string& FN*/
		const CAddress& a) :
		CPerson(name, gender, EGN),
		m_FN("8888"), m_adress(a) {}


	CStudent(const CStudent& a) :
		m_FN(a.m_FN),
		m_adress(a.m_adress) {}
	//ostream& Output(ostream& out)const;
	//kum trite klasa da ima output funkcii D.R.

	istream& Input(istream& in) {
		if (&in == &cin) {
			cout << "FN:";
		}
		cin >> m_FN;
		CPerson::Input(in);
		m_adress.Input(in);
		return in;
	}
	ostream& Output(ostream& out)const {
		out << m_FN << " ";
		CPerson::Output(out);
		return out;
	}
	friend ostream& operator<<(ostream& out, const CStudent& obj) {
		obj.Output(out);
		return out;
	}
	/*out<<obj.m_FN<<" ";
	GetFN()
		out<<obj.GetName()<<" "<<obj.GetEGN()<<"";
	out<<obj.Getadress()endl;
	return out;}*/
	friend istream& operator>>(istream& in, CStudent& obj) {
		return obj.Input(in);
	}
	/* in>>obj.m_FN>>obj.m_strName>>obj.m_strEGN;
	in>>obj.m_adress;
	return in;
	*/
};

int main()
{
	CAddress a1,
		a2("dubrovnik18", "9010"),
		a3("zheleznivrata10", "9010", "Varna"),
		a4(a2);
	cout << a1.getstreet() << " " << a1.getpcode() << "  " << a1.gettown() << endl;
	cout << a2.getstreet() << " " << a2.getpcode() << "  " << a2.gettown() << endl;
	cout << a3.getstreet() << " " << a3.getpcode() << "  " << a3.gettown() << endl;
	cout << "----------------------------------" << endl;
	a1.Output(cout);
	a2.Output(cout);
	a3.Output(cout);
	a4.Output(cout);
	CStudent pesho,
		ivan("ivan", male, "004199587", "19621417", a2),
		gosho(ivan);
	CAddress b1;
	cout << b1;
	b1.Input(cin);
	b1.Output(cout);
	CStudent s1; s1.Output(cout); s1.Input(cin); s1.Output(cout);
	cout << s1;
	system("pause");
	return 0;
}