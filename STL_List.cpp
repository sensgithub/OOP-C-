#include <iostream>
#include <list>
#include <ctime>
#include <fstream>
#include <algorithm>
using namespace std;
#define FILE_ERROR 1
void ex1_splice() {
    std::list<int> mylist1, mylist2;
    std::list<int>::iterator it;
    // set some initial values:
    for (int i = 1; i <= 4; ++i)
        mylist1.push_back(i);      // mylist1: 1 2 3 4
    for (int i = 1; i <= 3; ++i)
        mylist2.push_back(i * 10);   // mylist2: 10 20 30
    it = mylist1.begin();
    ++it;                         // points to 2
    mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                  // mylist2 (empty)
                                  // "it" still points to 2 (the 5th element)
    mylist2.splice(mylist2.begin(), mylist1, it);
    // mylist1: 1 10 20 30 3 4
    // mylist2: 2
    // "it" is now invalid.
    it = mylist1.begin();
    std::advance(it, 3);           // "it" points now to 30
    mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());
    // mylist1: 30 3 4 1 10 20
    std::cout << "mylist1 contains:";
    for (auto it1 = mylist1.begin(); it1 != mylist1.end(); ++it1)
        std::cout << ' ' << *it1;
    std::cout << '\n';
    for (const auto& i : mylist1) {
        cout << " " << i;
    }
    std::cout << endl;
    copy(mylist1.begin(), mylist1.end(), ostream_iterator<int>(cout, "->"));
    std::cout << "mylist2 contains:";
    for (it = mylist2.begin(); it != mylist2.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}
void ex2_merge() {
    srand((unsigned)time(NULL));
    list<int> l1, l2;
    for (int i = 0; i < 10; i++)
        l1.push_back(rand() % 89 + 10), l2.push_back(rand() % 89 + 10);
    ostream_iterator<int> out(cout, " ");
    cout << "List1 Random numbers: ";
    copy(l1.begin(), l1.end(), out);
    cout << endl << "List2 Random numbers:";
    copy(l2.begin(), l2.end(), out);
    l1.sort(), l2.sort();
    cout << endl << endl << "List1 Sorted numbers: ";
    copy(l1.begin(), l1.end(), out);
    cout << endl << "List2 Sorted numbers: ";
    copy(l2.begin(), l2.end(), out);
    l1.merge(l2);
    cout << endl << endl << "All sorted numbers: ";
    copy(l1.begin(), l1.end(), out);
    l1.unique();

}
class CStudent {
private:
    string m_StudentFN;
    double m_grade;
public:
    void setm_StudentFN(const string& studentfn) {     
        m_StudentFN = studentfn;
    } //promenqme
    void setm_grade(const double& grade) {
       m_grade = grade;
    }
    const string& getstudentfn()const {
        return m_StudentFN;
    } //samo vrushtame
    const double& getm_grade()const {
        return m_grade;
    }
    CStudent() :           //default constructor
        m_StudentFN("19621417"),
       m_grade() {}
    CStudent(const string& studentfn,      //explicit constrictor
        const double& grade):
        m_StudentFN(studentfn),
        m_grade(grade)
         {}
    ostream& Output(ostream& out)const {
        out << m_StudentFN << " "
            << m_grade << " "
            << endl;
        return out;
    }
    istream& Input(istream& in) {
        if (&in == &cin) {
            cout << "studentfn"; cin >> m_StudentFN;
            cout << "grade"; cin >> m_grade;
       
        }
        else {    //fail
            in >> m_StudentFN >> m_grade;
        }
        return in;
    }
    friend ostream&operator<<(ostream&out,const  CStudent& obj){
			obj.Output(out);
			return out;}
	friend istream&operator>>(istream&in, CStudent&obj){
			return obj.Input(in);
		}
    
};
    
class CStudentBook {
private:
    CStudent m_student;
    list<string> m_disc;
    list<int> m_points;
    //list<int> m_grades;
    list<int> pointsToGrades() {
        list<int> grades;
        //for_each m_points - >  grades
        //transform
        return grades;
    }
public:
    CStudentBook(const CStudent& obj) : m_student(obj) {} // { m_student=obj;}
    CStudentBook(const char* filename) {    // (const string& fn)
        /*19620001 0.0
        OOP1 20
        OOP2 40
        OOP3 60
        OOP4 80
        OOP5 100*/
        ifstream ifile(filename);              // ifile (fn.data())
        if (ifile.good()) {
            CStudent temp;
            ifile >> temp; // m_StudentName, m_grade
            m_student = temp;
            while (ifile.good()) {
                string disc; int points;
                ifile >> disc;
                ifile >> points;
                addPoints(disc, points);
            }
        }
        else throw FILE_ERROR;
    }
    friend ostream& operator<<(ostream& out, const CStudentBook obj) {
        out << obj.m_student;
        auto it1 = obj.m_disc.begin();
        auto it2 = obj.m_points.begin();

        for (it1; it1 != obj.m_disc.end(); it1++, it2++)
            out << *it1 << " " << *it2 << endl;
        return out;
    }

    void addPoints(const string& d, int p) {
        auto it1 = find(m_disc.begin(), m_disc.end(), d);
        auto it2 = m_points.begin();
        if (it1 == m_disc.end()) {
            m_disc.push_back(d);
            m_points.push_back(p);
        }
        else {

            int temp = distance(m_disc.begin(), it1);
            advance(it2, temp);
            (*it2) += p;
        }
    }
};

        
    
   

void ex3_StudentBook() {

    try {
        CStudentBook stBook1("student19620001.txt");

        cout << stBook1;
    }
    catch (int error) {
        switch (error) {
        case FILE_ERROR:
            cout << "File error!" << endl;

        }
    }
}
int main()
{

        //ex1_splice();
        //ex2_merge();
      ex3_StudentBook();

    return 0;
}