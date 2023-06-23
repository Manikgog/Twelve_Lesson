#ifndef _IP_ADDRESS_H_
#define _IP_ADDRESS_H_

#include <string>
#include "IP_mask.h"

class IP_address
{
private:
	unsigned char _first_oktet;
	unsigned char _second_oktet;
	unsigned char _third_oktet;
	unsigned char _fouth_oktet;

public:
	IP_address(std::string address);
	IP_address(int first_oktet, int second_oktet, int third_oktet, int fouth_oktet);
	bool IsValidIP(std::string);
	bool IsValidIP(int first_oktet, int second_oktet, int third_oktet, int fouth_oktet);
	//IP_address FromMaskToAddress(const IP_mask& mask);
	bool operator==(const IP_address& address);
	bool operator<(const IP_address& address);
	friend std::istream& operator>>(std::istream& in, std::string address);



};


#endif // !_IP_ADDRESS_H_

