#include <cstdlib>
#include <ctime>
#include <chrono>
#include "test_func.h"


int main() {

	std::srand(std::time(nullptr));

	test_heap_sort_time<int>(4000000);
	test_shell_sort_time<int>(4000000, 4);

	//			  Heap_sort   Shell_sort
	// unsorted_vec   	=  48009ms 	59275ms
	// unsor_5_elements	=  46504ms 	28209ms
	return 0;
}
