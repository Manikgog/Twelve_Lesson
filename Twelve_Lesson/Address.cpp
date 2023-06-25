#include "Address.h"
#include "Mask.h"

Address Address::StringToAddress(std::string str)
{
	int* arr = StringToArr(str);
	if (!IsValidIP(arr[0], arr[1], arr[2], arr[3]))
		std::cout << "Адрес невалидный!\n";
	Address tmp_mask(arr[0], arr[1], arr[2], arr[3]);
	return tmp_mask;
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


Address::Address(long long int addr)
{
	_first_oktet = (unsigned char)(addr >> 24);
	_second_oktet = (unsigned char)(((addr >> 16) << 24) >> 24);
	_third_oktet = (unsigned char)(((addr >> 8) << 24) >> 24);
	_fouth_oktet = (unsigned char)(((addr) << 24) >> 24);
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


Address::Address() : _first_oktet(0), _second_oktet(0), _third_oktet(0), _fouth_oktet(0) {}

Address::Address(std::string addr)
{
	*this = StringToAddress(addr);
}

Address::Address(int first_oktet, int second_oktet, int third_oktet, int fouth_oktet)
	: _first_oktet(first_oktet), _second_oktet(second_oktet), _third_oktet(third_oktet), _fouth_oktet(fouth_oktet) 
{
	if (!IsValidIP(first_oktet, second_oktet, third_oktet, fouth_oktet))
	{
		_first_oktet = 0;
		_second_oktet = 0;
		_third_oktet = 0;
		_fouth_oktet = 0;
	}
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
	if (_first_oktet < addr._first_oktet)
		return true;
	else if (_first_oktet == addr._first_oktet)
	{
		if (_second_oktet < addr._second_oktet)
			return true;
		else if (_second_oktet == addr._second_oktet)
		{
			if (_third_oktet < addr._third_oktet)
				return true;
			else if (_third_oktet == addr._third_oktet)
			{
				if (_fouth_oktet < addr._fouth_oktet)
					return true;
				else
					return false;
			}
		}
	}
}

Address Address::ConvertToNetworkAddress(Mask& mask)
{
	long long int maskInlonglongInt = mask.IPToLongInt();
	long long int addrInLongLongInt = this->IPToLongInt();
	Address addr(maskInlonglongInt & addrInLongLongInt);
	return addr;
}

long long int Address::IPToLongInt()
{
	long long int addressInLongLong = 0;

	addressInLongLong = ((long long int)_first_oktet << 24);
	addressInLongLong |= ((long long int)_second_oktet << 16);
	addressInLongLong |= ((long long int)_third_oktet << 8);
	addressInLongLong |= ((long long int)_fouth_oktet);

	/*
	const int n = 32;
	std::string binary = std::bitset<n>(addressInLongLong).to_string();
	std::cout << binary << std::endl;
	*/
	return addressInLongLong;
}




