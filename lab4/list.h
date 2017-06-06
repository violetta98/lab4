#pragma once 
using std::out_of_range;

template<class T>
class list { // двусвязный список
	struct Node {
		T data;
		Node *next, *prev; // указатели на адреса след и пред элементов списка
	};
	Node *head, *tail;
	unsigned int _size; // количество элементов в списке
public:
	class iterator { // и тут обычный итератор не обязательно было делать, но я сделала :)
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
		iterator operator++(int); // постфиксный инкремент
		iterator& operator++(); // префиксный инкремент
		iterator operator--(int); // постфиксный декремент
		iterator& operator--(); // префиксный декремент
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
		reverse_iterator operator++(int); // постфиксный инкремент
		reverse_iterator& operator++(); // префиксный инкремент
		reverse_iterator operator--(int); // постфиксный декремент
		reverse_iterator& operator--(); // префиксный декремент
		T& operator*();
		T* base();
	};
	iterator begin(); // указатель первый элемент
	iterator end(); // указатель на элемент, что стоит после последнего
	reverse_iterator rbegin(); // последний элемент
	reverse_iterator rend(); // элемент, который стоит перед нулевым
	list();
	bool empty();
	unsigned int size();
	void push_back(T val);
	~list();
};


// реализация методов обычного итератора для списка
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



// реализация методов обратного итератора для списка

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


// реализация методов списка

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
	Node* tmp = new Node; // создаем новый нод
	tmp->next = NULL; // следующий элемент указывает в NULL
	tmp->data = val; // записываем данные в наш новый нод
	if (head == NULL) { // список пуст
		tmp->prev = NULL; // предыдущий элемент указывает в NULL
		head = tmp; // голова и хвост указывают на один и тот же элемент
		tail = tmp;
	}
	else { // всегда двигаем хвост и никогда не двигаем голову
		tmp->prev = tail; // указываем адрес на пред нод
		tail->next = tmp; // указываем адрес следущего нода за хвостом
		tail = tmp; // меняем адрес хвоста
	}
	_size++;
}

template<class T>
list<T>::~list() {
	Node* tmp = new Node;
	while (head != NULL) {
		tmp = head->next;
		delete head;
		head = tmp; // передвигаем голову списка
		_size--;
	}
}



