#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template<typename T, typename F>
void iter(T* arr, int len, F f)
{
	for (int i = 0; i < len; i++)
		f(arr[i]);
}

template<typename T>
void printElement(const T& element)
{
	std::cout << element << std::endl;
}

template<typename T>
void increment(T& element)
{
	element++;
}

template<>
void increment<std::string>(std::string& s)
{
	s += "A";
}

#endif
