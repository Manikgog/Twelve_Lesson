#include <iostream>
#include "Address.h"
#include "Mask.h"



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
