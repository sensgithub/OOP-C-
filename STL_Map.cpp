#include<iostream>
#include<iterator>
#include<list>
#include<algorithm>
#include<fstream>
#include<map>
#include<cctype> 
#define FILE_ERROR 1
#define DATA_ERROR 2
using namespace std;
class CCar {
private:
    int power;
    string m_model;
    string m_plate_number;
    string m_owner;
public:
    CCar() :
        power(0), m_model("Unknown"), m_plate_number("Unknown"), m_owner("Unknown")
    {}
    CCar(const int& pow, const string& mod, const string& pn, const string& own) :
        power(pow), m_model(mod), m_plate_number(pn), m_owner(own)
    {}
    CCar(const CCar& obj) :
        power(obj.power), m_model(obj.m_model), m_plate_number(obj.m_plate_number), m_owner(obj.m_owner)
    {}
    const string& get_pn()const {
        return m_plate_number;
    }
    bool operator ==(const CCar& obj)const {
        return m_owner == obj.m_owner;
    }
    bool operator <(const CCar& obj)const {
        return get_pn() < obj.get_pn();
    }
    friend ostream& operator <<(ostream& out, const CCar& obj) {
        out << obj.m_model << " " << obj.power << " " << obj.m_plate_number << " " << obj.m_owner << endl;
        return out;
    }
    friend istream& operator >>(istream& in, Car& obj) {
        in >> obj.m_model >> obj.power >> obj.m_plate_number >> obj.m_owner;
        return in;
    }
    static string city_code;
    static map<string, string> code_to_city;
    static multimap<string, string> city_to_code;
    static string return_city_code(const string& pn) {
        string code;
        for (int i = 0; i < pn.length(); i++) {
            if (!isdigit(pn[i])) {
                code.push_back(pn[i]);
            }
            else
                break;
        }
        return code;
    }
    static bool is_equal_codes(const CCar& obj) {
        return return_city_code(obj.get_pn()) == city_code;
    }
    static string get_code_from_name(const string& city_name) {
        auto it = city_to_code.find(city_name);
        if (it != city_to_code.end()) {
            return (*it).second;
        }
        else
            cout << "This city does not exist." << endl;
    }
};
class Cregister {
private:
    list <CCar> database;
public:
    auto_register(const char* filename) {
        fstream ifile(filename, ios_base::in);
        if (ifile.good()) {
            copy(istream_iterator<CCar>(ifile), istream_iterator<CCar>(), back_inserter(database));
        }
        else
            throw FILE_ERROR;
    }
    string owner_to_PN(const string& own) {
        CCar fake_car(0, "", "", own);
        auto it = find(database.begin(), database.end(), fake_car);
        if (it != database.end())
            return (*it).get_pn();
        else
            return "Not found. ";
    }
    list<CCar> code_to_carlist(const string& code) {
        list<CCar> result;
        CCar::city_code = code;
        copy_if(database.begin(), database.end(), back_inserter(result), CCar::is_equal_codes);
        return result;
    }
    friend ostream& operator <<(ostream& out, const auto_register& obj) {
        copy(obj.database.begin(), obj.database.end(), ostream_iterator<CCar>(out, "\n"));
        return out;
    }
    friend istream& operator >>(istream& in, auto_register& obj) {
        copy(istream_iterator<CCar>(in), istream_iterator<CCar>(), back_inserter(obj.database));
        return in;
    }
};
string CCar::city_code = "BP";
map<string, string> CCar::code_to_city{
    {"H", "Shumen"},
    {"B", "Varna"},
    {"C", "Sofia"},
    {"Y", "Yambol"},
    {"M", "Montana"},
    {"A", "Burgas"},
    {"PP", "Razgrad"},
    {"P", "Plovdiv"},
    {"X", "Haskovo"},
};
multimap<string, string> CCar::city_to_code{
    {"Shumen", "H"},
    {"Varna", "B"},
    {"Sofia", "C"},
    {"Yambol","Y"},
    {"Montana","M"},
    {"Burgas","A"},
    {"Razgrad","PP"},
    {"Plovdiv","P"},
    {"Haskovo","X"},
};
int main() {
    try {
        auto_register data("car_data.txt");
        cout << data;
        list<CCar> temp = data.code_to_carlist(Car::get_code_from_name("Vratsa"));
        copy(temp.begin(), temp.end(), ostream_iterator<CCar>(cout, "\n"));
        cout << data.owner_to_PN("own1");
    }
    catch (int error) {
        switch (error) {
        case FILE_ERROR:
            cout << "File error! " << endl;
            break;
        case DATA_ERROR:
            cout << "Corrupt data. " << endl;
            break;
        }
    }
    return 0;
}