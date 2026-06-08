#include "head.h"

int main() {
	Complex num1{ 1., 2. };
	Complex num2{ 3., 2. };
	Complex num3{0., 0.};
	num3 = num1 + num2;
	num3.show();
	num3 = num1 - num2;
	num3.show();
	num3 = num1 * num2;
	num3.show();

	GenDataBits bits{ 10 };
	bits.setValue();
	bits.show();

	Codec codec{ 10, 3 };
	codec.code(bits.getPtr());
	codec.decode();
	codec.show();
}
