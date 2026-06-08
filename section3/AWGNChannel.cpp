#include "head.h"

AWGNChannel::AWGNChannel(float* input = nullptr, int len = 0, float SNR = 0.) {
	input_signal = input;
	len_ = len;
	SNR_ = SNR;
}
void AWGNChannel::gen_val() {
	float P_sig = 0.;
	for (int i{}; i < len_; i++) {
		P_sig += pow(*(input_signal + i), 2);
	}
	P_sig /= len_;
	float P_n = P_sig / pow(10., SNR_ / 10);
	float stddev = sqrt(P_n);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<float> dist_noise(0., stddev);
	for (int i{}; i < len_; i++) {
		*(input_signal + i) += dist_noise(gen);
	}
}