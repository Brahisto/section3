#include "head.h"

ComplexGenerator::ComplexGenerator(int n, float f) {
	if (n > 0) {
		len_ = n;
		real_sig = new float[n];
		imag_sig = new float[n];
		real_noise = new float[n];
		imag_noise = new float[n];
		freq = f;
	}
	else {
		real_sig = nullptr;
		imag_sig = nullptr;
		real_noise = nullptr;
		imag_noise = nullptr;
		len_ = 0;
	}
}
ComplexGenerator::~ComplexGenerator() {
	delete[] real_sig;
	delete[] imag_sig;
	delete[] real_noise;
	delete[] imag_noise;
}
void ComplexGenerator::show(int k = 0) {
	switch (k) {
	case 0:
		for (int i{}; i < len_; i++) {
			cout << *(real_sig + i) << " " << *(imag_sig + i) << endl;
		}
		break;
	case 1:
		for (int i{}; i < len_; i++) {
			std::cout << *(real_noise + i) << " " << *(imag_noise + i) << std::endl;
		}
	}
}
void ComplexGenerator::init_sig() {
	float dT = 0.01;
	for (int i{}; i < len_; i++) {
		*(real_sig + i) = cos(2*PI * freq *i*dT);
		*(imag_sig + i) = sin(2*PI*freq*i*dT);
	}
}

void ComplexGenerator::init_noise() {
	mt19937 gen_r(-1.2);
	normal_distribution<float> dist_r(0);

	mt19937 gen_i(1.5);
	normal_distribution<float> dist_i(0);
	for (int i{}; i < len_; i++) {
		*(real_noise + i) = dist_r(gen_r);
		*(imag_noise + i) = dist_i(gen_i);
	}
}