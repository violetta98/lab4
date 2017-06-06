#pragma once 
using std::out_of_range;

template<class T>
class list { // ���������� ������
	struct Node {
		T data;
		Node *next, *prev; // ��������� �� ������ ���� � ���� ��������� ������
	};
	Node *head, *tail;
	unsigned int _size; // ���������� ��������� � ������
public:
	class iterator { // � ��� ������� �������� �� ����������� ���� ������, �� � ������� :)
		Node* cur;
	public:
		iterator(Node* n);
		iterator(iterator& i);
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
		T& operator*();
		T* base();
	};
	class reverse_iterator {
		Node* cur;
	public:
		reverse_iterator(Node* n);
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
		T& operator*();
		T* base();
	};
	iterator begin(); // ��������� ������ �������
	iterator end(); // ��������� �� �������, ��� ����� ����� ����������
	reverse_iterator rbegin(); // ��������� �������
	reverse_iterator rend(); // �������, ������� ����� ����� �������
	list();
	bool empty();
	unsigned int size();
	void push_back(T val);
	~list();
};


// ���������� ������� �������� ��������� ��� ������
template<class T>
list<T>::iterator::iterator(Node* n) : cur(n) {}

template<class T>
list<T>::iterator::iterator(iterator& i) : cur(i.cur) {}

template<class T>
bool list<T>::iterator::operator !=(iterator i) {
	return cur != i.cur;
}

template<class T>
bool list<T>::iterator::operator ==(iterator i) {
	return cur == i.cur;
}

template<class T>
bool list<T>::iterator::operator <(iterator i) {
	return cur < i.cur;
}

template<class T>
bool list<T>::iterator::operator >(iterator i) {
	return cur > i.cur;
}

template<class T>
bool list<T>::iterator::operator <=(iterator i) {
	return cur <= i.cur;
}

template<class T>
bool list<T>::iterator::operator >=(iterator i) {
	return cur >= i.cur;
}

template<class T>
typename list<T>::iterator list<T>::iterator::operator++(int) {
	iterator tmp(cur);
	cur = cur->next;
	return tmp;
}

template<class T>
typename list<T>::iterator& list<T>::iterator::operator++() {
	cur = cur->next;
	return *this;
}

template<class T>
typename list<T>::iterator list<T>::iterator::operator--(int) {
	iterator tmp(cur);
	cur = cur->prev;
	return tmp;
}

template<class T>
typename list<T>::iterator& list<T>::iterator::operator--() {
	cur = cur->prev;
	return *this;
}

template<class T>
T& list<T>::iterator::operator*() {
	return cur->data;
}

template<class T>
T* list<T>::iterator::base() {
	return cur;
}



// ���������� ������� ��������� ��������� ��� ������

template<class T>
list<T>::reverse_iterator::reverse_iterator(Node* n) : cur(n) {}

template<class T>
list<T>::reverse_iterator::reverse_iterator(const reverse_iterator& i) : cur(i.cur) {}

template<class T>
bool list<T>::reverse_iterator::operator !=(reverse_iterator i) {
	return cur != i.cur;
}

template<class T>
bool list<T>::reverse_iterator::operator ==(reverse_iterator i) {
	return cur == i.cur;
}

template<class T>
bool list<T>::reverse_iterator::operator <(reverse_iterator i) {
	return cur > i.cur;
}

template<class T>
bool list<T>::reverse_iterator::operator >(reverse_iterator i) {
	return cur < i.cur;
}

template<class T>
bool list<T>::reverse_iterator::operator <=(reverse_iterator i) {
	return cur >= i.cur;
}

template<class T>
bool list<T>::reverse_iterator::operator >=(reverse_iterator i) {
	return cur <= i.cur;
}

template<class T>
typename list<T>::reverse_iterator list<T>::reverse_iterator::operator++(int) {
	reverse_iterator tmp(cur);
	cur = cur->prev;
	return tmp;
}

template<class T>
typename list<T>::reverse_iterator& list<T>::reverse_iterator::operator++() {
	cur = cur->prev;
	return *this;
}

template<class T>
typename list<T>::reverse_iterator list<T>::reverse_iterator::operator--(int) {
	reverse_iterator tmp(cur);
	cur = cur->next;
	return tmp;
}

template<class T>
typename list<T>::reverse_iterator& list<T>::reverse_iterator::operator--() {
	cur = cur->next;
	return *this;
}

template<class T>
T& list<T>::reverse_iterator::operator*() {
	return cur->data;
}

template<class T>
T* list<T>::reverse_iterator::base() {
	return cur;
}


// ���������� ������� ������

template<class T>
typename list<T>::iterator list<T>::begin() {
	return iterator(head);
}

template<class T>
typename list<T>::iterator list<T>::end() {
	return iterator((Node*)(NULL));
}

template<class T>
typename list<T>::reverse_iterator list<T>::rbegin() {
	return reverse_iterator(tail);
}

template<class T>
typename list<T>::reverse_iterator list<T>::rend() {
	return reverse_iterator((Node*)(NULL));
}

template<class T>
list<T>::list() : head(NULL), tail(NULL), _size(0) {}

template<class T>
bool list<T>::empty() {
	return _size == 0;
}

template<class T>
unsigned int list<T>::size() {
	return _size;
}

template<class T>
void list<T>::push_back(T val) {
	Node* tmp = new Node; // ������� ����� ���
	tmp->next = NULL; // ��������� ������� ��������� � NULL
	tmp->data = val; // ���������� ������ � ��� ����� ���
	if (head == NULL) { // ������ ����
		tmp->prev = NULL; // ���������� ������� ��������� � NULL
		head = tmp; // ������ � ����� ��������� �� ���� � ��� �� �������
		tail = tmp;
	}
	else { // ������ ������� ����� � ������� �� ������� ������
		tmp->prev = tail; // ��������� ����� �� ���� ���
		tail->next = tmp; // ��������� ����� ��������� ���� �� �������
		tail = tmp; // ������ ����� ������
	}
	_size++;
}

template<class T>
list<T>::~list() {
	Node* tmp = new Node;
	while (head != NULL) {
		tmp = head->next;
		delete head;
		head = tmp; // ����������� ������ ������
		_size--;
	}
}



