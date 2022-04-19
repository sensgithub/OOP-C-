#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class CBirthdate
{
public:
	CBirthdate() {}
	~CBirthdate(){}
	CBirthdate(const int& day, const int& month, const int& year)
	{
		iday = day;
		imonth = month;
		iyear = year;
	}

	CBirthdate operator=(const CBirthdate& obj)
	{
		iday = obj.iday;
		imonth = obj.imonth;
		iyear = obj.iyear;
		return(*this);
	}
	friend bool operator==(const CBirthdate& date_1, const CBirthdate& date_2)
	{
		return ((date_1.iday == date_2.iday)
			&& (date_1.imonth == date_2.imonth)
			&& (date_1.iyear == date_2.iyear));
	}
	friend bool operator<(const CBirthdate& date_1, const CBirthdate& date_2)
	{
		if (date_1.iyear < date_2.iyear)
			return true;
		else if ((date_1.iyear == date_2.iyear) &&
			(date_1.imonth < date_2.imonth))
			return true;
		else if ((date_1.iyear == date_2.iyear) &&
			(date_1.imonth == date_2.imonth) &&
			(date_1.iday < date_2.iday))
			return true;
		return false;
	}
	friend bool operator>(const CBirthdate& date_1, const CBirthdate& date_2)
	{
		if (!(date_1 == date_2) && !(date_1 < date_2))
			return true;
		else return false;
	}
	ostream& output(ostream& out) const
	{
		out << iday << " " << imonth << " " << iyear << endl;
		return out;
	}
	istream& input(istream& in)
	{
		if (&in == &cin)
		{
			cout << "Day:"; cin >> iday;
			cout << "Month:"; cin >> imonth;
			cout << "Year:"; cin >> iyear;
		}
		else
		{
			in >> iday >> imonth >> iyear;
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, CBirthdate& date)
	{
		return date.output(out);
	}
	friend istream& operator>>(istream& in, CBirthdate& date)
	{
		return date.input(in);
	}

	void Setiday(const int& day)
	{
		iday = day;
	}
	void Setimonth(const int& month)
	{
		imonth = month;
	}
	void Setiyear(const int& year)
	{
		iyear = year;
	}
	const int& Getiday()const
	{
		return iday;
	}
	const int& Getimonth()const
	{
		return imonth;
	}
	const int& Getiyear()const
	{
		return iyear;
	}

private:
	unsigned int iday;
	unsigned int imonth;
	unsigned int iyear;
};


class CStudent

{
public:
CStudent(string Name) 
	:m_strName(Name) {}
~CStudent() {}
private:
	string m_strName;
	CBirthdate bdate;

};

int main()
{
	CBirthdate date_1, date_2;
	cout << "Date 1:";
	cin >> date_1;
	cout << "Date 2:" << endl;
	cin >> date_2;
	cout << endl;
	if (date_1 < date_2)
		cout << date_1 << " < " << date_2 << endl;
	else if (date_1 == date_2)
		cout << date_1 << " = " << date_2 << endl;
	else cout <<  date_1 << " > " << date_2 << endl;
	ifstream iFile("Dates.txt");
	system("pause");
	return 0;
}