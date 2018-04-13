#include "QInt.h"

//Reference: https://codescracker.com/cpp/program/cpp-program-convert-hexadecimal-to-binary.htm
string HexStringToBinString(string hex)
{
	string bin = "";
	for (int i = 0; i < hex.length(); i++)
	{
		switch (toupper(hex[i]))
		{
		case '0': bin.append("0000"); break;
		case '1': bin.append("0001"); break;
		case '2': bin.append("0010"); break;
		case '3': bin.append("0011"); break;
		case '4': bin.append("0100"); break;
		case '5': bin.append("0101"); break;
		case '6': bin.append("0110"); break;
		case '7': bin.append("0111"); break;
		case '8': bin.append("1000"); break;
		case '9': bin.append("1001"); break;
		case 'A': bin.append("1010"); break;
		case 'B': bin.append("1011"); break;
		case 'C': bin.append("1100"); break;
		case 'D': bin.append("1101"); break;
		case 'E': bin.append("1110"); break;
		case 'F': bin.append("1111"); break;
		}
	}
	return bin;
}

string BinStringToBHexString(string bin)
{
	string hex = "";
	string tmp = "0000";
	for (int j = 0; j < 128; j += 4)
	{
		tmp = bin.substr(j, 4);
		if (!tmp.compare("0000")) bin += "0";
		else if (!tmp.compare("0001")) hex += "1";
		else if (!tmp.compare("0010")) hex += "2";
		else if (!tmp.compare("0011")) hex += "3";
		else if (!tmp.compare("0100")) hex += "4";
		else if (!tmp.compare("0101")) hex += "5";
		else if (!tmp.compare("0110")) hex += "6";
		else if (!tmp.compare("0111")) hex += "7";
		else if (!tmp.compare("1000")) hex += "8";
		else if (!tmp.compare("1001")) hex += "9";
		else if (!tmp.compare("1010")) hex += "A";
		else if (!tmp.compare("1011")) hex += "B";
		else if (!tmp.compare("1100")) hex += "C";
		else if (!tmp.compare("1101")) hex += "D";
		else if (!tmp.compare("1110")) hex += "E";
		else if (!tmp.compare("1111")) hex += "F";
		else continue;
	}

	return hex;
}

QInt::QInt()
{
	arrayBits[0] = 0;
	arrayBits[1] = 0;
}

QInt::QInt(const QInt& a)
{
	arrayBits[0] = a.arrayBits[0];
	arrayBits[1] = a.arrayBits[1];
}

QInt::~QInt()
{
}

string QInt::QIntToBin()
{
		string Bin = "";
		for (int i = 0; i<128; i++)
		{
			if (this->getBit(i))
				Bin += '1';//Bin.insert(0, "1");
			else
				Bin += '0';//Bin.insert(0, "0");
			
		}
		return Bin;
}

bool QInt::BinToQInt(string bin)
{
	QInt a;
	//Nếu ko đủ 128 bit thì add 0 vào đầu chuỗi
	int n = bin.length();
	if (n < 128)
	{
		for (int i = n; i < 128; i++)
		{
			bin.insert(0,"0");
		}
	}
	for (int i = 0; i < 128; i++)
	{
		//if (bin.at(abs(i-127))==0) turnOff(i);
		if (bin[i] == '1')  a.turnOn(i);
	}
	*this = a;
	return true;
}

string QInt::QIntToHex()
{
	string bin = QIntToBin();
	string hex = BinStringToBHexString(bin);
	return hex;
}

bool QInt::HexToQInt(string hex)
{
	string bin = HexStringToBinString(hex);
	this->BinToQInt(bin);
	return true;

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
	int pos;
	QInt bu2 = *this;
	
	for (int i = 127; i >= 0; i--)
		if (bu2.getBit(i)) {
			pos = i;
			break;
		}
		
	for (int i = 0; i < pos; i++)
		bu2.ToogleBit(i);
	return bu2;
}

QInt& QInt::operator = (const QInt &num)
{
	if (this == &num)
		return *this;

	arrayBits[0] = num.arrayBits[0];
	arrayBits[1] = num.arrayBits[1];
	return *this;
}

QInt QInt::operator+(QInt &a)
{
	QInt obj;
	bool carry = 0;//bit nhớ
	for (int i = 127; i >= 0; i--)
	{
		if (carry == 0)//không nhớ
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
		else//có nhớ
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