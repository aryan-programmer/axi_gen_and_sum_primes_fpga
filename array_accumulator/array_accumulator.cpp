#include "./array_accumulator.hpp"

void                  array_accumulator(data_t                             arr[MAX_SIZE],
										size_upto_t<MAX_SIZE + 1>          size,
										size_upto_t<MAX_ACCUMULATION + 1>* sum) {
#pragma HLS PIPELINE  off
#pragma HLS INTERFACE mode = ap_ctrl_hs port = return
#pragma HLS INTERFACE mode = m_axi port = arr offset = off bundle = arr_axi
#pragma HLS INTERFACE mode = ap_none port = size
#pragma HLS INTERFACE mode = ap_vld port = sum

	size_upto_t<MAX_ACCUMULATION + 1> sum_t = 0;
	for (size_upto_t<MAX_SIZE + 1> i = 0; i < MAX_SIZE; i++) {
#pragma HLS          UNROLL
#pragma HLS PIPELINE off
		if (i < size) {
			sum_t += arr[i];
		}
	}
	*sum = sum_t;
}