#ifndef _MASK_H_
#define _MASK_H_

#include <string>
#include <bitset>

class Address;

class Mask
{
private:
	unsigned char _first_oktet;
	unsigned char _second_oktet;
	unsigned char _third_oktet;
	unsigned char _fouth_oktet;
	Mask StringToMask(std::string str);
	int* StringToArr(std::string str);
	bool IsValidIP(int first, int second, int third, int fouth);
public:
	Mask();
	Mask(std::string mask);
	Mask(int first_oktet, int second_oktet, int third_oktet, int fouth_oktet);
	unsigned int AmountOfNodes();									// метод-член, возвращающий количество узлов в сети, соответствующей маске, данного объекта класса
	long long int IPToLongInt();
	bool CorrespondenceBetweenAddressAndMask(Address addr);			// метод-член, проверяющий принадлежит ли передаваемый в метод IP-адрес данной маске сети
	bool operator==(const Mask addr);

	friend std::istream& operator>>(std::istream& in, Mask& mask);
};


#endif // !_MASK_H_

