#include "iter.hpp"

int main()
{
	int numbers[] = {1, 2, 3, 4, 5};
	const int constNumbers[] = {10, 20, 30};
	float floats[] = {1.1, 2.1, 3.1, 4.1, 5.1};
	const float constFloats[] = {10.1, 20.1, 30.1};
	std::string strings[] = {"a", "b", "c"};
	const std::string constStrings[] = {"X", "Y", "Z"};

	std::cout << "--- Non-const arrays ---" << std::endl;
	iter(numbers, 5, printElement<int>);
	iter(numbers, 5, increment<int>);
	iter(numbers, 5, printElement<int>);
	iter(floats, 5, printElement<float>);
	iter(floats, 5, increment<float>);
	iter(floats, 5, printElement<float>);

	std::cout << "--- Const elements (only print allowed) ---" << std::endl;
	iter(constNumbers, 3, printElement<int>);   
	//iter(constNumbers, 3, increment<int>); //compile error
	iter(constFloats, 3, printElement<float>);   
	//iter(constNumbers, 3, increment<int>); //compile error

	std::cout << "--- Strings ---" << std::endl;
	iter(strings, 3, printElement<std::string>);
	iter(strings, 3, increment<std::string>);
	iter(strings, 3, printElement<std::string>);

	std::cout << "--- Const strings ---" << std::endl;
	iter(constStrings, 3, printElement<std::string>);
	//iter(constStrings, 3, increment<std::string>); //compile error
	return 0;
}
