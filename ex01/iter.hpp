#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template<typename T>
void iter(T* arr, int len, void (*f)(T&))
{
	for (int i = 0; i < len; i++)
		(f)(arr[i]);
}

template<typename T>
void printElement(T& element)
{
	std::cout << element << std::endl;
}

void increment(int& element)
{
	element++;
}

void increment(float& element)
{
	element += 1.1;
}

void appendCharA(std::string &s)
{
	s += "A";
}

#endif
