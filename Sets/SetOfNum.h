#pragma once
#include <iostream>

class SetOfNum
{
	uint32_t* arr;
	uint32_t sszz;
public:
	SetOfNum(unsigned int size, uint32_t* arr) : arr{ new uint32_t[size] }, sszz { size }
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

	bool has(uint32_t value, uint32_t limit = -1) const;
	
	void show() const
	{
		for (size_t i = 0; i < sszz; i++)
		{
			std::cout << arr[i] << ", ";
		}
	}

};

