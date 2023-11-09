#include <iostream>
#include "SetOfNum.h"

int main()
{

	uint32_t temp[] = { 1, 1, 1, 1, 1, 1, 2, 3 };
	SetOfNum x{ 8, temp };


	x.show();

	return 0;
}
  