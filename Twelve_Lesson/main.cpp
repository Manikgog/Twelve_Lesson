#include <iostream>
#include <Windows.h>
#include <string>
#include <cassert>
#include "Mask.h"
#include "Address.h"

void TestEqualOperator()
{
	Address a1("192.168.1.0");
	Address a2("192.168.1.0");
	Address a3("192.168.1.1");
	assert(a1 == a2);
}

void TestLessOperator()
{
	Address a1("192.168.1.0");
	Address a2("192.168.1.1");
	Address a3("192.169.1.1");
	assert(a1 < a2);
	assert(a1 < a3);
}

void TestAmountOfNodes()
{
	Mask m1("255.255.255.0");
	Mask m2("255.255.0.0");
	assert(m1.AmountOfNodes() == 254);
	assert(m2.AmountOfNodes() == 65534);

}

void TestCorrespondenceBetweenAddressAndMask()
{
	Mask m1("255.255.255.0");
	Address a1("192.168.1.100");
	assert(1 == m1.CorrespondenceBetweenAddressAndMask(a1));
	Mask m2("255.255.0.0");
	assert(0 == m2.CorrespondenceBetweenAddressAndMask(a1));
}


void TestInputStreamOperatorMask()
{
	std::cout << "Введите маску 255.255.254.0 -> ";
	Mask m1;
	Mask m2("255.255.254.0");
	std::cin >> m1;
	assert(m1 == m2);
}


void TestInputStreamOperatorAddress()
{
	std::cout << "Введите адрес 192.168.1.100 -> ";
	Address a1;
	Address a2("192.168.1.100");
	std::cin >> a1;
	assert(a1 == a2);
}

void TestIsValidIPMask()
{
	Mask m1("255.256.255.128");
	Mask m2;
	assert(m1 == m2);

}

void TestIsValidIPAddress()
{
	Address a1("255.256.255.128");
	Address a2;
	assert(a1 == a2);

}

void TestConvertToNetworkAddress()
{
	Address a1("192.168.1.100");
	Address a2("192.168.1.0");
	Mask m1("255.255.255.0");
	Address networkAddress(a1.ConvertToNetworkAddress(m1));
	assert(networkAddress == a2);
}

void Test()
{
	TestIsValidIPMask();							// проверка правильности работы метода проверки валидности маски
	TestIsValidIPAddress();							// проверка правильности работы метода проверки валидности адреса
	TestCorrespondenceBetweenAddressAndMask();		// проверка правильности работы метода, проверяющего принадлежит ли передаваемый в метод IP-адрес данной маске сети
	TestEqualOperator();							// проверка правильности работы перегруженного оператора "==" 
	TestLessOperator();								// проверка правильности работы перегруженного оператора "<"
	TestAmountOfNodes();							// проверка правильности работы метода возвращающего количество узлов в сети, соответствующей маске, данного объекта класса
	TestConvertToNetworkAddress();					// проверка правильности работы метода, преобразующего адрес в сетевой адрес, используя маску сети
	TestInputStreamOperatorAddress();				// проверка правильности работы перегруженного оператора ">>" класса Address
	TestInputStreamOperatorMask();					// проверка правильности работы перегруженного оператора ">>" класса Mask
}


int main()
{
	system("chcp 1251");
	system("cls");
	Test();


	return 0;
}

