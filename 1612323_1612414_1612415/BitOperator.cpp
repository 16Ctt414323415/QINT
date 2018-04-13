#include"QInt.h"
bool QInt::getBit(int i)
{
	int INDEX = 63 - i % 64;
	long long x = arrayBits[i / 64];
	return (1ULL << INDEX & x) >> INDEX;
}

void QInt::setBit(long long bit, int i)
{
	if (bit == 1)
		arrayBits[i / 64] |= (1 << 63 - (i % 64));
	arrayBits[i / 64] &= ~(1 << (63 - i % 64));
}

void QInt::turnOn(int i)
{
	arrayBits[i / 64] |= 1ULL << (i % 64);
}

void QInt::turnOff(int i)
{
	arrayBits[i / 64] &= ~(1ULL << (i % 64));
}

void QInt::ToogleBit(int i) {
	arrayBits[i / 64] ^= (1ULL << (i % 64));
}