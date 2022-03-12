#include <iostream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	//cout << 1 / 0 << endl;
	int a, b;
	cin >> a >> b;
	try
	{
		cout << "\n" << a / b;
	}
	catch (...)
	{
		std::cerr << "Something happened";
	}
	//Чтобы обрабатывать системные исключения, нужно зайти в свойства проекта и во вкладке C/C++ перейти в Command Line(команданая строка), куда нужно приписать /EHa
}