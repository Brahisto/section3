#include "head.h"

int main() {
	

	GenDataBits bits{ 10 };
	bits.setValue();
	bits.show();

	Codec codec{ 10, 3 };
	codec.code(bits.getPtr());
	codec.decode();
	codec.show();
}
