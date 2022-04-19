#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
#define FILE_EXCEPTION 0
using namespace std;

class cPerson {
private:
	string p_name;
	string EGN;
public:
	cPerson(const string& name, const string& egn):
		p_name(name),EGN(egn)
	{}
	
	const string& get_EGN()const {
		return EGN;
	}

	const string& get_name()const {
		return p_name;
	}

	bool operator <(const cPerson& obj) {
		return EGN < obj.get_EGN();
	}

	bool operator == (const cPerson& obj) {
		return EGN == obj.get_EGN();
	}

	ostream& Output(ostream& out)const;
	istream& Input(istream& in);

	friend istream& operator >> (istream& in, cPerson& obj);
	friend ostream& operator << (ostream& out, const cPerson& obj);
};

ostream& cPerson::Output(ostream& out)const {
	out << p_name << " " << EGN;
	return out;
}

istream& cPerson::Input(istream& in) {
	if (&in == &cin) {
		cout << "Enter name: ";
		cin >> p_name;
		cout << "Enter EGN: ";
		cin >> EGN;
	}
	else {
		in >> p_name >> EGN;
	}
	return in;
}

ostream& operator << (ostream& out, const cPerson& obj) {
	obj.Output(out);
	return out;
}

istream& operator >> (istream& in, cPerson& obj) {
	obj.Input(in);
	return in;
}

class cCity {
private:
	string city_name;
	vector<cPerson> people;
public:
	cCity(const string& filename) {
		fstream current_file(filename,ios_base::in);//use this file for input only
		if (current_file.good()) {
			current_file >> city_name;
			vector_insert(current_file, people);
		}
		else {
			throw FILE_EXCEPTION;
		}
	}
	ostream& vector_output(ostream& out) {// or just void
		copy(people.begin(), people.end(), ostream_iterator<cPerson>(out, "\n"));
		return out;
	}

	void vector_insert(istream& file, vector<cPerson>& vec) {
		while (file.good()) {
			cPerson temp("","");
			file >> temp;
			vec.push_back(temp);
		}
		//copy(istream_iterator<cPerson>(file), istream_iterator<cPerson>(), back_inserter(vec)); //Alternative cycle.
	}

	vector<cPerson> duplicate_egn() {
		vector<cPerson> result;
		vector<cPerson> temp = people;
		vector<cPerson> unq;
		sort(temp.begin(),temp.end());
		unique_copy(temp.begin(), temp.end(), back_inserter(unq));
		set_difference(temp.begin(), temp.end(), unq.begin(), unq.end(), back_inserter(result));
		/*
		for (auto i = temp.begin(); i != temp.end()-1; i++) {
			if ((*i) == (*(i + 1))) {
				result.push_back((*(i+1)));//Only push the 2nd duplicate
			}
		}
		*/
		return result;
	}

	void delete_duplicates() {
		vector<cPerson> temp = people;
		vector<cPerson> unq;
		sort(temp.begin(), temp.end());
		unique_copy(temp.begin(), temp.end(), back_inserter(unq));
		people.clear();
		people = unq;
	}


};

int main() {
	/*
		cPerson abc("ivan", "19621961");
	cPerson too("gesh", "19621962");

	if (abc < too) {
		cout << "it is ";

	}
	else {
		cout << "it isn't";
	}
	*/

	try {
		cCity test("city_file.txt");
		test.vector_output(cout);
		vector<cPerson> duplicates = test.duplicate_egn();
		cout << endl;
		copy(duplicates.begin(), duplicates.end(), ostream_iterator<cPerson>(cout, "\n"));
		cout << "Only uniques "<<endl;
		test.delete_duplicates();
		test.vector_output(cout);
	}
	catch(int a){
		switch (a) {
		case(FILE_EXCEPTION):
			cout << "File does not exist. " << endl;
			break;
		}
	}
	return 0;
}
