#include "head.h"

FIRFilter::FIRFilter(int len) {
	if (len > 0) {
		len_ = len;
		buffer_ = new float[len];
	}
	else {
		len_ = 0;
		buffer_ = nullptr;
	}
}
FIRFilter::~FIRFilter() {
	delete[] buffer_;
}

void FIRFilter::setVal(float value, int pos) {
	if (pos < len_) {
		*(buffer_ + pos) = value;
	}
	else std::cout << "error.out of range\n";
}
void FIRFilter::cyclic_convolution(float* input, int len_sig, float* output) {
	if (len_sig > len_) {
		int d = len_sig - len_;
		app_buf(len_sig - len_);
		for (int i{ len_ - d }; i < len_sig; i++) {
			*(buffer_ + i) = 0.;
		}
		for (int i{}; i < len_sig; i++) {
			float sum = 0.;
			for (int j{}; j < len_sig; j++) {
				sum += (*(buffer_ + j)) * (*(input + j));
			}
			*(output + i) = sum;
			cyclic_right_n(input, len_sig, 1);
		}
		app_buf(-d);
	}
	else {
		for (int i{}; i < len_sig; i++) {
			float sum = 0.;
			for (int j{}; j < len_sig; j++) {
				sum += (*(buffer_ + j)) * (*(input + j));
			}
			*(output + i) = sum;
			cyclic_right_n(input, len_sig, 1);
		}
	}
}

void FIRFilter::app_buf(int n) {
	float* new_ptr = new float[len_ + n];
	if (n > 0) {
		for (int i{}; i < len_; i++) {
			*(new_ptr + i) = *(buffer_ + i);
		}
	}
	else {
		for (int i{}; i < len_ + n; i++) {
			*(new_ptr + i) = *(buffer_ + i);
		}
	}

	buffer_ = new_ptr;

	len_ += n;
}