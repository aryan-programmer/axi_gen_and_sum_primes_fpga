#include "./array_writer.hpp"

template <bool cond>
struct sassert {
	static_assert(cond, "!");
	static bool const value = false;
};

constexpr i64 MAX_NUM_FOR_PRIME = (sassert<MAX_SIZE == 32>::value, 140);

// constexpr unsigned short isqrt(unsigned long a) {
// 	unsigned long rem  = 0;
// 	int           root = 0;

// 	for (int i = 0; i < 16; i++) {
// #pragma HLS UNROLL
// 		root <<= 1;
// 		rem <<= 2;
// 		rem += a >> 30;
// 		a <<= 2;

// 		if (root < rem) {
// 			root++;
// 			rem -= root;
// 			root++;
// 		}
// 	}

// 	return (unsigned short)(root >> 1);
// }

void                  array_writer(data_t arr[MAX_SIZE], size_upto_t<MAX_SIZE + 1> size) {
#pragma HLS PIPELINE  off
#pragma HLS INTERFACE mode = ap_ctrl_hs port = return
#pragma HLS INTERFACE mode = m_axi port = arr offset = off bundle = arr_axi
#pragma HLS INTERFACE mode = ap_none port = size
	/*
	for (size_upto_t<MAX_SIZE + 1> i = 0; i < MAX_SIZE; i++) {
#pragma HLS          UNROLL
#pragma HLS PIPELINE off
		if (i < size) {
			arr[i] = (i + 1) * 2;
		} else {
			arr[i] = 0;
		}
	}
	/*/
	size_upto_t<MAX_SIZE + 1>  arr_w = 0;
	ap_uint<MAX_NUM_FOR_PRIME> sieve = 0;
	if (size >= 1) {
		arr[arr_w] = 2;
		arr_w++;
	}
	for (size_upto_t<MAX_NUM_FOR_PRIME + 1> i = 3;
		 i < MAX_NUM_FOR_PRIME && arr_w < size && arr_w < MAX_SIZE;
		 i += 2) {
#pragma HLS LOOP_TRIPCOUNT max = 32
#pragma HLS PIPELINE       off

		// printf("i = %d\n", i.to_int());

		if (sieve[i]) continue;

		auto step = i << 1;
		for (size_upto_t<MAX_NUM_FOR_PRIME* 2 + 1> j = i; j < MAX_NUM_FOR_PRIME; j += step) {
			// printf("j = %d,", j.to_int());
#pragma HLS PIPELINE       off
#pragma HLS LOOP_TRIPCOUNT max = 70
			sieve[j] = true;
		}
		// printf("\ni = %d is a prime\n", i.to_int());

		arr[arr_w] = i;
		arr_w++;
	}

	for (; arr_w < MAX_SIZE; arr_w++) {
#pragma HLS PIPELINE       off
#pragma HLS LOOP_TRIPCOUNT max = 32
		arr[arr_w] = 0;
		// printf("arr_w = %d\n", arr_w.to_int());
	}
	//*/

	/*
	size_upto_t<MAX_NUM_FOR_PRIME + 1> prime_test_i = 3;
	for (size_upto_t<MAX_SIZE + 1> arr_w = 0; arr_w < MAX_SIZE; arr_w++) {
#pragma HLS                UNROLL
#pragma HLS PIPELINE       off
#pragma HLS LOOP_TRIPCOUNT max = 32
		if (arr_w == 0) {
			arr[arr_w] = 2;
		} else if (arr_w >= size) {
			arr[arr_w] = 0;
		} else {
			for (; prime_test_i < MAX_NUM_FOR_PRIME; prime_test_i += 2) {
#pragma HLS LOOP_TRIPCOUNT max = 7
#pragma HLS PIPELINE       off

				// printf("i = %d\n", i.to_int());

				if (sieve[prime_test_i]) continue;

				auto step = prime_test_i << 1;
				for (size_upto_t<MAX_NUM_FOR_PRIME* 2 + 1> j = prime_test_i; j < MAX_NUM_FOR_PRIME;
					 j += step) {
					// printf("j = %d,", j.to_int());
#pragma HLS PIPELINE       off
#pragma HLS LOOP_TRIPCOUNT max = 70
					sieve[j] = true;
				}
				// printf("\ni = %d is a prime\n", i.to_int());

				arr[arr_w] = prime_test_i;
				break;
			}
		}
		arr[arr_w] = 0;
		// printf("arr_w = %d\n", arr_w.to_int());
	}
*/
}