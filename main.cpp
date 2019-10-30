#include "WORD.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{

	setlocale(LC_ALL, "");
	int select = 0;
	//=================================
	stringstream ss;
	string str;
	string temp;
	WORD buff;

	printf("\n  Выбор Задания:\n");
	printf("1 - Задание 1 \n");

	printf("\n Любой символ - выход из программы\n");
	scanf_s("%d", &select);
	if (select == 1)
	{
		ifstream fin;
		fin.open("test.txt");
		try
		{
			if (!fin.is_open())
			{
				throw exception("Exception\n");   //переходим в класс Exception, для обработки ошибки
			}
		}
		catch (const exception& exc)
		{
			cout << " Такого файла не существует" << endl;
			cout << exc.what();
			system("pause");
		}
		while (!fin.eof())
		{
			getline(fin, str); //считывание строки
			ss << str; // записали строку в ss
			while (ss >> temp)  // пока не \n запись в temp слова до пробела
			{
				buff.setword(temp); // отправляем слово
				if (buff.change())  // если слово начинается с гласной то выводим его
				{
					cout << buff << " ";
				}
			}
			cout << endl;
			ss.clear(); // очистит ss строку
		}
		fin.close();
	}
	system("pause");
	return 0;
}