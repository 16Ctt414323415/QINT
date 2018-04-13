#pragma once
#include <iostream>
#include <string>
using namespace std;


class QInt
{
	long long arrayBits[2];
	bool getBit(int i);//
	void setBit(long long bit, int i);//
	void turnOn(int i);//
	void turnOff(int i);//
	void ToogleBit(int i);//
public:
	QInt();//
	QInt(const QInt&);//
	~QInt();//
	
	string QIntToBin();//
	bool BinToQInt(string bin);//

	string QIntToHex();
	bool HexToQInt(string hex);

	bool DecToQInt(string dec);
	string QIntToDec();


	QInt Bu1();//
	QInt Bu2();//

	QInt& operator=(const QInt&);//
	QInt operator+(QInt&);//
	QInt operator-(QInt&);
	QInt operator*(QInt&);
	QInt operator/(QInt&);

	QInt operator&(QInt b);
	QInt operator|(QInt b);
	QInt operator^(QInt b);
	QInt operator~();

	QInt operator<<(int j)
	{
		QInt result = *this;
		for (int i = 0; i <= 1; i++)
			result.arrayBits[i] = this->arrayBits[i] << j;

		return result;
	}

	QInt operator>>(int j)
	{
		QInt result = *this;
		for (int i = 0; i <= 1; i++)
			result.arrayBits[i] = this->arrayBits[i] >> j;

		return result;
	}
};

string BinStringToBHexString(string bin);
string HexStringToBinString(string hex);