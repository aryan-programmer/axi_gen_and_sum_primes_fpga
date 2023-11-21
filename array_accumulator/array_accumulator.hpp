#ifndef ARRAY_ACCUMULATOR_HPP
#define ARRAY_ACCUMULATOR_HPP

#include "../common.hpp"

constexpr i64 MAX_ACCUMULATION = std::numeric_limits<data_t>::max() * MAX_SIZE;

void array_accumulator(data_t                             arr[MAX_SIZE],
					   size_upto_t<MAX_SIZE + 1>          size,
					   size_upto_t<MAX_ACCUMULATION + 1>* sum);

#endif  // ARRAY_ACCUMULATOR_HPP