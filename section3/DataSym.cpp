#include "head.h"

dataSyms::dataSyms(int len = 0) {
	if (len == 0) {
		sym_ = nullptr;
		len_ = 0;
	}
	else {
		sym_ = new float[len];
		len_ = len;
	}
}
dataSyms::~dataSyms() {
	delete[] sym_;
}

float* dataSyms::getPtr() const {
	return sym_;
}