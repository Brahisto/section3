#include "head.h"

void movingAverage(float* input, int len, int wind) {
	if (wind < len) {
		float* output = new float[len];
		for (int i{}; i < len; i++) {
			float sum = 0.;
			for (int j{}; j <= i; j++) {
				if (j < wind) sum += *(input + i - j);
			}
			*(output + i) = sum / wind;
		}
		for (int i{}; i < len; i++) {
			*(input + i) = *(output + i);
		}
		delete[] output;
	}
}

void cyclic_right_n(float* input, int len, int n) {
	float* add = new float[n];
	for (int i{ len - n }, j{}; i < len, j < n; i++, j++) {
		*(add + j) = *(input + i);
	}
	for (int i{ len - 1 }; i >= n; i--) {
		*(input + i) = *(input + i - n);
	}
	for (int i{}; i < n; i++) {
		*(input + i) = *(add + i);
	}
	delete[] add;
}

void cyclic_left_n(float* input, int len, int n) {
	float* add = new float[n];
	for (int j{}; j < n; j++) {
		*(add + j) = *(input + j);
	}
	for (int i{}; i < len - n; i++) {
		*(input + i) = *(input + i + n);
	}
	for (int i{ len - n }, j{}; (i < len) and (j < n); i++, j++) {
		*(input + i) = *(add + j);
	}
	delete[] add;
}