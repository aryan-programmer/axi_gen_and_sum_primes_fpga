#include "./decimal_digit_splitter.hpp"

#include "../simulation.hpp"

int main() {
	ap_uint<4> digit_1, digit_2, digit_3, digit_4;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k < 10; ++k) {
				for (int l = 0; l < 10; ++l) {
					int input = i * 1000 + j * 100 + k * 10 + l;
					decimal_digit_splitter(input, &digit_1, &digit_2, &digit_3, &digit_4);
					CHECK(digit_1 == l);
					CHECK(digit_2 == k);
					CHECK(digit_3 == j);
					CHECK(digit_4 == i);
				}
			}
		}
	}

	return 0;
}