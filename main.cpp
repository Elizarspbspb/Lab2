#include "WORD.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int select = 0;
	stringstream ss;
	string str;
	string temp;
	WORD buff; // объект класса WORD
	int flag = 0;
	cout << "Задание 2" << endl;
	cout << "Введите 1 для начала работы " << endl;
	cout << "Любой символ - выход из программы" << endl;
	cin >> select;
	if (select == 1)
	{
		ifstream fin; // открыт файл на чтение
		cout << "Создан объект для чтения" << endl;
		fin.exceptions(ifstream::badbit | ifstream::failbit); // для ifstream, чтоб увидеть ошибку в  exc.what()
		try
		{
			fin.open("test1.txt");
			if (!fin.is_open()) // если файл не открыт
			{
				throw exception("Exception\n");   //переходим в класс Exception, для обработки ошибки
			}
			cout << "Успешное открытие файла" << endl;
		}
		catch (const exception& exc) // ссылка на объект класса exception
		{
			cout << " Такого файла не существует" << endl;
			cout << exc.what() << endl; // описание того что случилось. Результат метода возвращает указатель на char (строчку)
			system("pause");
		}
		while (!fin.eof())
		{
			getline(fin, str); //считывание строки
			ss << str; // записали строку в ss
			while ((ss >> temp))  // пока не \n запись в temp слова до пробела
			{
				buff.setword(temp); // отправляем слово
				if (buff.find())  // если слово начинается с гласной то выводим его
				{
					cout << buff << " ";
					flag++;
				}
			}
			cout << endl;
			ss.clear(); // очистит ss строку
		}
		if (flag == 0)
			cout << "Слов на гласную букву не обнаружено " << endl;
		try
		{
			fin.close();
			cout << "Файл закрыт" << endl;
		}
		catch (const exception& exc)
		{
			cout << " Закрыть файл не удалось. Такого файла не существует" << endl;
			cout << exc.what(); // выдаст инфоормацию об ошибке
			system("pause");
		}
	}
	cout << "The End" << endl;
	system("pause");
	return 0;
}