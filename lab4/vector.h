#pragma once

using std::cin;
using std::cout;
using std::endl;

template<class T>
class vector {
	T *a;
	unsigned int size_a, max_size_a;
public:
	class iterator { // ������� �������� �� ����������� ���� ������, �� � ������� :)
		T *cur;
	public:
		typedef T value_type;
		typedef int difference_type;
		iterator(T* x);
		iterator(const iterator& i);
		bool operator !=(iterator i);
		bool operator ==(iterator i);
		bool operator <(iterator i);
		bool operator >(iterator i);
		bool operator <=(iterator i);
		bool operator >=(iterator i);
		iterator operator++(int); // ����������� ���������
		iterator& operator++(); // ���������� ���������
		iterator operator--(int); // ����������� ���������
		iterator& operator--(); // ���������� ���������
		iterator operator+(int n);
		iterator& operator+=(int n);
		iterator operator-(int n);
		iterator& operator-=(int n);
		T operator-(iterator it);
		T& operator*();
		T& operator[](int n);
		T* base();
	};
	class reverse_iterator {
		T* cur;
	public:
		typedef T value_type;
		reverse_iterator(T* x);
		reverse_iterator(const reverse_iterator& i);
		bool operator !=(reverse_iterator i);
		bool operator ==(reverse_iterator i);
		bool operator <(reverse_iterator i);
		bool operator >(reverse_iterator i);
		bool operator <=(reverse_iterator i);
		bool operator >=(reverse_iterator i);
		reverse_iterator operator++(int); // ����������� ���������
		reverse_iterator& operator++(); // ���������� ���������
		reverse_iterator operator--(int); // ����������� ���������
		reverse_iterator& operator--(); // ���������� ���������
		reverse_iterator operator+(int n);
		reverse_iterator& operator+=(int n);
		reverse_iterator operator-(int n);
		reverse_iterator& operator-=(int n);
		T& operator*();
		T& operator[](int n);
		T* base();
	};
	iterator begin();
	iterator end();
	reverse_iterator rbegin(); // ��������� �������
	reverse_iterator rend(); // �������, ������� ����� ����� �������
	vector();
	vector(unsigned int n);
	vector(T* p, unsigned int n);
	vector(const vector<T>& vect);
	void push_back(T val);
	void pop_back();
	bool empty();
	unsigned int max_size();
	unsigned int size();
	vector<T>& operator=(const vector<T>& vect);
	bool operator ==(const vector<T>& vect);
	T& operator[](int i); // ��� �������� ������ �� �������
	T& at(int i); // ���� �������� ������ �� �������
	T& front(); // ������ � �������� ��������
	T& back(); // ������ � ���������� ��������
	iterator erase(iterator pos); // ������� ������� � ������� pos (������ ��������, ��������� �� ��������� ��������� ���������)
	iterator erase(iterator first, iterator last); // ������� ������� � ��������� [first; last)
	void clear(); // ������� ��� �������� �������
	~vector();
};


// ���������� ������� �������� ��������� ��� �������

template<class T>
vector<T>::iterator::iterator(T* x) : cur(x) {}

template<class T>
vector<T>::iterator::iterator(const iterator& i) : cur(i.cur) {}

template<class T>
bool vector<T>::iterator::operator !=(iterator i) {
	return cur != i.cur;
}

template<class T>
bool vector<T>::iterator::operator ==(iterator i) {
	return cur == i.cur;
}

template<class T>
bool vector<T>::iterator::operator <(iterator i) {
	return cur < i.cur;
}

template<class T>
bool vector<T>::iterator::operator >(iterator i) {
	return cur > i.cur;
}

template<class T>
bool vector<T>::iterator::operator <=(iterator i) {
	return cur <= i.cur;
}

template<class T>
bool vector<T>::iterator::operator >=(iterator i) {
	return cur >= i.cur;
}

template<class T>
typename vector<T>::iterator vector<T>::iterator::operator++(int) { 
	iterator t(cur);
	++cur;
	return t;
}

template<class T>
typename vector<T>::iterator& vector<T>::iterator::operator++() {
	++cur;
	return *this;
}

template<class T>
typename vector<T>::iterator vector<T>::iterator::operator--(int) {
	iterator t(cur);
	--cur;
	return t;
}

template<class T>
typename vector<T>::iterator& vector<T>::iterator::operator--() {
	--cur;
	return *this;
}

