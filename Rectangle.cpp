#include <iostream> // s1961307@onlineedu.tu-varna.bg
#include <cmath>   //  Student#xxxx
using namespace std;
class CPointXY {
private:
	int m_iX1;
	int m_iY1;
	int m_iX2;
	int m_iY2;
public:
void SetX1(const int &iX1) 
	{
		m_iX1 = iX1;
	}
void SetX2(const int &iX2) 
	{
		m_iX2 = iX2;
	}
	const int&GetX1()const 
	{
		return m_iX1;
	}
	const int&GetX2()const 
	{
		return m_iX2;
	}
	void SetY1(const int &iY1)
	{
		m_iY1 = iY1;
	}
	void SetY2(const int &iY2)
	{
		m_iY2 = iY2;
	}
	const int&GetY1()const 
	{
		return m_iY1;
	}
		const int&GetY2()const 
	{
		return m_iY2;
	}
		CPointXY()
	{
		m_iX1 = 4;
		m_iX2 = 2;
		m_iY1 = 6;
		m_iY2 = 7;
	}
		CPointXY(const int&iX1, const int&iY1, const int&iX2, const int&iY2):
    m_iX1(iX1),
    m_iY1(iY1),
    m_iX2(iX2),
    m_iY2(iY2)		{}
		CPointXY(const CPointXY&a): // copy
		m_iX1(a.m_iX1),
		m_iY1(a.m_iY1),
		m_iX2(a.m_iX2),
		m_iY2(a.m_iY2){}
		int A() const
		{
			int a = abs(m_iX2 - m_iX1);
				return a;
		}
		int B() const
		{
			int b = abs(m_iY2 - m_iY1);
			return b;
		}
			int Lice() const 
	{
		int s = A()*B();
			return s;
	}
			ostream &Output(ostream&out) const 
			{
				out << m_iX1 << " , " << m_iY1 << " , " << m_iX2 << " , " << m_iY2 << endl;
				return out;
			}
			friend ostream &operator <<(ostream&out, const CPointXY&p)
			{
				p.Output(out);
				return out;
			}
};
int main()
{
	CPointXY oRectangle[] ={ CPointXY(2,5,1,2),
		                 CPointXY(7,10,1,4),
		                 CPointXY(15,2,4,6),
						 CPointXY(25,15,6,2) };
	CPointXY oMe(8,9,6,7);
	for(CPointXY &point: oRectangle) 
	{ 
	cout << "a=" << point.A() << endl;
	cout << "b=" << point.B() << endl;
    int s = oMe.Lice();
    cout << "S=" << point.Lice() << endl << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}