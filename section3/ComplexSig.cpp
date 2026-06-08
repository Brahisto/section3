#include "head.h"

ComplexGenerator::ComplexGenerator(int n) {
	if (n > 0) {
		len_ = n;
		real_sig = new float[n];
		imag_sig = new float[n];
		real_noise = new float[n];
		imag_noise = new float[n];
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
	mt19937 gen_r(1.2);
	uniform_real_distribution<float> dist_r(-PI / 2, PI / 2.);

	mt19937 gen_i(1.8);
	uniform_real_distribution<float> dist_i(-PI / 2., PI / 2.);
	for (int i{}; i < len_; i++) {
		*(real_sig + i) = cos(dist_r(gen_r));
		*(imag_sig + i) = sin(dist_i(gen_i));
	}
}

void ComplexGenerator::init_noise() {
	mt19937 gen_r(-1.2);
	normal_distribution<float> dist_r(-2., 2.);

	mt19937 gen_i(1.5);
	normal_distribution<float> dist_i(-2., 2.);
	for (int i{}; i < len_; i++) {
		*(real_noise + i) = dist_r(gen_r);
		*(imag_noise + i) = dist_i(gen_i);
	}
}