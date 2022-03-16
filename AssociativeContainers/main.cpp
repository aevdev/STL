//Associative Containers
#include <iostream>
#include <string>
#include <list>
#include<set>
#include<map>
using std::cin;
using std::cout;
using std::endl;
#define tab '\t'
//#define STL_SET
//#define STL_MAP
int main()
{
#ifdef STL_SET
	//set - ���������� ������
	//multiset - �� ���������� ������
	std::set<int> myset = { 50, 25, 75, 16, 32, 64, 80, 7, 7, 7 };
	//��� � �������� ��������� ����� ���������� ������ �� ���������� � ��������� �� �����
	for (std::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;

	int value;
	cout << "Input value: "; cin >> value;
	myset.insert(value);
	for (int i : myset) cout << i << tab; 	cout << endl;
	cout << "Input erasing value: "; cin >> value;
	myset.erase(value);
	//for (int i : myset) cout << i << tab; 	cout << endl;
	for (std::set<int>::iterator it = myset.lower_bound(25); it != myset.upper_bound(75); ++it) //����� � �������� _������������_
		cout << *it << tab;
	cout << endl;
	for (std::set<int>::iterator it = myset.find(25); it != myset.find(75); ++it) //����� � �������� _�������������_
		cout << *it << tab;
	cout << endl;
#endif // STL_SET

#ifdef STL_MAP
	//map - ��� ���������, ������� ������ ������ � ���� ��������� ������ ������.
	//������ ��������� map �������� ����, ������� ������ ���� � �������� (key and value)
	std::map<int, std::string> week =
	{
		std::pair<int, std::string>(0, "Monday"),
		std::pair<int, std::string>(1, "Tuesday"),
		std::pair<int, std::string>(2, "Wednesday"),
		std::pair<int, std::string>(3, "Thursday"),
		std::pair<int, std::string>(4, "Friday"),
		{5, "Saturday"},//����� � ���. �� ������������� ����������, ��� ��� ����.
		{6, "Sunday"}, 
		std::pair<int, std::string>(0, "ZeroDay"), //��� �������� �� ��������� ��-�� ����, ��� ���� �� ����������
		std::pair<int, std::string>(1, "FirstDay"),//�� ���� ������� multimap ������ map, �� ��� ���������.
	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); ++it)
	{
		cout << it->first << tab << it->second << endl;
	}
#endif // STL_MAP

	std::map<std::string, std::list<std::string>> dictionary
	{
		std::pair<std::string, std::list<std::string>>("Splice", {"Svarivaniye", "Sraschivaniye", "Svadba"}),
		{"Reconaissance", {"Razvedka", "Zondirovaniye"}},
		{"Space", {"Ksomos", "Prostranstvo", "Probel"}},
		{"pencil", {"karandash"}},
		{"desk", {"rabochiy stol", "doska"}},
		{"prohibit", {"zapreshat"}},
		{"appreciate", {"bit priznatelnim", "cenit"}}
	};

	for (std::map<std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		cout.width(20);
		cout << std::left;
		cout << it->first + ':'; //������� ����
		//��������� ������ �������� �������� �������, ���������� ���� ������ � ������� ������ ��� �������� �� �����:
		for (std::list<std::string>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			cout << *jt << ", "; 
		}
		cout << endl;
	}
	cout << "\n-------------------------------------------------------\n";
	for (std::pair<std::string, std::list<std::string>>i : dictionary)
	{
		cout.width(20);
		cout << std::left;
		cout << i.first + ":";
		for (std::string j : i.second) cout << j << ", ";
		cout << "\b\b;\n";
	}
	return 0;
}