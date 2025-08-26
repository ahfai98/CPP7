#include "iter.hpp"

int main()
{
	int numbers[] = {1, 2, 3, 4, 5};
	int size = 5;
	float floats[] = {1.1, 2.1, 3.1, 4.1, 5.1};
	std::string strings[] = {"a", "b" , "c" , "d" , "e"};
	iter(numbers, size, printElement);
	iter(floats, size, printElement);
	iter(strings, size, printElement);
	std::cout << "----Increment----" << std::endl;
	iter(numbers, size, increment);
	iter(numbers, size, printElement);
	iter(floats, size, increment);
	iter(floats, size, printElement);
	iter(floats, size, increment);
	iter(floats, size, printElement);
	std::cout << "----Append Char A----" << std::endl;
	iter(strings, size, appendCharA);
	iter(strings, size, printElement);
	iter(strings, size, appendCharA);
	iter(strings, size, printElement);
	return (0);
}
