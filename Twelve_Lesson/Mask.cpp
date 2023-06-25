#include "Mask.h"
#include "Address.h"

Mask Mask::StringToMask(std::string str)
{
	int* arr = StringToArr(str);
	if (!IsValidIP(arr[0], arr[1], arr[2], arr[3]))
	{
		std::cout << "Маска невалидна!\n";
		return { 0,0,0,0 };
	}
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

bool Mask::IsValidIP(int first, int second, int third, int fouth)
{
	if ((first >= 0 && first <= 255) &&
		(second >= 0 && second <= 255) &&
		(third >= 0 && third <= 255) &&
		(fouth >= 0 && fouth <= 255))
		return true;
	else
		return false;
}

Mask::Mask() : _first_oktet(0), _second_oktet(0), _third_oktet(0), _fouth_oktet(0) {}

Mask::Mask(std::string mask)
{
	*this = StringToMask(mask);
}

Mask::Mask(int first_oktet, int second_oktet, int third_oktet, int fouth_oktet)
	: _first_oktet(first_oktet), _second_oktet(second_oktet), _third_oktet(third_oktet), _fouth_oktet(fouth_oktet) {}


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

bool Mask::CorrespondenceBetweenAddressAndMask(Address addr)
{
	Address mask((int)_first_oktet, (int)_second_oktet, (int)_third_oktet, (int)_fouth_oktet);

	Address networkAddress(addr.ConvertToNetworkAddress(*this));
	long long int networkAddr = networkAddress.IPToLongInt();
	long long int networkMask = mask.IPToLongInt();
	int countNetworkZero = 0;
	int countAddressZero = 0;
	while (1)
	{
		if (networkAddr & 1)
			break;
		countAddressZero++;
		networkAddr >>= 1;
	}
	while (1)
	{
		if (networkMask & 1)
			break;
		countNetworkZero++;
		networkMask >>= 1;
	}
	if (countAddressZero == countNetworkZero)
		return true;
	return false;
}


bool Mask::operator==(const Mask addr)
{
	if (_first_oktet == addr._first_oktet &&
		_second_oktet == addr._second_oktet &&
		_third_oktet == addr._third_oktet &&
		_fouth_oktet == addr._fouth_oktet)
		return true;
	else
		return false;
}




