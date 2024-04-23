#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>
#include <unordered_set>

using namespace std;

class Worker {
public:
	string FIO;
	string Joined;
	string Speciality;
	int Salary;

	Worker() {}
	Worker(string a, string b, string c, int d) : FIO(a), Joined(b), Speciality(c), Salary(d) {}
	Worker(Worker& copy) {
		this->FIO = copy.FIO;
		this->Joined = copy.Joined;
		this->Speciality = copy.Speciality;
		this->Salary = copy.Salary;
	}
	Worker(Worker&& perem) {
		swap(this->FIO, perem.FIO);
		swap(this->Joined, perem.Joined);
		swap(this->Speciality, perem.Speciality);
		swap(this->Salary, perem.Salary);
	}

	Worker& operator=(const Worker& w1) {
		this->FIO = w1.FIO;
		this->Joined = w1.Joined;
		this->Speciality = w1.Speciality;
		this->Salary = w1.Salary;
		return *this;
	}
	bool operator==(const Worker& w) const {
		return this->FIO == w.FIO;
	}
	bool operator<(const Worker& w) const {
		return this->FIO < w.FIO;
	}
	friend ostream& operator<<(ostream& os, const Worker& w) {
		cout << w.FIO << ": " << w.Joined << "," << w.Speciality << "," << w.Salary << endl;
		return os;
	}
};
struct hashworker {
	size_t operator()(const Worker& w1) const {
		return hash<string>()(w1.FIO);
	}
};
bool compare(const Worker& w1, const Worker& w2) {
	return (w1.FIO < w2.FIO);
}
int main() {
	vector<Worker> spisok;
	ifstream input("input.txt");
	set<Worker> set1;
	unordered_set<Worker, hashworker> set2;
	string FIO, Joined, Speciality;
	int Salary;

	while (getline(input, FIO)) {
		input >> Joined >> Speciality >> Salary;
		input.ignore();
		spisok.push_back(Worker(FIO, Joined, Speciality, Salary));
		set1.insert(Worker(FIO, Joined, Speciality, Salary));
		set2.insert(Worker(FIO, Joined, Speciality, Salary));
	}

	ofstream output("output.txt");
	output << "Original container:" << endl;
	cout << "Original container:" << endl;
	for (const auto& x : spisok) {
		output << x << endl;
	}

	deque<Worker> copied_spisok;
	copied_spisok.resize(spisok.size());
	copy(spisok.begin(), spisok.end(), copied_spisok.begin());
	sort(spisok.begin(), spisok.end(), compare);

	output << "Sorted container:" << endl;
	cout << "Sorted container:" << endl;
	for (const auto& x : spisok) {
		output << x << endl;
	}
	output << "Copied container:" << endl;
	cout << "Copied container:" << endl;
	for (const auto& x : copied_spisok) {
		output << x << endl;
	}
	cout << "test for set1" << endl;
	for (const auto& x : set1) {
		output << x << endl;
	}
	cout << "test for set2" << endl;
	for (const auto& x : set2) {
		output << x << endl;
	}
	return 0;
}