#include<iostream>
#include<fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
ifstream fin("data.txt"); // будем считывать данные из файла, чтобы не вводить их по 300 раз

//#define _STL_ALGORITHM_
//#define _STL_REVERSE_ITERATOR_ 

#ifdef _STL_ALGORITHM_
#include<algorithm>
using std::find_if;
using std::for_each;
using std::max;
#else
#include"algorithm.h"
#endif

#ifdef _STL_REVERSE_ITERATOR_  // тут будут подключаться стандартные (все) структуры данных (vector, list) и reverse_iterator
#include<vector>
#include<list>
using std::vector;
using std::list;
using std::reverse_iterator;
#else                         // тут подключаются мои структуры данных и мой reverse_iterator
#include"reverse_iterator.h" // это сделано специально для массива ( чтобы для него работал reverse_iterator)
#include"vector.h" // в векторе свой вложенный класс reverse_iterator
#include"list.h"   // в двусвязном списке свой вложенный класс reverse_iterator
#endif

void print(int a) {
	cout << a << ' ';
}

void read(int &a) {
	fin >> a;
}

class greater_than {
	int param;
public:
	greater_than(int n) : param(n) {}
	bool operator()(int n) { return n > param; }
};


int main() {
	system("CHCP 1251>NULL");
	// демонстрация reverse_iterator для обычного массива
	cout << "--МАССИВ--" << endl;
	int sizeArray;
	fin >> sizeArray;
	int *a = new int[sizeArray];
	for_each(reverse_iterator<int*>(a + sizeArray), reverse_iterator<int*>(a), read);
	cout << "Элементы массива:" << endl;
	for_each(reverse_iterator<int*>(a + sizeArray), reverse_iterator<int*>(a), print);
	cout << endl;
	int val1; 
	fin >> val1;
	reverse_iterator<int*> ait = find_if(reverse_iterator<int*>(a + sizeArray), reverse_iterator<int*>(a), greater_than(val1));
	if (ait != reverse_iterator<int*>(a))
		cout << *ait << " - первый найденный элемент в массиве, который больше " << val1 << endl;
	else
		cout << "К сожалению, все элементы в массиве меньше либо равны " << val1 << " :(" << endl;
	delete[]a;

	// демонстрация reverse_iterator для вектора
	cout << endl << "--ВЕКТОР--" << endl;
	int sizeVector;
	fin >> sizeVector;
	vector<int> v;
	for (int i = 0; i < sizeVector; i++) {
		int elem;
		fin >> elem;
		v.push_back(elem);
	}
	cout << "Элементы вектора:" << endl;
	for_each(v.rbegin(), v.rend(), print);
	cout << endl;
	int val2;
	fin >> val2;
	vector<int>::reverse_iterator vit = find_if(v.rbegin(), v.rend(), greater_than(val2));
	if (vit != v.rend())
		cout << *vit << " - первый найденный элемент в векторе, который больше " << val2 << endl;
	else
		cout << "К сожалению, все элементы в векторе меньше либо равны " << val2 << " :(" << endl;

	// демонстрация reverse_iterator для двусвязного динамического списка
	cout << endl << "--СПИСОК--" << endl;
	int sizeList;
	fin >> sizeList;
	list<int> l;
	for (int i = 0; i < sizeList; i++) {
		int elem;
		fin >> elem;
		l.push_back(elem);
	}
	cout << "Элементы списка:" << endl;
	for_each(l.rbegin(), l.rend(), print);
	cout << endl;
	int val3;
	fin >> val3;
	list<int>::reverse_iterator lit = find_if(l.rbegin(), l.rend(), greater_than(val3));
	if (lit != l.rend())
		cout << *lit << " - первый найденный элемент в списке, который больше " << val3 << endl;
	else
		cout << "К сожалению, все элементы в списке меньше либо равны " << val3 << " :(" << endl;
	return 0;
}









