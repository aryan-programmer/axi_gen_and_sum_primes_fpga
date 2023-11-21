#ifndef LED_SLAVE_AXI_TO_WIRE_HPP
#define LED_SLAVE_AXI_TO_WIRE_HPP

#include "../common.hpp"

void led_slave_axi_to_wire(ap_uint<16> axi_in, ap_uint<16>* wire_out);

#endif  // LED_SLAVE_AXI_TO_WIRE_HPP