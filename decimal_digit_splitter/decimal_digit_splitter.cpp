#include "./decimal_digit_splitter.hpp"

constexpr i64 BASE = 10;

void                  decimal_digit_splitter(counter_t<DECIMAL_DIGIT_SPLITTER_MAX_INCL> input,
											 ap_uint<4>                                *digit_1,
											 ap_uint<4>                                *digit_2,
											 ap_uint<4>                                *digit_3,
											 ap_uint<4>                                *digit_4) {
#pragma HLS PIPELINE  II   = 1
#pragma HLS INTERFACE mode = ap_ctrl_none port = return
#pragma HLS INTERFACE mode = ap_vld port = input
#pragma HLS INTERFACE mode = ap_none port = digit_1
#pragma HLS INTERFACE mode = ap_none port = digit_2
#pragma HLS INTERFACE mode = ap_none port = digit_3
#pragma HLS INTERFACE mode = ap_none port = digit_4
	counter_t<DECIMAL_DIGIT_SPLITTER_MAX_INCL / BASE>        input_div_10 = div_const<BASE>(input);
	counter_t<DECIMAL_DIGIT_SPLITTER_MAX_INCL / BASE / BASE> input_div_100 =
		div_const<BASE * BASE>(input);
	counter_t<DECIMAL_DIGIT_SPLITTER_MAX_INCL / BASE / BASE / BASE> input_div_1000 =
		div_const<BASE * BASE * BASE>(input);

	*digit_1 = input - mul_const<BASE>(input_div_10);
	*digit_2 = input_div_10 - mul_const<BASE>(input_div_100);
	*digit_3 = input_div_100 - mul_const<BASE>(input_div_1000);
	*digit_4 = input_div_1000;
}