#ifndef SEG_DRIVER_CLOCK_DIVIDER_HPP
#define SEG_DRIVER_CLOCK_DIVIDER_HPP

#include "../common.hpp"

// 10ns * 600'000'000 -> 6s
/*
constexpr size_t CLOCK_DIVISON_FACTOR = 600'000'000;
/*/
constexpr size_t CLOCK_DIVISON_FACTOR = 500'000;
//*/

void seg_driver_clock_divider(bool input, bool *output);

#endif  // SEG_DRIVER_CLOCK_DIVIDER_HPP