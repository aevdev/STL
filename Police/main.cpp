#include <iostream>
#include <map>
#include <list>
#include <string>

#include "Crime.h"

using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n----------------------------------------------------------\n"
void print(const std::map<std::string, std::list<Crime>>& base);
int main()
{
	std::map<std::string, std::list<Crime>> base =
	{
		{"a777km", {Crime(1, "Lenin street"), Crime(2, "Frunze street")}},
		{"a557ab", {Crime(5, "Kosmonavtov street")} },
		{"a001ss", {Crime(4, "Lenina and Oktyabrya crossroad"), Crime(3, "Oktyabrya street")}},
	};
	print(base)

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

	print(base);

	return 0;
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