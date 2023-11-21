#include "./clock_divider.hpp"

void                  seg_driver_clock_divider(bool input, bool *output) {
#pragma HLS INTERFACE mode = ap_ctrl_none port = return
#pragma HLS INTERFACE mode = ap_none port = input
#pragma HLS INTERFACE mode = ap_none port = output

	static counter_t<CLOCK_DIVISON_FACTOR> ctr     = CLOCK_DIVISON_FACTOR;
	static bool                            started = false;

	bool out = false;

	if ((!started && input) || started) {
		started = true;
		if (ctr == 0) {
			ctr = CLOCK_DIVISON_FACTOR;
			out = true;
		} else {
			ctr--;
			out = false;
		}
	} else {
		out = false;
	}
	*output = out;
}