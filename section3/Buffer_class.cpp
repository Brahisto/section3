#include "head.h"

Buffer::Buffer(int len) {
	pBuffer = new float[len];
	len_buf = len;
}
Buffer::~Buffer() {
	delete[] pBuffer;
}
void Buffer::setVal(float value, int n) {
	if (n < len_buf) *(pBuffer + n) = value;
	else std::cout << "error: out of range. You may make buffer's size bigger invoking app_buf()\n";
}
void Buffer::getVal(int n) {
	if (n < len_buf) std::cout << "value in " << n << " position is  " << *(pBuffer + n) << std::endl;
	else std::cout << "out of range\n";
}
void Buffer::app_buf(int n) {
	float* new_ptr = new float[len_buf + n];
	for (int i{}; i < len_buf; i++) {
		*(new_ptr + i) = *(pBuffer + i);
	}

	float* ptr_to_delete = pBuffer;

	pBuffer = new_ptr;

	len_buf += n;
}