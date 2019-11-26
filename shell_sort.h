#pragma once

#include <vector>

//функция сротировки методом shellsort
template <typename T>
void shell_sort(std::vector<T>& v, size_t n) {
	for (int gap = v.size() / n; gap > 0; gap /= n) {
		for (int i = 0; i + gap < v.size(); i++) {
			int j = i + gap;
			int tmp = v[j];
			while ((j - gap) >= 0 &&
				v[j - gap] > tmp) {
				v[j] = v[j - gap];
				j -= gap;
			}
			v[j] = tmp;
		}
	}
}