template<class T>
typename vector<T>::iterator vector<T>::iterator::operator+(int n) {
	return iterator(cur + n);
}

template<class T> 
typename vector<T>::iterator& vector<T>::iterator::operator+=(int n) {
	cur += n;
	return *this;
}

template<class T>
typename vector<T>::iterator vector<T>::iterator::operator-(int n) {
	return iterator(cur - n);
}

template<class T> 
typename vector<T>::iterator& vector<T>::iterator::operator-=(int n) {
	cur -= n;
	return *this;
}

template<class T>
T vector<T>::iterator::operator-(iterator it) {
	return (cur - it.cur);
}

template<class T>
T& vector<T>::iterator::operator*() {
	return *cur;
}

template<class T>
T& vector<T>::iterator::operator[](int n) {
	return *(*this + n); 
}

template<class T>
T* vector<T>::iterator::base() {
	return cur;
}



// ���������� ������� ��������� ��������� ��� �������

template<class T>
vector<T>::reverse_iterator::reverse_iterator(T* x) : cur(x) {}

template<class T>
vector<T>::reverse_iterator::reverse_iterator(const reverse_iterator& i) : cur(i.cur) {}

template<class T>
bool vector<T>::reverse_iterator::operator !=(reverse_iterator i) {
	return cur != i.cur;
}

template<class T>
bool vector<T>::reverse_iterator::operator ==(reverse_iterator i) {
	return cur == i.cur;
}

template<class T>
bool vector<T>::reverse_iterator::operator <(reverse_iterator i) {
	return cur > i.cur;
}

template<class T>
bool vector<T>::reverse_iterator::operator >(reverse_iterator i) {
	return cur < i.cur;
}

template<class T>
bool vector<T>::reverse_iterator::operator <=(reverse_iterator i) {
	return cur >= i.cur;
}

template<class T>
bool vector<T>::reverse_iterator::operator >=(reverse_iterator i) {
	return cur <= i.cur;
}

template<class T>
typename vector<T>::reverse_iterator vector<T>::reverse_iterator::operator++(int) { 
	reverse_iterator t(cur);
	--cur;
	return t;
}

template<class T>
typename vector<T>::reverse_iterator& vector<T>::reverse_iterator::operator++() {
	--cur;
	return *this;
}

template<class T>
typename vector<T>::reverse_iterator vector<T>::reverse_iterator::operator--(int) {
	reverse_iterator t(cur);
	++cur;
	return t;
}

template<class T>
typename vector<T>::reverse_iterator& vector<T>::reverse_iterator::operator--() {
	++cur;
	return *this;
}

template<class T>
typename vector<T>::reverse_iterator vector<T>::reverse_iterator::operator+(int n) {
	return reverse_iterator(cur - n);
}

template<class T> 
typename vector<T>::reverse_iterator& vector<T>::reverse_iterator::operator+=(int n) {
	cur -= n;
	return *this;
}

template<class T>
typename vector<T>::reverse_iterator vector<T>::reverse_iterator::operator-(int n) {
	return reverse_iterator(cur + n);
}

template<class T> 
typename vector<T>::reverse_iterator& vector<T>::reverse_iterator::operator-=(int n) {
	cur += n;
	return *this;
}

template<class T>
T& vector<T>::reverse_iterator::operator*() {
	return *cur;
}

template<class T>
T& vector<T>::reverse_iterator::operator[](int n) {
	return *(*this + n); 
}

template<class T>
T* vector<T>::reverse_iterator::base() {
	return cur;
}



// ���������� ������� �������

template<class T>
typename vector<T>::iterator vector<T>::begin() {
	return iterator(a);
}

template<class T>
typename vector<T>::iterator vector<T>::end() {
	return iterator(a + size_a);
}

template<class T>
typename vector<T>::reverse_iterator vector<T>::rbegin() { // ��������� �������
	return reverse_iterator(a + size_a - 1);
};

template<class T>
typename vector<T>::reverse_iterator vector<T>::rend() { // �������, ������� ����� ����� �������
	return reverse_iterator(a - 1);
}

template<class T>
vector<T>::vector() : size_a(0), max_size_a(100) {
	a = new T[max_size_a];
}

template<class T> // ������� ������ �� n+100 ��������� � �������������� ��� ������
vector<T>::vector(unsigned int n) : size_a(n), max_size_a(n + 100) {
	a = new T[max_size_a];
	for (int i = 0; i < size_a; i++)
		a[i] = 0;
}

