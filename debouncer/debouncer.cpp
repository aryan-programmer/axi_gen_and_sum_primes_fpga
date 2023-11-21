#include "./debouncer.hpp"

void                  debouncer(bool input, bool* output) {
#pragma HLS INTERFACE mode = ap_ctrl_none port = return
#pragma HLS INTERFACE mode = ap_none port = input
#pragma HLS INTERFACE mode = ap_none port = output

	static bool                            is_debouncing = false;
	static bool                            prev_output   = false;
	static counter_t<DEBOUNCE_COUNTER_MIN> counter       = DEBOUNCE_COUNTER_MIN;

	bool next_output = false;
	if (!is_debouncing && prev_output != input) {
		is_debouncing = true;
		counter       = DEBOUNCE_COUNTER_MIN - 1;
		next_output   = input;
	} else if (!is_debouncing && prev_output == input) {
		is_debouncing = false;
		counter       = DEBOUNCE_COUNTER_MIN;
		next_output   = input;
	} else if (counter == 1) {
		is_debouncing = false;
		counter       = DEBOUNCE_COUNTER_MIN;
		next_output   = prev_output;
	} else {
		is_debouncing = true;
		counter--;
		next_output = prev_output;
	}

	*output = prev_output = next_output;
}