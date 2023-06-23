#ifndef _IP_MASK_H_
#define _IP_MASK_H_

#include <string>
#include <iostream>
#include "IP_address.h"

class IP_mask
{
private:
	unsigned char _first_oktet;
	unsigned char _second_oktet;
	unsigned char _third_oktet;
	unsigned char _fouth_oktet;

public:
	IP_mask(std::string mask);
	IP_mask(int first_oktet, int second_oktet, int third_oktet, int fouth_oktet);
	//bool IsRespondAddressToMask(const IP_address& address);
	void AmountOfNodes();
	friend std::istream& operator>>(std::istream& in, std::string mask);


};

#endif