#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Planina
{protected:
string Country;
string Mountain;
public:
	void set_Country(string C1)
	{Country=C1;}
	void set_Mountain(string M1)
	{Mountain=M1;}
	string getCountry()
	{return Country;}
	string getMountain()
	{return Mountain;}
	Planina(string C1,string M1)
	{Country=C1; Mountain=M1;}
	void print()
	{cout<<Country<<endl;
	cout<<Mountain<<endl;}
	Planina(const Planina&p)
	{Country=p.Country; Mountain=p.Mountain;}
};
class Vrah: public Planina
{protected:
string ime;
int h;
public:
	Vrah(string C1, string M1, string I1, int h1):Planina(C1,M1)
	{ime=I1; h=h1;} 
	string getime() {return ime;}
	int geth() {return h;}
	void print() {Planina::print();
	cout<<ime<<endl;
	cout<<"visochina="<<h<<endl;}
		friend istream& operator>>(istream&istr,Vrah&p)
	{istr>>p.ime>>p.h;
	return istr;}
	friend ostream& operator<<(ostream&ostr, Vrah&p)
	{ostr<<p.ime<<"-"<<p.h<<endl;
	return ostr;}
	bool operator==(Vrah&p)
	{if(ime==p.ime && h==p.h) return true;
	else return false;}
	bool operator<(Vrah&p)
	{if(h>0) return true;
	else return false;}};
	int main()
	{Vrah v1("bulgaria","Rila","Musala",2925);
	Vrah v2("bulgaria","pirin","vihren",2914);
	Vrah v3("greece","olympus","mitikas",2920);
	v1.print(); v2.print();
	Vrah m[5]={v1,v2,v3,Vrah("bulgaria","rodopi","botev",2080),Vrah("germany","Wetterstein Mountains","Zugspitze",2962)};
	ofstream file("points.txt");
for (int i=0;i<5;i++)
{cout<<m[i];
file<<m[i];}
file.close();
	system("pause");}
	