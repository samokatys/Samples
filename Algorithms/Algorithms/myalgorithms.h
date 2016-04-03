#pragma once

#include <math.h>

template <class Iter, class T>
Iter seqfind(Iter begin, Iter end, T val)
{
	for (Iter elem = begin; elem != end; ++elem) {
		if ((*elem) == val) {
			return elem;
		}
	}
	return end;
}

template <class T>
int compare(T a, T b)
{
	if (a > b) {
		return 1;
	}
	else if (a < b) {
		return -1;
	}
	else {
		return 0;
	}
}

template <class Iter, class T>
Iter binfind(const Iter begin, const Iter end, T val)
{
	Iter s = begin;
	Iter e = end;
	int i = 0;
	do {
		i = (e - s) / 2;
		Iter elem = s + i;
		switch (compare(val, *elem)) {
			case -1:
				e -= i;
				break;
			case 0: return elem;
			case 1:
				s += i;
				break;
		}
	} while (i);

	return end;
}

template <class Iter>
void insertion_sort(Iter begin, Iter end)
{
	int size = end - begin;
	for (int i = 1; i < size; ++i) {
		auto val = begin[i];
		int loc = i - 1;
		while (loc >= 0 && val < begin[loc]) {
			begin[loc+1] = begin[loc];
			--loc;
		}
		
		begin[loc + 1] = val;		
	}
}

template <class T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <class Iter>
void buble_sort(Iter begin, Iter end)
{
	int size = end - begin;
	for (int unsortedElem = size - 1; unsortedElem != 0; --unsortedElem) {
		for (int i = 0; i < unsortedElem; ++i) {
			if (begin[i] > begin[i + 1]) {
				swap(begin[i], begin[i + 1]);
			}
		}
	}
}

template <class Iter>
void insertion_sort_steps(Iter begin, Iter end, int step)
{
	int size = end - begin;
	for (int i = step; i < size; i+=step) {
		auto val = begin[i];
		int loc = i - step;
		while (loc >= 0 && val < begin[loc]) {
			begin[loc + step] = begin[loc];
			loc -= step;
		}

		begin[loc + step] = val;
	}
}

template <class Iter>
void shell_sort(Iter begin, Iter end)
{
	int size = end - begin;
	int passes = log2(size);
	while (passes >= 1) {
		int increment = pow(2, passes - 1);
		for (int i = 0; i < increment; ++i) {
			insertion_sort_steps(begin + i, end, increment);
		}

		--passes;
	}
}