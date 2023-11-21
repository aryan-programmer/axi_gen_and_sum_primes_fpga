#include "./four_digit_7_seg_driver.hpp"

#include "../simulation.hpp"

struct tester {
	bool       next;
	ap_uint<4> digit_1;
	ap_uint<4> digit_2;
	ap_uint<4> digit_3;
	ap_uint<4> digit_4;
	ap_uint<4> dp_enable;
	ap_uint<4> seg_select;
	ap_uint<7> seg_display;
	bool       seg_dp;

	void exec() {
		four_digit_7_seg_driver(next,
								digit_1,
								digit_2,
								digit_3,
								digit_4,
								dp_enable,
								&seg_select,
								&seg_display,
								&seg_dp);
	}

	void cycle_exec() {
		next = false;
		exec();

		ap_uint<4> old_seg_select  = seg_select;
		ap_uint<7> old_seg_display = seg_display;
		bool       old_seg_dp      = seg_dp;
		next                       = true;
		exec();
		CHECK(seg_select == old_seg_select);
		CHECK(seg_display == old_seg_display);
		CHECK(seg_dp == old_seg_dp);
	}

	void test_with_data(ap_uint<4> digit_1,
						ap_uint<4> digit_2,
						ap_uint<4> digit_3,
						ap_uint<4> digit_4,
						ap_uint<4> dp_enable) {
		this->digit_1   = digit_1;
		this->digit_2   = digit_2;
		this->digit_3   = digit_3;
		this->digit_4   = digit_4;
		this->dp_enable = dp_enable;

		for (int i = 0; i < 10; i++) {
			cycle_exec();
			CHECK(seg_select == 0b1110, << ": i=" << i);
			CHECK(from_7_seg(seg_display) == digit_1, << ": i=" << i);
			CHECK(seg_dp == !dp_enable[0], << ": i=" << i);

			cycle_exec();
			CHECK(seg_select == 0b1101, << ": i=" << i);
			CHECK(from_7_seg(seg_display) == digit_2, << ": i=" << i);
			CHECK(seg_dp == !dp_enable[1], << ": i=" << i);

			cycle_exec();
			CHECK(seg_select == 0b1011, << ": i=" << i);
			CHECK(from_7_seg(seg_display) == digit_3, << ": i=" << i);
			CHECK(seg_dp == !dp_enable[2], << ": i=" << i);

			cycle_exec();
			CHECK(seg_select == 0b0111, << ": i=" << i);
			CHECK(from_7_seg(seg_display) == digit_4, << ": i=" << i);
			CHECK(seg_dp == !dp_enable[3], << ": i=" << i);
		}
	}
};

int main() {
	tester t;
	t.test_with_data(1, 2, 3, 4, 0b0010);
	t.test_with_data(2, 4, 5, 7, 0b0101);
	return 0;
}