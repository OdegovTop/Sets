#pragma once
#include <iostream>

class SetOfNum
{
private:
	uint32_t* arr;
	uint32_t sszz;
public:
	SetOfNum(unsigned int size, uint32_t* arr);

	SetOfNum() : SetOfNum(0, nullptr) {}

	SetOfNum(const SetOfNum& obj) : arr{ new uint32_t[obj.sszz] }, sszz{ obj.sszz }
	{
		for (uint32_t i = 0; i < obj.sszz; i++)
		{
			arr[i] = obj.arr[i];
		}
	}

	~SetOfNum()
	{
		delete[] arr;
	}

	uint32_t has(uint32_t value, uint32_t limit = -1) const;

	void show() const
	{
		for (size_t i = 0; i < sszz; i++)
		{
			std::cout << arr[i] << " ";
		}
	}

	SetOfNum& operator+=(const SetOfNum& set);
	SetOfNum& operator+(const SetOfNum& set);

	SetOfNum& increment();
	SetOfNum& operator++();
	SetOfNum& operator++(int);

	SetOfNum& operator-=(uint32_t value);

	SetOfNum& operator+=(uint32_t value);
	friend const SetOfNum operator+(const SetOfNum& set, uint32_t value);
	friend const SetOfNum operator+(uint32_t value, const SetOfNum& set);

};

