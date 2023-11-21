#include "./edge_detector.hpp"

void                  edge_detector(bool input, bool *rising_edge) {
#pragma HLS INTERFACE mode = ap_ctrl_none port = return
#pragma HLS INTERFACE mode = ap_none port = input
#pragma HLS INTERFACE mode = ap_none port = rising_edge

	static bool past_input = false;

	*rising_edge = !past_input && input;
	past_input   = input;
}