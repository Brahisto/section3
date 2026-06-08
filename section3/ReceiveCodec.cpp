#include "head.h"


Codec::Codec(int len_input, int repeat) {
	if (len_input > 0 and repeat > 0) {
		len_input_ = len_input;
		len_output_ = len_input * repeat;
		repeat_ = repeat;
		coder_output_ = new int[len_output_];
		decoder_output_ = new int[len_input];
	}
	else {
		len_input_ = 0;
		len_output_ = 0;
		repeat_ = 0;
		coder_output_ = nullptr;
		decoder_output_ = nullptr;
	}
}
Codec::~Codec() {
	delete[] coder_output_;
	delete[] decoder_output_;
}

void Codec::code(int* input) {
	for (int i{}; i < len_input_; i++) {
		for (int j{}; j < repeat_; j++) {
			*(coder_output_ + i * repeat_ + j) = *(input + i);
		}
	}
}

void Codec::decode() {
	for (int i{}; i < len_input_; i++) {
		int count_0 = 0;
		int count_1 = 0;
		for (int j{}; j < repeat_; j++) {
			if (*(coder_output_ + j) == 0) count_0++;
			else count_1++;
		}
		if (count_0 > count_1) *(decoder_output_ + i) = 0;
		else *(decoder_output_ + i) = 1;
	}
}
void Codec::show() {
	cout << "after coder: " << endl;
	for (int i{}; i < len_output_; i++) {
		cout << *(coder_output_ + i) << " ";
	}
	cout << endl;
	cout << "after decoder: " << endl;
	for (int i{}; i < len_input_; i++) {
		cout << *(decoder_output_ + i) << " ";
	}
}