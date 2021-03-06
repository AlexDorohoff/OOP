// flipbyte.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

uint8_t FlipByte(const uint8_t number)
{
	uint8_t outputByte = 0;
	uint8_t inputByte = number;
	for (int i = 0; i < 8; i++) //пока байт не кончился
	{
		outputByte = outputByte <<= 1; //реверсивный байт двигаем влево
		outputByte = inputByte & 1 | outputByte; //сохраянем если в исходном байте бит = 1, или записываем 0
		inputByte = inputByte >>= 1; //исходный байт двигаем вправо
	}
	return outputByte;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid argument count\n"
				  << "Usage: flipbyte.exe <decimal>\n";
		return 1;
	}
	int byte;

	try
	{
		byte = std::stoi(argv[1]);

		if (byte < 0 || byte > 255)
		{
			std::cout << "Non decimal\n";
			return 1;
		}
	}
	catch (const std::exception& err)
	{
		std::cout << err.what() << "\n";
		return 1;
	}

	std::cout << static_cast<int>(FlipByte(byte)) << "\n";
	return 0;
}