template<class T>
vector<T>::vector(T* p, unsigned int n) {
	size_a = n;
	a = new T[n];
	for (int i = 0; i < n; i++)
		a[i] = p[i];
}

template<class T>
vector<T>::vector(const vector<T>& vect) {
	size_a = vect.size_a;
	max_size_a = vect.max_size_a;
	a = new T[vect.size_a];
	for (int i = 0; i < vect.size_a; i++)
		a[i] = vect.a[i];
}

template<class T>
void vector<T>::push_back(T val) {
	if (size_a + 1 <= max_size_a) { // ���� ������� ������ ������� + 1 ������ ���� ����� ������������ �����
		a[size_a++] = val;
	}
	else { // ������������ ������ ��������� (�� ������ ������������ ����� ������� � 2 ���� ������ ����������)
		int new_max_size_a = max(2 * max_size_a, max_size_a + 1);  // ������� ����� ��������������� ������ new_a[] � 2 ���� ������ ������� a[] (max_size==0)
		T* new_a = new T[new_max_size_a];
		for (int i = 0; i < size_a; i++)
			new_a[i] = a[i];
		new_a[size_a] = val; // �������� � ���� ���������� ������� �[] � ��������� ����� �������� val
		if (max_size_a >= 1)
			delete[]a;
		size_a++;
		max_size_a = new_max_size_a;
		a = new T[new_max_size_a];
		for (int i = 0; i <= size_a; i++) // a=new_a
			a[i] = new_a[i];
		if (new_max_size_a >= 1)
			delete[]new_a; // ������� ��������������� ������
	}
}

template<class T>
void vector<T>::pop_back() {
	size_a--;
}

template<class T>
bool vector<T>::empty() {
	return size_a == 0;
}

template<class T>
unsigned int vector<T>::max_size() {
	return max_size_a;
}

template<class T>
unsigned int vector<T>::size() {
	return size_a;
}

template<class T>
vector<T>& vector<T>::operator=(const vector<T>& vect) {
	delete[]a;
	size_a = vect.size_a;
	max_size_a = vect.max_size_a;
	a = new T[vect.size_a];
	for (int i = 0; i < vect.size_a; i++)
		a[i] = vect.a[i];
	return *this;
}

template<class T>
bool vector<T>::operator==(const vector<T>& vect) {
	if (size_a != vect.size_a)
		return false;
	else {
		for (int i = 0; i < size_a; i++)
			if (a[i] != vect.a[i])
				return false;
		return true;
	}
}

template<class T>
T& vector<T>::operator[](int i) {
	return a[i];
}

template<class T>
T& vector<T>::at(int i) {
	if (!(i >= 0 && i < size_a))
		throw out_of_range("It is not allowed operation!"); 
	else
		return a[i];
}

template<class T>
T& vector<T>::front() {
	if (!empty()) // ���� ��������� �� ����
		return a[0];
	else
		throw out_of_range("It is not allowed operation!");
}

template<class T>
T& vector<T>::back() {
	if (!empty())
		return a[size_a - 1];
	else
		throw out_of_range("It is not allowed operation!");
}

template<class T>
typename vector<T>::iterator vector<T>::erase(iterator pos) {
	if (!(pos >= begin() && pos < end()))
		throw out_of_range("It is not allowed operation!");
	else {
		size_a--;
		vector<T>::iterator l = pos;
		vector<T>::iterator r = vector<T>::iterator(a + size_a);
		for (vector<T>::iterator it = l; it != r; it++)
			*it = *(it + 1);
		return pos;
	}
}

template<class T>
typename vector<T>::iterator vector<T>::erase(iterator first, iterator last) {
	if (!(first >= begin() && first <= end() && last >= begin() && last <= end() && first <= last)) 
		throw out_of_range("It is not allowed operation!");
	else {
		int d = last - first;
		size_a -= d;
		vector<T>::iterator l = first;
		vector<T>::iterator r = vector<T>::iterator(a + size_a);
		for (vector<T>::iterator it = l; it != r; it++)
			*it = *(it + d);
		return last;
	}
}

template<class T>
void vector<T>::clear() {
	size_a = 0;
	max_size_a = 0;
	delete[]a;
}

template<class T>
vector<T>::~vector() {
	delete[]a;
}


