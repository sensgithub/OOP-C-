#include <iostream>
#include <string>
using namespace std;
class CCar{
private:
	string m_model;
	int m_power;
public:
	void setmodel(const string&model){ 
		m_model=model;
	}
	const string&getmodel()const{
		return m_model;
	} 
   void setpower(const int &power){
		m_power = power ;
   }
	const int&getpower()const{
		return m_power;
	}

	CCar():          
		m_model("BMW"),
		m_power(131){}

	CCar(const int&power,const string&model):
	m_model(model),
		m_power(power){}

	CCar(const CCar&a):
		m_model(a.m_model),
		m_power(a.m_power){}

	ostream & Output(ostream&out)const{
		out<<m_model<<" "
			<<m_power<<" "
			<<endl;
		return out;}
	istream&Input(istream&in){
		if(&in==&cin){
			cout<<"Model:";cin>>m_model;
			cout<<"Power:";cin>>m_power;
		}
		else{   
			in>>m_model>>m_power;
		}
		return in;
	}
	friend ostream&operator<<(ostream&out,const CCar& obj){
			obj.Output(out);
			return out;}
	friend istream&operator>>(istream&in,CCar& obj){
			return obj.Input(in);
		}
};

	class COwner :
	public CCar {
private:
	string m_strName;
	string m_strRegNumber;
public:
	void setname(const string&name){ 
		m_strName=name;
	}
	const string&getname()const{
		return m_strName;
	} 
   void setRN(const string &RN){
		m_strRegNumber = RN ;
   }
	const string&getRN()const{
		return m_strRegNumber;
	}

	COwner() : CCar(),
		m_strRegNumber("B 6825 KT") {}
	COwner(const string&name,
		const string&RN,
		const string&model, 
		const int&power,
		const CCar& a) :
		m_strRegNumber(RN), m_strName(name) {}
COwner(const string&name,
		const string&RN,
		const string&model, 
		const int&power) :
		m_strRegNumber("B 6825 KT"), m_strName(name) {}
	COwner(const COwner& a) :
		m_strRegNumber(a.m_strRegNumber),
		m_strName(a.m_strName) {}

			ostream & Output(ostream&out)const{
		out<<m_strName<<" "
			<<m_strRegNumber<<" "
			<<endl;
		return out;}
	istream&Input(istream&in){
		if(&in==&cin){
			cout<<"Name:";cin>>m_strName;
			cout<<"RegNumber:";cin>>m_strRegNumber;
		}
		else{   
			in>>m_strName>>m_strRegNumber;
		}
		return in;
	}
		friend ostream&operator<<(ostream&out,const COwner& obj){
			obj.Output(out);
			return out;
		}
		friend istream&operator>>(istream&in,COwner&obj){
			return obj.Input(in);
		}
	};

	int main()
	{
		COwner a1("Ivan","B 9310 KT","Audi",130),
			a2("Boris","B 1341 KT", "VW", 98);
		cout << a1.getname() << " " << a1.getRN() << " " << a1.getmodel() << " " << a1.getpower()<< endl;
		cout << a2.getname() << " " << a2.getRN() << " " << a2.getmodel() << " " << a2.getpower()<< endl;
		//...
		system("pause");
	}