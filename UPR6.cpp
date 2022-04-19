#include <iostream>
#include <string>

using namespace std;
template <class T, class P>
class CPair {
private:
	T first;
	P second;
public:
	CPair()
	{
		first = T();
		second = P();
	}
	CPair(const T& a, const P& b) :
		first(a), second(b) {}
	CPair(const CPair& c) :
		first(c.first), second(c.second) {}
	// set get
	void setfirst(const T& afirst)
	{
		first = afirst;
	}
	const T& getfirst()
	{
		return first;
	}
	void setsecond(const P& asecond)
	{
		second = asecond;
	}
	const P& getsecond()
	{
		return second;
	}
	// input output
	istream& Input(istream& in)
	{
		if (&in == &cin)
		{
			cout << "First: "; in >> first;
			cout << "Second: "; in >> second;
		}
		else
		{
			in << first << second;
		}
	}
	ostream& Output(ostream& out)
	{
		out << "(" << first << "," << second << ")" << endl;
		return out;
	}
	friend ostream& operator<<(ostream& out, const CPair& x)
	{
		xOutput(out);
		return out;
	}
	friend istream& operator>>(istream& in, const CPair& y)
	{
		yInput(in);
		return in;
	}
	// == < !=
	bool operator <(const CPair& obj)const
	{
		return((second < obj.second) ? true : false);
	}
	bool operator ==(const CPair& obj)const
	{
		return((second == obj.second) && ((first == obj.first)) ? true : false);
	}
	bool operator !=(const CPair& obj)const
	{
		return !((*this) == obj);
	}
	CPair& operator=(const CPair& obj) // prepredavame adresa cher referenciq CPair&
	{                                  // i s tazi funckiq promenqme stoinostite direktno
		first = obj.first;
		second = obj.second;
		return(*this);
	}
	/* CPair operator=(const CPair& obj)
	{
	CPair temp(obj);
	return temp;
	return CPair(obj);
	}*/
	CPair operator+(const CPair& obj) // tuk vrushtame kopie
	{
		CPair temp(first + obj.first, second + obj.second);
		return temp;
	}
	/* CPair &operator+(const CPair&obj)
	{
	first = first+obj.first;
	second = second+obj.second;
	return (*this);
	}
	*/
};
int main()
{
	CPair<int, int> a(3, 3), b(4, 8);
	CPair<int, int> c = a + b;
	cout << a << " " << b << " " << c << " ";
	cout << (a < b) << endl;
	CPair <int, string> d("Alex"), e("Ivan"),
		f = d + e;
	cout << d << " " << e << " " << endl;
	cout << (d < e) << endl;
	CPair <string, string> 
		w("grand", "grand"),
		v("father", "mother"),
		z = w + v;
	cout << w << " " << v << " " << " " << z;
	CPair<int, CPair<string, string>> 
		x(1, w), y(z, v), t = x + y;
	cout << x << " " << y << " " << t;
	system("pause");
	return 0;
}
