#include "./array_accumulator.hpp"

#include <algorithm>
#include <bitset>

#include "../simulation.hpp"

using namespace std;

data_t primes[] = {2,  3,  5,  7,  11, 13, 17, 19, 23,  29,  31,  37,  41,  43,  47,  53, 59,
				   61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137};

int main() {
	int                               sum_cpu  = 0;
	size_upto_t<MAX_ACCUMULATION + 1> sum_fpga = 0;
	for (int i = 0; i <= MAX_SIZE; i++) {
		cout << "i = " << i << ", sum_cpu = " << sum_cpu << "("
			 << bitset<msbi64(next_pow_of_2(MAX_ACCUMULATION + 1))>(sum_cpu) << ")" << endl;
		array_accumulator(primes, i, &sum_fpga);
		CHECK(sum_fpga == sum_cpu);
		sum_cpu += primes[i];
	}
	cout << "---------------------------------\n"
		 << "All tests successfull\n"
		 << "---------------------------------\n";
	return 0;
}