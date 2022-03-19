#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <string>

#include "Crime.h"

using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n----------------------------------------------------------\n"
void add(std::map<std::string, std::list<Crime>>& base);
void print(const std::map<std::string, std::list<Crime>>& base);
void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename);
void load(std::map<std::string, std::list<Crime>>& base, const std::string& filename);

int main()
{
	std::map<std::string, std::list<Crime>> base/* =
	{
		{"a777km", {Crime(1, "Lenin street"), Crime(2, "Frunze street")}},
		{"a557ab", {Crime(5, "Kosmonavtov street")} },
		{"a001ss", {Crime(4, "Lenina and Oktyabrya crossroad"), Crime(3, "Oktyabrya street")}},
	}*/;
	load(base, "base.txt");
	print(base);
	//save(base, "base.txt");
	//add(base);


	//print(base);

	return 0;
}

void add(std::map<std::string, std::list<Crime>>& base)
{
	std::string license_plate;
	int id;
	std::string place;
	cout << "Input license plate number: "; cin >> license_plate;
	cout << "Input crime (article number): "; cin >> id;
	cout << "Input place: ";
	cin.clear(); //34 и 35 - очищают буфер ввода.
	cin.ignore();
	std::getline(cin, place);

	////1 вариант
	base[license_plate].push_back(Crime(id, place));

	//2 Вариант
	/*std::map<std::string, std::list<Crime>>::iterator it = base.find(license_plate);
	if (it != base.end())
	{
		it->second.push_back(Crime(id, place));
	}
	else
	{
		base.insert(std::pair<std::string, std::list<Crime>>(license_plate, { Crime(id, place) }));
	}
	*/
}
void print(const std::map<std::string, std::list<Crime>>& base)
{
	for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		cout << it->first + ":\n";
		for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			cout << "\t" << *jt << ";\n";
		}
		cout << delimiter;
	}
}

void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename)
{
	std::ofstream fout(filename);
	for (std::pair<std::string, std::list<Crime>> i : base)
	{
		fout << i.first << ":\t";
		for (Crime j : i.second)
		{
			fout << j << ", ";
		}
		fout.seekp(-2, std::ios::cur); //сдвигаем курсор на две позиции влево (и затираем символы на пути)
		fout << ";\n";
	}
	fout.close();
	system((std::string("start notepad ") + filename).c_str()); //c_str - возвращает С-string (NULL terminated line) 
}

void load(std::map<std::string, std::list<Crime>>& base, const std::string& filename)
{
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::string license_plate;
			int id;
			std::string crimes;
			std::getline(fin, license_plate, ':');
			std::getline(fin, crimes);

			if (crimes.empty())continue;
			if (crimes.find(',') != std::string::npos)
			{
				for (int start = 0, end = crimes.find(','); end != std::string::npos; start = end)
				{
					end = crimes.find(',', start + 1);
					std::string place;
					place = crimes.substr(start + 1, end);
					place.erase(0, place.find_first_not_of(' '));
					id = std::stoi(place.substr(0, place.find_first_of(' '))); //stoi - преобразует строку в число (string to integer)
					place.erase(0, place.find_first_of(' ') + 1);
					base[license_plate].push_back(Crime(id, place));
				}
			}
			else
			{
				id = std::stoi(crimes.substr(0, crimes.find_first_of(' ')));
				crimes.erase(0, crimes.find_first_of(' '));
				base[license_plate].push_back(Crime(id, crimes));
			}

		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
}