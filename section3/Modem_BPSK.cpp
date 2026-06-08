#include "head.h"

Modem::Modem(int* bits = nullptr, float* sym = nullptr, int* rec_bits = nullptr, int n = 0, float edge = 0.) {
	bits_ = bits;
	sym_ = sym;
	rec_bits_ = rec_bits;
	edge_ = edge;
	n_ = n;
}

float* Modem::getPtrSym() {
	return sym_;
}

void Modem::bpsk_mod(int n) {
	for (int i{}; i < n; i++) {
		if (*(bits_ + i) == 1) *(sym_ + i) = 1.;
		else *(sym_ + i) = -1.;
	}
}
void Modem::bpsk_demod(int n) {
	for (int i{}; i < n; i++) {
		if (*(sym_ + i) > edge_) *(rec_bits_ + i) = 1;
		else *(rec_bits_ + i) = 0;
	}
}
void Modem::show() {
	for (int i{}; i < n_; i++) {
		std::cout << "bit -> " << *(bits_ + i) << "  sym -> " << *(sym_ + i) << " demodul bit -> " << *(rec_bits_ + i) << std::endl;
	}
}