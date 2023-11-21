#include "./wait_delay_timer.hpp"

void                  wait_delay_timer(bool start, ap_uint<BITS> delay, bool* delayed_out) {
#pragma HLS INTERFACE mode = ap_ctrl_none port = return
#pragma HLS INTERFACE mode = ap_none port = start
#pragma HLS INTERFACE mode = ap_none port = delay
#pragma HLS INTERFACE mode = ap_none port = delayed_out

	static bool          is_waiting = false;
	static ap_uint<BITS> counter    = 0;

	if (start && delay != 0) {
		is_waiting   = true;
		counter      = delay - 1;
		*delayed_out = false;
	} else if (start && delay == 0) {
		is_waiting   = false;
		counter      = 0;
		*delayed_out = true;
	} else if (is_waiting && counter > 0) {
		is_waiting = true;
		counter--;
		*delayed_out = false;
	} else if (is_waiting && counter == 0) {
		is_waiting   = false;
		counter      = 0;
		*delayed_out = true;
	} else {
		*delayed_out = false;
	}
}