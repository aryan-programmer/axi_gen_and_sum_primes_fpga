#include "./debouncer.hpp"

#include "../simulation.hpp"

int main() {
	bool input;
	bool output;

	for (int i = 0; i < DEBOUNCE_COUNTER_MIN; ++i) {
		input = false;
		debouncer(input, &output);
		CHECK(!output);
	}

	input = true;
	debouncer(input, &output);
	CHECK(output);
	for (int i = 1; i < DEBOUNCE_COUNTER_MIN; ++i) {
		input = false;
		debouncer(input, &output);
		CHECK(output, << ": i=" << i);
	}

	for (int i = 0; i < DEBOUNCE_COUNTER_MIN; ++i) {
		input = false;
		debouncer(input, &output);
		CHECK(!output, << ": i=" << i);
	}

	for (int i = 0; i < DEBOUNCE_COUNTER_MIN / 10; ++i) {
		input = true;
		debouncer(input, &output);
		CHECK(output);
		input = false;
		debouncer(input, &output);
		CHECK(output);
	}
	for (int i = 0; i < DEBOUNCE_COUNTER_MIN * 10; ++i) {
		input = true;
		debouncer(input, &output);
		CHECK(output);
	}

	for (int i = 0; i < DEBOUNCE_COUNTER_MIN / 10; ++i) {
		input = false;
		debouncer(input, &output);
		CHECK(!output);
		input = true;
		debouncer(input, &output);
		CHECK(!output);
	}
	for (int i = 0; i < DEBOUNCE_COUNTER_MIN * 10; ++i) {
		input = false;
		debouncer(input, &output);
		CHECK(!output);
	}

	return 0;
}