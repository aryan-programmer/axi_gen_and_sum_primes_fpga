#include "./clock_divider.hpp"

#include "../simulation.hpp"

using namespace std;

int main() {
	bool clock;

	seg_driver_clock_divider(false, &clock);
	CHECK(!clock);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < CLOCK_DIVISON_FACTOR; ++j) {
			seg_driver_clock_divider(i == 0, &clock);
			CHECK(clock == (j == CLOCK_DIVISON_FACTOR - 1),
				  << ": i=" << i << ",j=" << j << ",clock=" << clock);
		}
	}

	cout << "-------------------------\n"
		 << "All tests successful.\n"
		 << "-------------------------\n"
		 << endl;

	return 0;
}