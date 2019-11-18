#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

class WORD {
private:
	string word;
public:
	void setword(string wrd);
	string getword() const;
	double find(); // функция определения 1-ой буквы слова
	friend ostream& operator<<(ostream &cout, WORD obj); // переопределил оператор вывода
	// friend  так как нужно 2 параметра передать
};