#include "./clock_divider.hpp"

#include "../simulation.hpp"

using namespace std;

constexpr size_t CLOCK_DIVISON_FACTOR_DIV_2 = CLOCK_DIVISON_FACTOR / 2;

int main() {
	bool clock;

	seg_driver_clock_divider(false, &clock);
	CHECK(!clock);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < CLOCK_DIVISON_FACTOR; ++j) {
			seg_driver_clock_divider(i == 0, &clock);
			CHECK(clock == (j >= CLOCK_DIVISON_FACTOR_DIV_2), << ": i=" << i << ",j=" << j);
		}
	}

	cout << "-------------------------\n"
		 << "All tests successful.\n"
		 << "-------------------------\n"
		 << endl;

	return 0;
}