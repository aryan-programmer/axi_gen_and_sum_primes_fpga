#include "./wait_delay_timer.hpp"

#include "../simulation.hpp"

int main() {
	bool start = true;
	int  delay = 20;
	bool delayed_out;

	wait_delay_timer(start, delay, &delayed_out);
	CHECK(!delayed_out);
	delay--;

	while (delay > 0) {
		wait_delay_timer(false, 0, &delayed_out);
		CHECK(!delayed_out);
		delay--;
	}

	wait_delay_timer(false, 0, &delayed_out);
	CHECK(delayed_out);

	wait_delay_timer(false, 0, &delayed_out);
	CHECK(!delayed_out);
	wait_delay_timer(false, 0, &delayed_out);
	CHECK(!delayed_out);

	return 0;
}