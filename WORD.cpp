#include "WORD.h"

void WORD::setword(string wrd) // записывает слово
{
	word = wrd;
}
string WORD::getword() const // возвращает слово
{
	return word;
}
double WORD::find() {  // Находит первую букву в слове, если гласная возвращает 1, иначе 0
	char ch; 
	double f = 0;
	ch = word[0]; // берем 1 символ слова
	switch (ch) {   // если ch гласная буква то f = 1
	case 'a': f = 1;
		break;
	case 'o': f = 1;
		break;
	case 'i': f = 1;
		break;
	case 'e': f = 1;
		break;
	case 'u': f = 1;
		break;
	case 'y': f = 1;
		break;
	case 'A': f = 1;
		break;
	case 'O': f = 1;
		break;
	case 'I': f = 1;
		break;
	case 'E': f = 1;
		break;
	case 'U': f = 1;
		break;
	case 'Y': f = 1;
		break;
	}
	return f; 
}

ostream & operator<<(ostream & cout, WORD obj) // вывод
{
	cout << obj.word;
	return cout;
}
