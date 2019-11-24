#pragma once
#include <vector>
#include <algorithm>


template <typename T>
int down(std::vector<T>& v, size_t root) {
	size_t size = v.size();
	size_t left = root * 2 + 1;
	size_t right = root * 2 + 2;
	size_t x = root;
	if (left < size && v[left] > v[x]) { x = left; }
	if (right < size && v[right] > v[x]) { x = right; }
	if (x == root) { return 0; }
	std::swap(v[x], v[root]);
	down(std::forward(v), x);
}

template <typename T>
int make_heap(std::vector<T>& v) {
	for (int i = v.size / 2 - 1; i > 0; i--) {
		down(std::forward(v), i);
	}
	return 0;
}

template <typename T>
int heap_sort(std::vector<T>& v) {
	make_heap(std::forward(v));
	for (int i = v.size() - 1; i > 0; i--) {
		std::swap(v[0], v[i]);
		down(std::forward(v), 0);
	}

	return 0;
}
