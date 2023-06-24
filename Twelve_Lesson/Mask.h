#ifndef _MASK_H_
#define _MASK_H_

#include <string>

class Address;

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


#endif // !_MASK_H_

