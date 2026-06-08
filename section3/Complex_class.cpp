#include "head.h"


Complex::Complex(float re, float im) {
	real = re;
	imag = im;
}
void Complex::module() const {
	float abs_ = std::sqrt(pow(real, 2) + pow(imag, 2));
	std::cout << "module = " << abs_ << std::endl;
}
void Complex::phase() const {
	float phase;
	if (real != 0.0) phase = std::atan(imag / real);
	else (imag > 0 ? phase = PI / 2 : phase = -PI / 2);
	std::cout << "phase = " << phase << std::endl;
}
Complex Complex::operator+(const Complex& num1) const {
	Complex res{ 0., 0. };
	res.real = this->real + num1.real;
	res.imag = this->imag + num1.imag;
	return res;
}
Complex Complex::operator-(const Complex& num1) const {
	Complex res{ 0., 0. };
	res.real = this->real - num1.real;
	res.imag = this->imag - num1.imag;
	return res;
}
Complex Complex::operator*(const Complex& num1) const {
	Complex res{ 0., 0. };
	double a, b, c, d;
	a = this->real; b = this->imag; c = num1.real; d = num1.imag;
	res.real = a * c - b * d;
	res.imag = a * d + b * c;
	return res;
}
void Complex::show() {
	cout << "real = " << real << " imag = " << imag << endl;
}