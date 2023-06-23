#include "IP_mask.h"
#include "IP_address.h"


IP_mask::IP_mask(std::string mask)
{
	int count = 0;
	int first_dot = 0;
	int second_dot = 0;
	int third_dot = 0;
	int fouth_dot = 0;
	for (size_t i = 0; i <= mask.size(); ++i)
	{
		if (mask[i] == '.' && count == 0)
		{
			first_dot = i;
			count++;
		}
		else if (mask[i] == '.' && count == 1)
		{
			second_dot = i;
			count++;
		}
		else if (mask[i] == '.' && count == 2)
		{
			third_dot = i;
			count++;
		}
		else if (mask[i] == '.' && count == 3)
		{
			fouth_dot = i;
		}
	}
	std::string first_oktet = mask.substr(0, first_dot);
	std::string second_oktet = mask.substr(first_dot+1, second_dot);
	std::string third_oktet = mask.substr(second_dot+1, third_dot);
	std::string fouth_oktet = mask.substr(third_dot+1, fouth_dot);
	_first_oktet = stoi(first_oktet);
	_second_oktet = stoi(second_oktet);
	_third_oktet = stoi(third_oktet);
	_fouth_oktet = stoi(fouth_oktet);
}

IP_mask::IP_mask(int first_oktet, int second_oktet, int third_oktet, int fouth_oktet)
	: _first_oktet(first_oktet), _second_oktet(second_oktet), _third_oktet(third_oktet), _fouth_oktet(fouth_oktet){}

//bool IP_mask::IsRespondAddressToMask(const IP_address& address)
//{
//	return true;
//}

void IP_mask::AmountOfNodes()
{

}

std::istream& operator>>(std::istream& in, std::string mask)
{
	return in;
}