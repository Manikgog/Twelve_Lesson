#include "Mask.h"
#include "Address.h"

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