#ifndef FOUR_DIGIT_7_SEG_DRIVER_HPP
#define FOUR_DIGIT_7_SEG_DRIVER_HPP

#include "../common.hpp"

void four_digit_7_seg_driver(bool        next_digit,
							 ap_uint<4>  digit_1,
							 ap_uint<4>  digit_2,
							 ap_uint<4>  digit_3,
							 ap_uint<4>  digit_4,
							 ap_uint<4>  dp_enable,
							 ap_uint<4> *seg_select,
							 ap_uint<7> *seg_display,
							 bool       *seg_dp);

#endif  // FOUR_DIGIT_7_SEG_DRIVER_HPP
