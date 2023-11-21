#include "./edge_detector.hpp"

#include "../simulation.hpp"

int main() {
	bool input;
	bool rising_edge;

	for (int i = 0; i < 10; ++i) {
		input = false;
		edge_detector(input, &rising_edge);
		CHECK(!rising_edge);
	}

	input = true;
	edge_detector(input, &rising_edge);
	CHECK(rising_edge);

	for (int i = 0; i < 10; ++i) {
		input = true;
		edge_detector(input, &rising_edge);
		CHECK(!rising_edge);
	}

	input = false;
	edge_detector(input, &rising_edge);
	CHECK(!rising_edge);

	for (int i = 0; i < 10; ++i) {
		input = false;
		edge_detector(input, &rising_edge);
		CHECK(!rising_edge);
	}

	input = true;
	edge_detector(input, &rising_edge);
	CHECK(rising_edge);

	input = false;
	edge_detector(input, &rising_edge);
	CHECK(!rising_edge);

	return 0;
}