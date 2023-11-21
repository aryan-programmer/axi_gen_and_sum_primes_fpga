#ifndef WAIT_DELAY_TIMER_HPP
#define WAIT_DELAY_TIMER_HPP

#include "../common.hpp"

void wait_delay_timer(bool start, ap_uint<BITS> delay, bool* delayed_out);

#endif  // WAIT_DELAY_TIMER_HPP