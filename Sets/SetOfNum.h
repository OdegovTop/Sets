#pragma once
#include <iostream>

using namespace std;

class SetOfNum
{
private:
	uint32_t* arr;
	uint32_t sszz;

	void clear()
	{
		delete[] arr;
		arr = nullptr;
	}

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
		clear();
	}

	uint32_t has(uint32_t value, uint32_t limit = -1) const;

	SetOfNum& operator+=(const SetOfNum& set);
	const SetOfNum operator+(const SetOfNum& set) const;

	SetOfNum& operator++();
	const SetOfNum operator++(int);

	SetOfNum& operator--();
	const SetOfNum operator--(int);

	SetOfNum& operator-=(uint32_t value);
	const SetOfNum operator-(uint32_t value) const;

	SetOfNum& operator+=(uint32_t value);
	friend const SetOfNum operator+(const SetOfNum& set, uint32_t value);
	friend const SetOfNum operator+(uint32_t value, const SetOfNum& set);

	friend ostream& operator<<(ostream& out, const SetOfNum& set);
	friend istream& operator>>(istream& input, SetOfNum& set);

	SetOfNum& operator= (const SetOfNum& set)
	{
		if (this == &set)
		{
			return *this;
		}
		clear();
		arr = new uint32_t[set.sszz];
		for (uint32_t i = 0; i < set.sszz; i++)
		{
			arr[i] = set.arr[i];
		}
		sszz = set.sszz;
		return *this;
	}
};

