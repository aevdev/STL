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
	//����� ������������ ��������� ����������, ����� ����� � �������� ������� � �� ������� C/C++ ������� � Command Line(���������� ������), ���� ����� ��������� /EHa
}