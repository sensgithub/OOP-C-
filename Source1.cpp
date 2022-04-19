#include <iostream>
#include <string>
#include <vector>
#include<fstream>
using namespace std;
#define FILE_ERROR 1
#define DATA_ERROR 2
class Page {
protected:
	string m_content;
public:
	Page() :
		m_content("Default")
	{}
	Page(const string& content) :
		m_content(content) {}
	Page(const Page& a) :
		m_content(a.m_content)
	{}
	void SetContent(const string& content) {
		m_content = content;
	}
	const string& GetContent()const {
		return m_content;
	}
	virtual const string& PageNum() const = 0;
	virtual const string& ChangePage(Page&obj)const = 0;
};

class BookPage : Page {
private:
	int m_pagenum;
public:
	BookPage() :
		m_pagenum(100)
	{}
	BookPage(const int& pagenum) :
		m_pagenum(pagenum) {}
	BookPage(const BookPage& c) :
		m_pagenum(c.m_pagenum)
	{}
	const int& GetPage()const {
		return m_pagenum;
	}
	istream& Input(istream& in) {
		if (&in == &cin) {
			cout << "Content: "; cin >> m_content;
			cout << "Page Number: "; cin >> m_pagenum;
		}
		else {
			in >> m_content >> m_pagenum;
		}
		return in;
	}
	ostream& Output(ostream& out)const {
		out << m_content << " "
			<< m_pagenum << " "
			<< endl;
		return out;
	}
	friend ostream& operator<<(ostream& out, const BookPage& obj) {
		obj.Output(out);
		return out;
	}
	friend istream& operator>>(istream& in, BookPage& obj) {
		return obj.Input(in);
	}
	friend bool operator<(const BookPage& c1, const BookPage& c2)
	{
		return c1.GetPage() < c2.GetPage();
	}
	friend bool operator==(const BookPage& c1, const BookPage& c2)
	{
		return c1.GetPage() == c2.GetPage();
	}
};
class Book {
private:
	vector<BookPage> pages;
public:
int i;
int s; 
Book(void);
Book(int ii, int ss);
void AddNumber(Book& numpages);
Book::Book()
{
i = -1;
s = -1;
vector<Book> numpages1;
}
Book::Book(int ii, int ss)
{
   i = ii;
   s = ss;
}
void Book::AddPages(Book& book)
{
pages.push_back(book);
}
void Pages()
{
	int tot = 600;
	vector<Book> myPage();
	int i = 0;
	while (i < tot)
	{
		Book book(i, 1);
		myPage.push_back(book);
		i++;
	}
	i = 0;
	while (i < tot)
	{
		Book* book = myPage.back();
		myPage.pop_back();
		cout << book->i << book->s << endl;
		i++;
	}
}
};
int main()
{
	Book b1("1984", 562);
	b1.show();
}