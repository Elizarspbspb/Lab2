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

	printf("\n  ����� �������:\n");
	printf("1 - ������� 1 \n");

	printf("\n ����� ������ - ����� �� ���������\n");
	scanf_s("%d", &select);
	if (select == 1)
	{
		ifstream fin;
		fin.open("test.txt");
		try
		{
			if (!fin.is_open())
			{
				throw exception("Exception\n");   //��������� � ����� Exception, ��� ��������� ������
			}
		}
		catch (const exception& exc)
		{
			cout << " ������ ����� �� ����������" << endl;
			cout << exc.what();
			system("pause");
		}
		while (!fin.eof())
		{
			getline(fin, str); //���������� ������
			ss << str; // �������� ������ � ss
			while (ss >> temp)  // ���� �� \n ������ � temp ����� �� �������
			{
				buff.setword(temp); // ���������� �����
				if (buff.change())  // ���� ����� ���������� � ������� �� ������� ���
				{
					cout << buff << " ";
				}
			}
			cout << endl;
			ss.clear(); // ������� ss ������
		}
		fin.close();
	}
	system("pause");
	return 0;
}