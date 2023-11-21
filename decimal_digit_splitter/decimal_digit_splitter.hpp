#ifndef DECIMAL_DIGIT_SPLITTER_HPP
#define DECIMAL_DIGIT_SPLITTER_HPP

#include "../common.hpp"

constexpr unsigned int DECIMAL_DIGIT_SPLITTER_MAX_INCL = 9999;

void decimal_digit_splitter(counter_t<DECIMAL_DIGIT_SPLITTER_MAX_INCL> input,
							ap_uint<4>                                *digit_1,
							ap_uint<4>                                *digit_2,
							ap_uint<4>                                *digit_3,
							ap_uint<4>                                *digit_4);

#endif  // DECIMAL_DIGIT_SPLITTER_HPP