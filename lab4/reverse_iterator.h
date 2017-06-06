#pragma once

template<class iter>
struct iter_traits {
	typedef typename iter::value_type value_type;
	typedef typename iter::reference reference;
	typedef typename iter::pointer pointer;
};

template<class T>
struct iter_traits <T*> {
	typedef typename T value_type;
	typedef typename T& reference;
	typedef typename T* pointer;
};

template<class iter>
class reverse_iterator {
	iter cur;
public:
	typedef reverse_iterator<iter> RI;
	typedef typename iter_traits<iter>::value_type value_type;
	typedef typename iter_traits<iter>::reference reference;
	typedef typename iter_traits<iter>::pointer pointer;
	reverse_iterator() : cur() {}
	reverse_iterator(iter i) : cur(i) {}
	reverse_iterator(const RI& i) : cur(i.cur) {}
	bool operator !=(RI i) {
		return cur != i.cur;
	}
	bool operator ==(RI i) {
		return cur == i.cur;
	}
	bool operator <(RI i) {
		return cur > i.cur;
	}
	bool operator >(RI i) {
		return cur < i.cur;
	}
	bool operator <=(RI i) {
		return cur >= i.cur;
	}
	bool operator >=(RI i) {
		return cur <= i.cur;
	}
	RI operator++(int) { // постфиксный инкремент
		RI t(*this);
		cur--;
		return t;
	}
	RI& operator++() { // префиксный инкремент
		cur--;
		return *this;
	}
	RI operator--(int) { // постфиксный декремент
		RI t(*this);
		cur++;
		return t;
	}
	RI& operator--() { // префиксный декремент
		cur++;
		return *this;
	}
	RI operator+(int n) {
		return RI(cur - n);
	}
	RI operator-(int n) {
		return RI(cur + n);
	}
	reference operator *() {
		iter t(cur);
		return *--t;
	}
};



