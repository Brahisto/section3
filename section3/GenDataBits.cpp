#include "head.h"

GenDataBits::GenDataBits(int len = 0) {
	if (len == 0) {
		bits_ = nullptr;
		len_ = 0;
	}
	else {
		bits_ = new int[len];
		len_ = len;
	}
}
GenDataBits::~GenDataBits() {
	delete[] bits_;
}

void GenDataBits::setValue() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, 1);
	for (int i{}; i < len_; i++) {
		*(bits_ + i) = dist(gen);
	}
}
int* GenDataBits::getPtr() const {
	return bits_;
}

void GenDataBits::show() {
	for (int i{}; i < len_; i++) {
		cout << *(bits_ + i) << " ";
	}
	cout << endl;
}