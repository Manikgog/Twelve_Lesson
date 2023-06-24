﻿#include <iostream>
#include <string>
#include <bitset>

class Address;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Mask
{
private:
	unsigned char _first_oktet;
	unsigned char _second_oktet;
	unsigned char _third_oktet;
	unsigned char _fouth_oktet;
	Mask StringToMask(std::string str);
	
public:
	Mask();
	Mask(std::string mask);
	Mask(int first_oktet, int second_oktet, int third_oktet, int fouth_oktet);
	bool IsRespondAddressToMask(const Address addr);
	unsigned int AmountOfNodes();
	friend std::istream& operator>>(std::istream& in, std::string mask);
	int* StringToArr(std::string str);
	long long int IPToLongInt();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Address
{
private:
	unsigned char _first_oktet;
	unsigned char _second_oktet;
	unsigned char _third_oktet;
	unsigned char _fouth_oktet;
	Address StringToAddress(std::string str);
	bool IsValidIP();
public:
	Address();
	Address(std::string addr);
	Address(int first_oktet, int second_oktet, int third_oktet, int fouth_oktet);
	Address(long long int addr);
	int* StringToArr(std::string str);
	bool IsValidIP(std::string);
	bool IsValidIP(int first_oktet, int second_oktet, int third_oktet, int fouth_oktet);
	bool operator==(const Address addr);
	bool operator<(const Address& addr);
	Address ConvertToNetworkAddress(Mask& mask);
	long long int IPToLongInt();
	friend std::istream& operator>>(std::istream& in, std::string addr);
	
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Mask::Mask() : _first_oktet(0), _second_oktet(0), _third_oktet(0), _fouth_oktet(0) {}

Mask::Mask(std::string mask)
{
	*this = StringToMask(mask);
}

Mask::Mask(int first_oktet, int second_oktet, int third_oktet, int fouth_oktet)
	: _first_oktet(first_oktet), _second_oktet(second_oktet), _third_oktet(third_oktet), _fouth_oktet(fouth_oktet) {}

bool Mask::IsRespondAddressToMask(const Address addr)
{
	return true;
}

Mask Mask::StringToMask(std::string str)
{
	int* arr = StringToArr(str);

	Mask tmp_addr(arr[0], arr[1], arr[2], arr[3]);
	return tmp_addr;
}


int* Mask::StringToArr(std::string str)
{
	int arr[4]{};						// цифра 4 - количество октетов в маске или адресе
	std::string s_tmp;
	char c;

	for (size_t i = 0, j = 0; i <= str.length(); ++i)
	{
		if ((str[i] == '.' || i == str.length()) && s_tmp.length() != 0)
		{
			arr[j] = stoi(s_tmp);
			s_tmp.erase();
			j++;
			if (j == 4) break;
		}

		if (str[i] >= '0' && str[i] <= '9')
		{
			c = str[i];
			s_tmp += c;
		}
	}
	return arr;
}

long long int Mask::IPToLongInt()
{
	long long int addressInLongLong = 0;

	addressInLongLong = ((long long int)_first_oktet << 24);
	addressInLongLong |= ((long long int)_second_oktet << 16);
	addressInLongLong |= ((long long int)_third_oktet << 8);
	addressInLongLong |= ((long long int)_fouth_oktet);
		
	/*const int n = 32;
	std::string binary = std::bitset<n>(addressInLongLong).to_string();
	std::cout << binary << std::endl; */       
	return addressInLongLong;
}

unsigned int Mask::AmountOfNodes()
{
	int razryad = 1;
	int count = 0;
	long long int maskInLongLongInt = IPToLongInt();
	while (1)
	{
		if (1 & maskInLongLongInt)
			break;
		maskInLongLongInt >>= 1;
		count++;
	}
	return (unsigned int)std::pow(2, count) - 2;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Address::Address() : _first_oktet(0), _second_oktet(0), _third_oktet(0), _fouth_oktet(0) {}

Address::Address(std::string addr)
{
	*this = StringToAddress(addr);
	if (!IsValidIP())
		std::cout << "Адрес невалидный!\n";
}

Address::Address(int first_oktet, int second_oktet, int third_oktet, int fouth_oktet)
	: _first_oktet(first_oktet), _second_oktet(second_oktet), _third_oktet(third_oktet), _fouth_oktet(fouth_oktet) {}

bool Address::IsValidIP(std::string str)
{
	Address addr{ StringToAddress(str) };
	return addr.IsValidIP();
}

Address::Address(long long int addr)
{
	_first_oktet = (addr >> 24);
	_second_oktet = ((addr >> 16) << 24) >> 24;
	_third_oktet = ((addr >> 8) << 24) >> 24;
	_fouth_oktet = ((addr) << 24) >> 24;
}

bool Address::IsValidIP(int first_oktet, int second_oktet, int third_oktet, int fouth_oktet)
{
	if ((first_oktet >= 0 && first_oktet <= 255) &&
		(second_oktet >= 0 && second_oktet <= 255) &&
		(third_oktet >= 0 && third_oktet <= 255) &&
		(fouth_oktet >= 0 && fouth_oktet <= 255))
		return true;
	else
		return false;
}

bool Address::IsValidIP()
{
	if ((_first_oktet >= 0 && _first_oktet <= 255) &&
		(_second_oktet >= 0 && _second_oktet <= 255) &&
		(_third_oktet >= 0 && _third_oktet <= 255) &&
		(_fouth_oktet >= 0 && _fouth_oktet <= 255))
		return true;
	else
		return false;
}



bool Address::operator==(const Address addr)
{
	if (_first_oktet == addr._first_oktet &&
		_second_oktet == addr._second_oktet &&
		_third_oktet == addr._third_oktet &&
		_fouth_oktet == addr._fouth_oktet)
		return true;
	else
		return false;
}

bool Address::operator<(const Address& addr)
{

	return true;
}

Address Address::StringToAddress(std::string str)
{
	int* arr = StringToArr(str);
	Address tmp_addr(arr[0], arr[1], arr[2], arr[3]);
	return tmp_addr;
}

int* Address::StringToArr(std::string str)
{
	int arr[4]{};						// цифра 4 - количество октетов в маске или адресе
	std::string s_tmp;
	char c;

	for (size_t i = 0, j = 0; i <= str.length(); ++i)
	{
		if ((str[i] == '.' || i == str.length()) && s_tmp.length() != 0)
		{
			arr[j] = stoi(s_tmp);
			s_tmp.erase();
			j++;
			if (j == 4) break;
		}

		if (str[i] >= '0' && str[i] <= '9')
		{
			c = str[i];
			s_tmp += c;
		}
	}
	return arr;
}

long long int Address::IPToLongInt()
{
	long long int addressInLongLong = 0;

	addressInLongLong = ((long long int)_first_oktet << 24);
	addressInLongLong |= ((long long int)_second_oktet << 16);
	addressInLongLong |= ((long long int)_third_oktet << 8);
	addressInLongLong |= ((long long int)_fouth_oktet);

	/*const int n = 32;
	std::string binary = std::bitset<n>(addressInLongLong).to_string();
	std::cout << binary << std::endl; */
	return addressInLongLong;
}

Address Address::ConvertToNetworkAddress(Mask& mask)
{
	long long int maskInlonglongInt = mask.IPToLongInt();
	long long int addrInLongLongInt = this->IPToLongInt();
	Address addr(maskInlonglongInt & addrInLongLongInt);
	return addr;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::istream& operator>>(std::istream& in, Mask& mask)
{
	std::string str;
	std::getline(in, str);
	int* arr = mask.StringToArr(str);

	Mask tmp_addr(arr[0], arr[1], arr[2], arr[3]);
	mask = tmp_addr;
	return in;
}


std::istream& operator>>(std::istream& in, Address& addr)
{
	std::string str;
	std::getline(in, str);
	int* arr = addr.StringToArr(str);

	Address tmp_addr(arr[0], arr[1], arr[2], arr[3]);
	addr = tmp_addr;
	return in;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	Mask m1("255.255.254.0");
	
	std::cout << m1.AmountOfNodes();
	




	return 0;
}

