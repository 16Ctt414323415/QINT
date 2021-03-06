#include "QInt.h"

//1+2=4-1=3

QInt::QInt()
{
	arrayBits[0] = arrayBits[1] = 0;
}

QInt::QInt(const QInt& a)
{
	arrayBits[0] = a.arrayBits[0];
	arrayBits[1] = a.arrayBits[1];
}

QInt::~QInt()
{
}

string QInt::QInt_to_Bin()
{
		string Bin = "";
		for (int i = 0; i < 128; i++)
		{
			if (getBit(i) == 0)
				Bin.insert(0, "0");
			else
				Bin.insert(0, "1");
		}
		return Bin;
}

QInt QInt::Bu1()
{
	QInt obj;
	for (int i = 0; i < 128; i++)
	{
		if (this->getBit(i) == 1) obj.turnOff(i);
		else obj.turnOn(i);
	}
	return obj;
}

QInt QInt::Bu2()
{
	QInt bu1 = this->Bu1();
	QInt one;
	one.setBit(1, 0);
	QInt obj = bu1 + one;
	return obj;
}

QInt& QInt::operator = (const QInt &num)
{
	if (this == &num)
		return *this;

	for (int i = 0; i < 2; i++)
		this->arrayBits[i] = num.arrayBits[i];
	return *this;
}

QInt QInt::operator+(QInt &a)
{
	QInt obj;
	int carry = 0;
	for (int i = 0; i < 128; i++)
	{
		if (carry = 0)
		{
			if (this->getBit(i) == 0 and a.getBit(i) == 0)
				obj.turnOff(i);
			else if (this->getBit(i) == 1 and a.getBit(i) == 1)
			{
				carry = 1;
				obj.turnOff(i);
			}
			else obj.turnOn(i);
		}
		else
		{
			if (this->getBit(i) == 0 && a.getBit(i) == 0)
			{
				obj.turnOn(i);
				carry = 0;
			}

			else if (this->getBit(i) == 1 && a.getBit(i) == 1) {
				obj.turnOn(i);
				carry = 1;
			}
			else
			{
				obj.turnOff(i);
				carry = 1;
			}
		}
	}
	return obj;
}