#include "./switch_master_wire_to_axi.hpp"

void                  switch_master_wire_to_axi(ap_uint<16> wire_in,
												ap_uint<8> *axi_out1,
												ap_uint<8> *axi_out2,
												ap_uint<8> *wire_out1,
												ap_uint<8> *wire_out2) {
#pragma HLS INTERFACE mode = ap_ctrl_hs port = return
#pragma HLS INTERFACE mode = ap_none port = wire_in
#pragma HLS INTERFACE mode = m_axi port = axi_out1 bundle = BUS_A offset = direct
#pragma HLS INTERFACE mode = m_axi port = axi_out2 bundle = BUS_A offset = direct
#pragma HLS INTERFACE mode = ap_vld port = wire_out1
#pragma HLS INTERFACE mode = ap_vld port = wire_out2

	*axi_out1 = *wire_out1 = wire_in(7, 0);
	*axi_out2 = *wire_out2 = wire_in(15, 8);
}