#include <iostream>
#include "SetOfNum.h"

int main()
{
	setlocale(LC_ALL, "");
	uint32_t temp[] = { 1, 1, 1, 1, 1, 1, 2, 3 };
	SetOfNum x{ 8, temp };

	std::cout << x << std::endl;

	x += 10;

	std::cout << x << std::endl;

	std::cin >> x;

	SetOfNum y = x + 12;
	++y;

	std::cout << y << std::endl;

	y++;
	std::cout << y << std::endl;


	x += y;
	std::cout << x << std::endl;

	uint32_t temp2[] = { 100,200,400 };
	SetOfNum z{ 3, temp2 };

	SetOfNum zx = z + x;
	std::cout << zx << std::endl;

	zx -= 14;
	std::cout << zx << std::endl;

	{
		SetOfNum yz = zx - 200;
		std::cout << zx << std::endl << yz << std::endl;

		zx = yz;
	}
	
	std::cout << zx << std::endl;

	return 0;
}
  