#ifndef UTILS_SIMULATION_HPP
#define UTILS_SIMULATION_HPP
#define BOOST_STACKTRACE_USE_WINDBG
// #if defined(WIN32)
// #pragma comment(lib, "Ole32.lib")
// #pragma comment(lib, "DbgEng.lib")
// #endif
// #include <boost/stacktrace.hpp>
#include <iostream>

#define CHECK(input, ...)                                                            \
	do {                                                                             \
		bool __testing_input = input;                                                \
		if (!__testing_input) {                                                      \
			::std::cout << "Assertion failed at " << __FILE__ << ":" << __LINE__     \
						<< " in function " << __func__ << ": " << #input __VA_ARGS__ \
						<< ::std::endl;                                              \
			::std::exit(-1);                                                         \
		}                                                                            \
	} while (0)
#endif  // UTILS_SIMULATION_HPP