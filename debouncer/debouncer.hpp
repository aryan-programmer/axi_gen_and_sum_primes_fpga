#ifndef DEBOUNCER_HPP
#define DEBOUNCER_HPP

#include "../common.hpp"

constexpr unsigned int DEBOUNCE_COUNTER_MIN = 1'000'000;

void debouncer(bool input, bool* output);

#endif  // DEBOUNCER_HPP