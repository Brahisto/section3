#include "head.h"

RingBuffer::RingBuffer(int len) {
	if (len > 0) {
		buffer_ = new float[len];
		len_ = len;
		for (int i{}; i < len; i++) {
			*(buffer_ + i) = 0.;
		}
		free = len_;
	}
	else {
		len_ = 0;
		buffer_ = nullptr;
	}
}
RingBuffer::~RingBuffer() {
	delete[] buffer_;
}

void RingBuffer::push(float val) {
	if (head == len_) isFull = true;
	if (isFull) tail = (tail + 1) % len_, head %= len_;
	*(buffer_ + head++) = val;
	if (free >= 0) free--;
}
void RingBuffer::pop() {
	float cur = *(buffer_ + tail);
	*(buffer_ + tail) = 0.;
	isFull = false;
	tail = (tail + 1) % len_;
	head %= len_;
	if (free < len_) free++;
	std::cout << cur << std::endl;
}
void RingBuffer::EmptySpace() {
	std::cout << "empty -> " << free << std::endl;
}