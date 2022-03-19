#include "Crime.h"

std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	return os << crimes.at(obj.get_id()) << ", " << obj.get_place();	//метод at позволяет получить доступ к элементам так же, как и оператор квадратные скобки.
																		//возвращает ссылку на значение идентифицированное ключом. (то есть он принимает ключ, а возвращает значение. т.е. по нашему ключу он выведет строку)
}
std::ofstream& operator<<(std::ofstream& ofs, const Crime& obj)
{
	ofs << obj.get_id() << " " << obj.get_place();
	return ofs;
}