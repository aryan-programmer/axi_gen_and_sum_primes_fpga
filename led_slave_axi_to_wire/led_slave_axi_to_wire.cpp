#include "./led_slave_axi_to_wire.hpp"

void led_slave_axi_to_wire(ap_uint<8> axi_in1, ap_uint<8> axi_in2, ap_uint<8> *wire_out) {
#pragma HLS INTERFACE mode = ap_ctrl_none port = return
#pragma HLS INTERFACE mode = s_axilite port = axi_in1 bundle = BUS_A
#pragma HLS INTERFACE mode = s_axilite port = axi_in2 bundle = BUS_A
#pragma HLS INTERFACE mode = ap_none port = wire_out
	*wire_out = axi_in1 | axi_in2;
}