//STL
#include<iostream>
#include<array>
#include<vector>
#include<deque>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n---------------------------------------------------\n"
//#define STL_ARRAY
//#define STL_VECTOR
#define STL_DEQUE
int main()
{
	
#ifdef STL_ARRAY
	//array - это контейнеры, который хранит данные в виде статического массива.
	std::array<int, 5> arr = { 3, 5, 7, 13, 21 };
	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
	//Несмотря на то, что array - это по сути обычный статический массив. Его использование нужно по нескольким причинам, например:
	//Унификация. т.е. чтобы был одинаковый код-стайл.
	//Обработка исключений. Для обычного статического массива это сделать сложно, для array это сделать гораздо проще. (если умеете применять обработку исключений на аппаратном уровне)
	
	//еще можно так, но зачем: (в динамической памяти создается статическая конструкция)
	std::array<int, 5>* p_arr = new	std::array<int, 5> {3, 5, 7, 13, 21};
	for (int i = 0; i < p_arr->size(); ++i)
	{
		cout << p_arr->operator[](i) << tab;
	}
	cout << endl;
#endif //STL_ARRAY

#ifdef STL_VECTOR
	//vector - это контейнеры, который хранит данные в виде динамического массива
	std::vector<int> vec = { 0, 1, 1, 2, 3 ,5, 8, 13, 21, 34 }; 
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	cout << "Size:\t\t" << vec.size() << endl;
	cout << "MaxSize:\t" << vec.max_size() << endl;
	cout << "Capacity:\t" << vec.capacity() << endl;
	cout << delimiter;
	vec.push_back(55);
	vec.pop_back();
	vec.pop_back();
	vec.pop_back();
	cout << "Size:\t\t" << vec.size() << endl;
	cout << "MaxSize:\t" << vec.max_size() << endl;
	cout << "Capacity:\t" << vec.capacity() << endl;
	cout << delimiter;

	//vec.shrink_to_fit();
	//vec.reserve(25); //если задать резерв меньше текущего capacity, то значение capacity не имзенится.
	//vec.resize(5);
	//vec.resize(12);

	cout << "Size:\t\t" << vec.size() << endl;
	cout << "MaxSize:\t" << vec.max_size() << endl;
	cout << "Capacity:\t" << vec.capacity() << endl;
	try
	{
		//throw "My exception";
		//throw 4;
		for (int i = 0; i < vec.capacity(); ++i) //пробуем выйти за пределы вектора
		{
			//cout << vec.operator[](i) << tab; // vec.operator[](i) == vec[i]
			cout << vec.at(i) << tab;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	catch (const char* e)
	{
		std::cerr << e << endl;
	}
	catch (int e)
	{
		std::cerr << "Error #" << e << endl;
	}
	catch (...) //деление на ноль - это системно аппаратное исключение и его может обработать только этот универсальный обработчик
	{
		//EHa - ключ, который нужно добавить в параметры компиляции, чтобы работал универсальный обработчик исключений.
		std::cerr << "Something happened" << endl;
	}
	cout << "\nFirst vector element: " << vec.front() << endl;
	cout << "\nLast vector element: " << vec.back() << endl;


	vec.assign({ 1 , 2, 4, 8, 16, 32 });
	cout << delimiter;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	for (std::vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); ++rit)
	{
		cout << *rit << tab;
	}



	cout << "Size:\t\t" << vec.size() << endl;
	cout << "MaxSize:\t" << vec.max_size() << endl;
	cout << "Capacity:\t" << vec.capacity() << endl;
	cout << delimiter;

	int index, value, count;
	cout << "\nInput index: "; cin >> index;
	cout << "\nInput value: "; cin >> value;
	cout << "\nInput count: "; cin >> count;
	//std::vector<int>::const_iterator position = vec.begin() + index;
	vec.insert(vec.begin() + index, count, value);

	cout << '\n';
	for (int i : vec) cout << i << tab; cout << endl;

	cout << "\nInput index: "; cin >> index;

	vec.insert(vec.begin() + index, { 3, 5 ,8 ,13, 21 });
	cout << '\n';
	for (int i : vec) cout << i << tab; cout << endl;
#endif //STL_VECTOR

#ifdef STL_DEQUE
	//deque (double-ended queue - двунаправленная очередь) - это контейнер, который хранит данные в виде списка динамических массивов.
	//в отличие от вектора, он не переопределяет ранее выделенную память при добавлении новых значений, а выделяет еще одну область памяти, там, где это возможно
	//и связывает выделенные памяти в список
	//как для пользователя, в отличие от вектора, deque так же позволяет добавлять значения в начало контейнера, а не только в конец.
	std::deque<int> deque = {2, 4, 8, 16, 32};
	deque.push_back(64);
	deque.push_back(128);
	deque.push_back(256);
	for (int i = 0; i < deque.size(); ++i)
	{
		cout << deque[i] << tab;
	}
	cout << endl;
	deque.push_front(1);
	deque.push_front(1);
	deque.push_front(0);
	deque.push_front(0);
	for (int i : deque) cout << i << tab;
#endif // STL_DEQUE

	return 0;
}