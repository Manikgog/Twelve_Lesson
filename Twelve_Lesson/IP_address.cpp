#include "IP_address.h"


IP_address::IP_address(std::string address)
{

}

IP_address::IP_address(int first_oktet, int second_oktet, int third_oktet, int fouth_oktet)
	: _first_oktet(first_oktet), _second_oktet(second_oktet), _third_oktet(third_oktet), _fouth_oktet(fouth_oktet) {}

bool IP_address::IsValidIP(std::string)
{
	return true;
}

bool IP_address::IsValidIP(int first_oktet, int second_oktet, int third_oktet, int fouth_oktet)
{
	return true;
}

//IP_address IP_address::FromMaskToAddress(const IP_mask& mask)
//{
//
//}

bool IP_address::operator==(const IP_address& address)
{
	if (_first_oktet == address._first_oktet &&
		_second_oktet == address._second_oktet &&
		_third_oktet == address._third_oktet &&
		_fouth_oktet == address._fouth_oktet)
		return true;
	else
		return false;
}

bool IP_address::operator<(const IP_address& address)
{
	
	return true;
}
