#include <iostream>
#include <list>
using namespace std;

class CEmployee {
private:
	string m_strName;
	string m_EGN;
	double m_dSalary;
	int m_iWorkHours;
public:
	virtual const double& getsalary()const = 0;
	CEmployee():
		m_strName("Ivan"),
		m_EGN("0057513000"),
		m_dSalary(500.50),
		m_iWorkHours(78)
	{}
	CEmployee(const string& name, const string& egn, const double&salary,const int&wh) :
		m_strName(name),
		m_EGN(egn),
		m_dSalary(salary),
		m_iWorkHours(wh)
	{}
	CEmployee(const CEmployee& a) :
		m_strName(a.m_strName),
		m_EGN(a.m_EGN),
		m_dSalary(a.m_dSalary),
		m_iWorkHours(a.m_iWorkHours)
	{}
	void setName(const string& name) {
		m_strName = name;
	}
	const string& getName()const {
		return m_strName;
	}
	void setEGN(const string& egn) {
		m_EGN = egn;
	}
	const string& getEGN()const { 
		return m_EGN;
	}
	void setSalary(const double& salary) {
		m_dSalary = salary;
	}
	const double& getSalary()const {
		return m_dSalary;
	}
	void setWorkHours(const int& wh) {
		m_iWorkHours = wh;
	}
	const int& getWorkHours()const {
		return m_iWorkHours;
	}
	bool operator == (const CEmployee& obj) {
		return m_EGN == obj.getEGN();
	}
	ostream& Output(ostream& out)const
	{
		CEmployee::Output(out);
		out << m_strName << " "
			<< m_EGN << " "
			<< m_dSalary << " "
			<< m_iWorkHours << " "
			<< endl;
		return out;
	}
	istream& Input(istream& in) {
		if (&in == &cin) {
			cout << "Name: "; cin >> m_strName;
			cout << "EGN: "; cin >> m_EGN;
			cout << "Salary: "; cin >> m_dSalary;
			cout << "iWorkHours: "; cin >> m_iWorkHours;
		}
		else {
			in >> m_strName >> m_EGN >> m_dSalary >> m_iWorkHours;
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, const CEmployee& obj) {
		obj.Output(out);
		return out;
	}
	friend istream& operator >> (istream& in, CEmployee& obj)
	{
		obj.Input(in);
		return in;
	}
	friend bool operator<(const CEmployee& c1, const CEmployee& c2)
	{
		return c1.getSalary() < c2.getSalary();
	}
};
class CEmployeeContract : CEmployee {
private:
	int m_iHours;
public:
	CEmployeeContract() : CEmployee(),
		m_iHours(500) {}
    CEmployeeContract(
		const string& name,
		const string& egn,
		const double& salary,
		const int& wh, const int& hours) :
		CEmployee(name, egn, salary, wh),
		m_iHours(hours) {}
	CEmployeeContract(const CEmployeeContract& a) :
		CEmployee(a),
		m_iHours(a.m_iHours) {}

	void setiHours(const int& hours)
	{
		m_iHours = hours;
	}
	const int& getHours()
	{
		return m_iHours;
	}
};
class CEmployeeHourly : CEmployee
{
private:
	double m_dHourlyTax;
public:
	CEmployeeHourly() : CEmployee(),
		m_dHourlyTax(45.31) {}
	CEmployeeHourly(
		const string& name,
		const string& egn,
		const double& salary,
		const int& wh, const int& hours, const double&tax) :
		CEmployee(name, egn, salary, wh),
		m_dHourlyTax(tax) {}
	CEmployeeHourly(const CEmployeeHourly& a) :
		CEmployee(a),
		m_dHourlyTax(a.m_dHourlyTax) {}

	const double& getHourlyTax()
	{
		return m_dHourlyTax;
	}
};
int main()
{
	list <CEmployee> ukazateli;
}