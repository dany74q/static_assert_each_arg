#include "static_assert_each_arg.h"
#include <type_traits>

int main() {
	static_assert_each_arg<std::is_integral>(1, 2); // OK
	std::wstring w;
	static_assert_each_arg<std::is_same, false, std::wstring>(1, w, 2.0); // Fail
}