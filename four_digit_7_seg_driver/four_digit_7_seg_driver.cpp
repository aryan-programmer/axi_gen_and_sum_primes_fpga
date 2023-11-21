#include "./four_digit_7_seg_driver.hpp"

void                  four_digit_7_seg_driver(bool        next_digit,
											  ap_uint<4>  digit_1,
											  ap_uint<4>  digit_2,
											  ap_uint<4>  digit_3,
											  ap_uint<4>  digit_4,
											  ap_uint<4>  dp_enable,
											  ap_uint<4> *seg_select,
											  ap_uint<7> *seg_display,
											  bool       *seg_dp) {
#pragma HLS INTERFACE mode = ap_ctrl_none port = return
#pragma HLS INTERFACE mode = ap_none port = next_digit
#pragma HLS INTERFACE mode = ap_none port = digit_1
#pragma HLS INTERFACE mode = ap_none port = digit_2
#pragma HLS INTERFACE mode = ap_none port = digit_3
#pragma HLS INTERFACE mode = ap_none port = digit_4
#pragma HLS INTERFACE mode = ap_none port = dp_enable
#pragma HLS INTERFACE mode = ap_none port = seg_select
#pragma HLS INTERFACE mode = ap_none port = seg_display
#pragma HLS INTERFACE mode = ap_none port = seg_dp

	static ap_uint<2> state = 0;

	ap_uint<4> t_seg_select = 0b1111;
	ap_uint<4> t_digit      = 0;
	bool       t_seg_dp     = !dp_enable[state];

	switch (state) {
	case 0:
		t_digit      = digit_1;
		t_seg_select = 0b1110;
		break;
	case 1:
		t_digit      = digit_2;
		t_seg_select = 0b1101;
		break;
	case 2:
		t_digit      = digit_3;
		t_seg_select = 0b1011;
		break;
	case 3:
		t_digit      = digit_4;
		t_seg_select = 0b0111;
		break;
	}

	*seg_select  = t_seg_select;
	*seg_display = to_7_seg(t_digit);
	*seg_dp      = t_seg_dp;
	if (next_digit) {
		state++;
	}
}