#include "WORD.h"

void WORD::setword(string wrd)
{
	word = wrd;
}
string WORD::getword() const
{
	return word;
}
double WORD::change() {
	char ch;
	double f = 0;
	ch = word[0];
	switch (ch) {
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

ostream& operator <<(ostream& output, WORD& pointer)
{
	cout << pointer.word;
	return output;
}