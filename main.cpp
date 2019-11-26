#include <cstdlib>
#include <ctime>
#include <chrono>
#include "test_func.h"


int main() {

	std::srand(std::time(nullptr));

	test_heap_sort_time<int>(2000000);
	test_shell_sort_time<int>(2000000, 3);

	//			    Heap_sort           Shell_sort
	// unsorted_vec   	 =  37104ms     	39038ms
	// unsorted_vec		 =  35640ms 		30380ms

	return 0;
}
