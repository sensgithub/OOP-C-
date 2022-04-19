#include <iostream>
#include <vector>
#include <iterator>
#include <ctime> //time.h

using namespace std;

int main() {
    vector<int> v (10, 0); //�����.������. v(10)
    ostream_iterator<int> out(cout, " "); //���.��������

     copy(v.begin(), v.end(), out); //��������� �� ����. copy(v.begin(), v.end(), ostream_iterator<int> (cout, " "));

     vector<int>::iterator i = v.begin();

     *i = 125;
    cout << endl;

     copy(v.begin(), v.end(), out); //��������� �� ����.

     v.resize(v.capacity() + 1);
    // *i = 126;

     i = v.begin();
    advance(i,2);
    *i = 126;

    cout << endl;
    copy(v.begin(), v.end(), out); //��������� �� ����.

     srand((unsigned)time(NULL));
    vector<int> v1;
    v1.resize(50);
    for (int i = 0; i < v1.size(); i++) {
     v1[i] = rand() % 64; //0 - 63 v.operator[](i)
    }

     int max = v1[0];
    for (int i = 0; i < v1.size(); i++) {
     cout << v1[i] << " "; //v.at(i)
     if (v1[i] > max) max = v1[i];
    }
    cout << "\nMax is " << max << endl;

     for (auto i = v1.begin(); i != v1.end(); i++) 
     {
     cout << *i << " ";
     if ((*i) > max) max = *i;
     }
    cout << endl;

    for (auto& i : v1) {
    cout << i << " ";
    }

    vector<int> vi(4, 1);
    vi.push_back(2);
    vi[2] = 3;
    vector<int>::iterator j = vi.begin();
    vi.insert(j, 3, 2);
    vi.pop_back();
    vi.clear();

    system("pause");
    return 0;
}