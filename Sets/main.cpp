#include <iostream>
#include "SetOfNum.h"

int main()
{

	uint32_t temp[] = { 1, 1, 1, 1, 1, 1, 2, 3 };
	SetOfNum x{ 8, temp };

	x.show();
	std::cout << std::endl;

	x += 10;

	x.show();
	std::cout << std::endl;

	SetOfNum y = x + 12;
	++y;

	y.show();
	std::cout << std::endl;

	y++;
	y.show();
	std::cout << std::endl;


	x += y;
	x.show();
	std::cout << std::endl;


	uint32_t temp2[] = { 100,200,400 };
	SetOfNum z{ 3, temp2 };

	SetOfNum zx = z + x;
	zx.show();
	std::cout << std::endl;

	zx -= 14;
	zx.show();
	std::cout << std::endl;

	return 0;
}
  