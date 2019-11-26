#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <vector>
#include <algorithm>
#include <string>
#include "heapsort.h"
#include "shell_sort.h"



template <typename T>
void made_vec_unsort(std::vector<T>& v) {
	std::for_each(v.begin(), v.end(), [](T& a) {a = rand(); });
}

template <typename T>
void made_vec_10persent(std::vector<T>& v) {
	int n = v.size() / 10;
	for (int i = 0; i < n; i++) {
		v[i] = rand();
	}
}

template <typename T>
void made_vec_5persent(std::vector<T>& v) {
	int n = v.size() / 20;
	for (int i = 0; i < n; i++) {
		v[i] = rand();
	}
}

template <typename T>
void made_vec_5(std::vector<T>& v) {
	int n = v.size() * 5 / 100;
	for (int i = 0; i < 4; i++) {
		v[rand() % v.size()] = rand();
	}
}


template<typename T>
void test_sort_time(size_t g) {
	std::vector<T> v(1000000);
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

	//заполняем вектор слычайными данными
	made_vec_unsort(v);
	start = std::chrono::high_resolution_clock::now();
	//сортировка вектора
	shell_sort(v, g);
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Sort unsorted vec, gap = " << g << ", time:" << std::chrono::duration_cast<std::chrono::milliseconds>
		(end - start).count() << " ms;" << std::endl;

	//10 процентов данных не отсортированы
	made_vec_10persent(v);
	start = std::chrono::high_resolution_clock::now();
	//сортировка вектора
	shell_sort(v, g);
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Sort 10 persent unsorted vec, gap = " << g << ", time:" << std::chrono::duration_cast<std::chrono::milliseconds>
		(end - start).count() << " ms;" << std::endl;

	//5 элементов не отсортированы
	made_vec_5(v);
	start = std::chrono::high_resolution_clock::now();
	//сортировка вектора
	shell_sort(v, g);
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Sort 5 persent unsorted vec, gap = " << g << ", time:" << std::chrono::duration_cast<std::chrono::milliseconds>
		(end - start).count() << " ms;" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
}


//замер времени сортировки методом heapsort
template<typename T>
void test_heap_sort_time(size_t size) {
	std::vector<T> v(size);
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

	//заполняем вектор случайными данными
	made_vec_unsort(v);
	start = std::chrono::high_resolution_clock::now();
	//сортировка вектора
	heap_sort(v);
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Heap sort unsorted vec, time:" << std::chrono::duration_cast<std::chrono::milliseconds>
		(end - start).count() << " ms;" << std::endl;

	//5 процентов данных не отсортированы
	made_vec_5persent(v);
	start = std::chrono::high_resolution_clock::now();
	//сортировка вектора
	heap_sort(v);
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Heap sort 5 persent unsorted vec, time:" << std::chrono::duration_cast<std::chrono::milliseconds>
		(end - start).count() << " ms;" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
}

template<typename T>
void test_shell_sort_time(size_t size, size_t g) {
	std::vector<T> v(size);
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

	//заполняем вектор слычайными данными
	made_vec_unsort(v);
	start = std::chrono::high_resolution_clock::now();
	//сортировка вектора
	shell_sort(v, g);
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Sort unsorted vec, gap = " << g << ", time:" << std::chrono::duration_cast<std::chrono::milliseconds>
		(end - start).count() << " ms;" << std::endl;

	//5 процентов данных не отсортированы
	made_vec_5persent(v);
	start = std::chrono::high_resolution_clock::now();
	//сортировка вектора
	shell_sort(v, g);
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Sort 10 persent unsorted vec, gap = " << g << ", time:" << std::chrono::duration_cast<std::chrono::milliseconds>
		(end - start).count() << " ms;" << std::endl;

	std::cout << "-----------------------------------" << std::endl;
}
