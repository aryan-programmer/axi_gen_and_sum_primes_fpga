#ifndef SWITCH_MASTER_WIRE_TO_AXI_HPP
#define SWITCH_MASTER_WIRE_TO_AXI_HPP

#include "../common.hpp"

void switch_master_wire_to_axi(ap_uint<16> wire_in,
							   ap_uint<8> *axi_out1,
							   ap_uint<8> *axi_out2,
							   ap_uint<8> *wire_out1,
							   ap_uint<8> *wire_out2);

#endif  // SWITCH_MASTER_WIRE_TO_AXI_HPP
