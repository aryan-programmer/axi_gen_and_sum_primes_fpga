#ifndef UTILS_COMMON_HPP
#define UTILS_COMMON_HPP

#include <ap_int.h>
#include <stddef.h>
#include <stdint.h>

#define _OUT
#define _IN

constexpr int BITS = 8;

using i64 = int64_t;

template <typename int_t>
int_t mul_lut(int_t a, int_t b) {
	int_t c = a * b;
#pragma HLS BIND_OP variable = c op = mul impl = fabric
#pragma HLS RESOURCE variable = c core = Mul_LUT
	return c;
}

template <typename int_t>
int_t add_lut(int_t a, int_t b) {
	int_t c = a + b;
#pragma HLS BIND_OP variable = c op = add impl = fabric
#pragma HLS RESOURCE variable = c core = AddSub
	return c;
}

template <int64_t b, typename int_t>
int_t mul_const(int_t a) {
	int_t c = a * b;
#pragma HLS BIND_OP variable = c op = mul impl = fabric
#pragma HLS RESOURCE variable = c core = Mul_LUT
	return c;
}

template <int64_t b, typename int_t>
int_t              div_const(int_t a) {
#pragma HLS INLINE off
	int_t c = a / b;
#pragma HLS BIND_OP variable = c op = mul impl = fabric
	return c;
}

template <int64_t b, typename int_t>
int_t              mod_const(int_t a) {
#pragma HLS INLINE off
	int c = a - mul_const<b, int_t>(div_const<b, int_t>(a));
	return c;
}

constexpr i64 msbi64(i64 v) {
	if (!v) return -1;
	i64 r = 0;
	while (v >>= 1) {
		r++;
	}
	return r;
}

constexpr i64 popcount(i64 v) {
	i64 r = 0;
	while (v) {
		r++;
		v &= v - 1;
	}
	return r;
}

constexpr i64 next_pow_of_2(i64 v) {
	auto v2 = 1 << msbi64(v);
	if (v == v2) {
		return v2;
	} else {
		return v2 << 1;
	}
}

template <size_t SIZE>
using size_upto_t = ap_uint<msbi64(next_pow_of_2(SIZE))>;

template <size_t VAL>
using counter_t [[deprecated]] = size_upto_t<VAL + 1>;

const ap_uint<7> to_7_seg_map[] = {
	0b1000000,
	0b1111001,
	0b0100100,
	0b0110000,
	0b0011001,
	0b0010010,
	0b0000010,
	0b1111000,
	0b0000000,
	0b0010000,
	0b0001000,
	0b0000011,
	0b1000110,
	0b0100001,
	0b0000110,
	0b0001110,
	0b1111111,
};

inline ap_uint<7> to_7_seg(ap_uint<4> in) {
	switch (in) {
	case 0:
		return 0b1000000;
	case 1:
		return 0b1111001;
	case 2:
		return 0b0100100;
	case 3:
		return 0b0110000;
	case 4:
		return 0b0011001;
	case 5:
		return 0b0010010;
	case 6:
		return 0b0000010;
	case 7:
		return 0b1111000;
	case 8:
		return 0b0000000;
	case 9:
		return 0b0010000;
	case 10:
		return 0b0001000;
	case 11:
		return 0b0000011;
	case 12:
		return 0b1000110;
	case 13:
		return 0b0100001;
	case 14:
		return 0b0000110;
	case 15:
		return 0b0001110;
	default:
		return 0b1111111;
	}
}

inline ap_uint<4> from_7_seg(ap_uint<7> in) {
	switch (in.to_int()) {
	case 0b1000000:
		return 0;
	case 0b1111001:
		return 1;
	case 0b0100100:
		return 2;
	case 0b0110000:
		return 3;
	case 0b0011001:
		return 4;
	case 0b0010010:
		return 5;
	case 0b0000010:
		return 6;
	case 0b1111000:
		return 7;
	case 0b0000000:
		return 8;
	case 0b0010000:
		return 9;
	case 0b0001000:
		return 10;
	case 0b0000011:
		return 11;
	case 0b1000110:
		return 12;
	case 0b0100001:
		return 13;
	case 0b0000110:
		return 14;
	case 0b0001110:
		return 15;
	default:
		return 0;
	}
}

constexpr i64 MAX_SIZE = 32;
constexpr i64 SIZE     = 4;

using data_t = uint8_t;

#endif  // UTILS_COMMON_HPP