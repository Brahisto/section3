#include <iostream>
#include <cmath>
#include <random>
constexpr float PI = 3.14159;
#ifndef HEAD_H
#define HEAD_H
using namespace std;
void movingAverage(float*, int, int);
void cyclic_left_n(float *,int, int);
void cyclic_right_n(float* , int, int);

class Complex {
	float real;
	float imag;
public:
	Complex(float, float);
	void module() const;
	void phase() const;
	Complex operator+(const Complex&) const;
	Complex operator-(const Complex&) const;
	Complex operator*(const Complex&) const;

	void show();
};

class Buffer {
	float* pBuffer;
	int len_buf;

public:
	Buffer(int len);
	Buffer(const Buffer&) = delete;
	Buffer& operator=(const Buffer&) = delete;

	~Buffer();

	void setVal(float, int);
	void getVal(int);
	void app_buf(int);
};

class Modem {
	int* bits_; //generated bits -> 0110101011010
	float* sym_; //gen symbols bpsk -> -1+1+1..
	int* rec_bits_; //received bits (sig + noise)
	int n_; //len of sequence
	float edge_; // decsion-makeing threshold
public:
	Modem(int*, float*, int*, int, float);
	void bpsk_mod(int);
	void bpsk_demod(int);
	float* getPtrSym();
	void show();
};

class GenDataBits {
	int* bits_;
	int len_;
public:
	GenDataBits(int);
	~GenDataBits();
	void setValue();
	int* getPtr() const;
	void show();
};

class dataSyms {
	float* sym_;
	int len_;
public:
	dataSyms(int);
	~dataSyms();
	float* getPtr() const;
};

class dataReceive {
	int* rec_bits_;
	int len_;
public:
	dataReceive(int len = 0) {
		if (len == 0) {
			rec_bits_ = nullptr;
			len_ = 0;
		}
		else {
			rec_bits_ = new int[len];
			len_ = len;
		}
	}
	~dataReceive() {
		delete[] rec_bits_;
	}
	int* getPtr() const {
		return rec_bits_;
	}

};

class AWGNChannel {
	float* input_signal;
	float SNR_;
	int len_;
public:
	AWGNChannel(float*, int, float);
	void gen_val();
};

class FIRFilter {
	float* buffer_;
	int len_;
public:
	FIRFilter(int);
	~FIRFilter();
	void setVal(float, int);
	void cyclic_convolution(float*, int len_sig, float*);
	void app_buf(int);
};

class RingBuffer {
	int len_;
	float* buffer_;
	int head = 0;
	int tail = 0;
	bool isFull = false;
	int free = 0;
public:
	RingBuffer(int);
	~RingBuffer();

	void push(float);
	void pop();
	void EmptySpace();
};

class Codec {
	int repeat_;
	int len_output_;
	int len_input_;
	int* coder_output_;
	int* decoder_output_;
public:
	Codec(int, int);
	~Codec();

	void code(int*);
	void decode();
	void show();
};

class ComplexGenerator {
	float* real_sig;
	float* imag_sig;
	float* real_noise;
	float* imag_noise;
	int len_;
public:
	ComplexGenerator(int);
	~ComplexGenerator();
	void show(int);
	void init_sig();
	void init_noise();
};
#endif