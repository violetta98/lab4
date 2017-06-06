#include<iostream>
#include<fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
ifstream fin("data.txt"); // ����� ��������� ������ �� �����, ����� �� ������� �� �� 300 ���

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

#ifdef _STL_REVERSE_ITERATOR_  // ��� ����� ������������ ����������� (���) ��������� ������ (vector, list) � reverse_iterator
#include<vector>
#include<list>
using std::vector;
using std::list;
using std::reverse_iterator;
#else                         // ��� ������������ ��� ��������� ������ � ��� reverse_iterator
#include"reverse_iterator.h" // ��� ������� ���������� ��� ������� ( ����� ��� ���� ������� reverse_iterator)
#include"vector.h" // � ������� ���� ��������� ����� reverse_iterator
#include"list.h"   // � ���������� ������ ���� ��������� ����� reverse_iterator
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
	// ������������ reverse_iterator ��� �������� �������
	cout << "--������--" << endl;
	int sizeArray;
	fin >> sizeArray;
	int *a = new int[sizeArray];
	for_each(reverse_iterator<int*>(a + sizeArray), reverse_iterator<int*>(a), read);
	cout << "�������� �������:" << endl;
	for_each(reverse_iterator<int*>(a + sizeArray), reverse_iterator<int*>(a), print);
	cout << endl;
	int val1; 
	fin >> val1;
	reverse_iterator<int*> ait = find_if(reverse_iterator<int*>(a + sizeArray), reverse_iterator<int*>(a), greater_than(val1));
	if (ait != reverse_iterator<int*>(a))
		cout << *ait << " - ������ ��������� ������� � �������, ������� ������ " << val1 << endl;
	else
		cout << "� ���������, ��� �������� � ������� ������ ���� ����� " << val1 << " :(" << endl;
	delete[]a;

	// ������������ reverse_iterator ��� �������
	cout << endl << "--������--" << endl;
	int sizeVector;
	fin >> sizeVector;
	vector<int> v;
	for (int i = 0; i < sizeVector; i++) {
		int elem;
		fin >> elem;
		v.push_back(elem);
	}
	cout << "�������� �������:" << endl;
	for_each(v.rbegin(), v.rend(), print);
	cout << endl;
	int val2;
	fin >> val2;
	vector<int>::reverse_iterator vit = find_if(v.rbegin(), v.rend(), greater_than(val2));
	if (vit != v.rend())
		cout << *vit << " - ������ ��������� ������� � �������, ������� ������ " << val2 << endl;
	else
		cout << "� ���������, ��� �������� � ������� ������ ���� ����� " << val2 << " :(" << endl;

	// ������������ reverse_iterator ��� ����������� ������������� ������
	cout << endl << "--������--" << endl;
	int sizeList;
	fin >> sizeList;
	list<int> l;
	for (int i = 0; i < sizeList; i++) {
		int elem;
		fin >> elem;
		l.push_back(elem);
	}
	cout << "�������� ������:" << endl;
	for_each(l.rbegin(), l.rend(), print);
	cout << endl;
	int val3;
	fin >> val3;
	list<int>::reverse_iterator lit = find_if(l.rbegin(), l.rend(), greater_than(val3));
	if (lit != l.rend())
		cout << *lit << " - ������ ��������� ������� � ������, ������� ������ " << val3 << endl;
	else
		cout << "� ���������, ��� �������� � ������ ������ ���� ����� " << val3 << " :(" << endl;
	return 0;
}









