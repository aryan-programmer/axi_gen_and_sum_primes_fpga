#include "./array_writer.hpp"

#include <algorithm>

#include "../simulation.hpp"

using namespace std;

data_t primes[] = {2,  3,  5,  7,  11, 13, 17, 19, 23,  29,  31,  37,  41,  43,  47,  53, 59,
				   61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137};

int main() {
	data_t zeros[MAX_SIZE] = {};
	data_t arr[MAX_SIZE];
	for (int i = 0; i <= MAX_SIZE; i++) {
		// cout << "i = " << i << endl;
		array_writer(arr, i);
		CHECK(std::equal(primes, primes + i, arr));
		CHECK(std::equal(arr + i, arr + MAX_SIZE, zeros));
	}
	cout << "---------------------------------\n"
		 << "All tests successfull\n"
		 << "---------------------------------\n";
	return 0;
}