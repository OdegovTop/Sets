#include "SetOfNum.h"

SetOfNum::SetOfNum(unsigned int size, uint32_t* arr) : arr{ new uint32_t[size] }, sszz{ size }
{
	int index = 0;

	for (size_t i = 0; i < sszz; i++)
	{
		if (!has(arr[i], index))
		{
			this->arr[index] = arr[i];
			index++;
		}
	}

	uint32_t* temp = new uint32_t[index];

	for (size_t i = 0; i < index; i++)
	{
		temp[i] = this->arr[i];
	}

	delete[] this->arr;
	this->arr = temp;

	sszz = index;
}

bool SetOfNum::has(uint32_t value, uint32_t limit) const
{
	uint32_t c_sszz = limit == -1 ? this->sszz : limit;

	for (size_t i = 0; i < c_sszz; i++)
	{
		if (arr[i] == value)
		{
			return true;
		}
	}

	return false;
}

SetOfNum& SetOfNum::operator+=(uint32_t value)
{
	if (has(value))
	{
		return *this;
	}

	uint32_t* temp = new uint32_t[sszz + 1];
	for (size_t i = 0; i < sszz; i++)
	{
		temp[i] = arr[i];
	}
	temp[sszz] = value;

	delete[] arr;
	arr = temp;

	sszz++;
	return *this;
}

SetOfNum& SetOfNum::operator+=(const SetOfNum& set)
{
	for (size_t i = 0; i < set.sszz; i++)
	{
		if (!this->has(set.arr[i]))
		{
			*this += set.arr[i];
		}
	}
	return *this;
}

SetOfNum& SetOfNum::operator++()
{
	return this->increment();
}

SetOfNum& SetOfNum::operator++(int)
{
	return this->increment();
}

SetOfNum& SetOfNum::increment()
{
	for (size_t i = 0; i < sszz; i++)
	{
		arr[i]++;
	}
	return *this;
}

const SetOfNum SetOfNum::add(const SetOfNum& set, uint32_t value)
{

	if (!set.has(value))
	{
		SetOfNum temp(set);
		temp += value;
		return temp;
	}

	return set;
}

const SetOfNum operator+(const SetOfNum& set, uint32_t value)
{
	return SetOfNum::add(set, value);
}

const SetOfNum operator+(uint32_t value, const SetOfNum& set)
{
	return SetOfNum::add(set, value);
}




