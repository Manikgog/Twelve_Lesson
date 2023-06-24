#include <iostream>
#include <string>
#include <bitset>
#include "Mask.h"
#include "Address.h"


int main()
{
	//Mask m1("255.255.254.0");
	//std::cout << m1.AmountOfNodes();
	
	Address a1("192.168.1.0");
	Address a2("192.168.1.1");

	std::cout << (a1 < a2) << std::endl;


	return 0;
}

