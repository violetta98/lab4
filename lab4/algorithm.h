#pragma once

template<class T>
void my_swap(T&a, T&b) {
	T c = a;
	a = b;
	b = c;
}

//template<class iter> // быстрая сортировка (очень странно себя ведет при переключении между реализациями)
//void sort(iter begin, iter end) {
//	iter ri = begin, rj = end - 1; 
//	iter rm = begin; // в качестве опорного элемента берем "первый"
//	while (ri <= rj) {
//		while (*ri < *rm) ri++;
//		while (*rm < *rj) rj--;
//		if (ri <= rj) {
//			my_swap(*ri, *rj);
//			ri++;
//			rj--;
//		}
//	}
//	if (ri < end - 1)
//		sort(ri, end);
//	if (rj > begin)
//		sort(begin, rj + 1);
//}

// TEMPLATE FUNCTION for_each
template<class iter, class Function> 
void _For_each(iter begin, iter end, Function &action) {
	for (iter it = begin; it != end; it++)
		action(*it);
}

template<class iter, class Function> // algorithm 153
Function for_each(iter begin, iter end, Function action) { 
	_For_each(begin, end, action);                         
	return action;
}

template<class T>
T max(T a, T b) {
	T c = a;
	if (b > a)
		c = b;
	return c;
}

template<class T>
T min(T a, T b) {
	T c = a;
	if (b < a)
		c = b;
	return c;
}

template<class iter, class predicate>
iter find_if(iter begin, iter end, predicate p) {
	for (; begin != end; begin++)
		if (p(*begin))
			break;
	return begin;
}








