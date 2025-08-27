#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    std::cout << "==Test for Const==" << std::endl;
    std::cout << "--- Non-const array, non-const elements ---" << std::endl;
    Array<int> a1(5);
    for (unsigned int i = 0; i < a1.size(); i++)
        a1[i] = i * 10;  // write allowed
    for (unsigned int i = 0; i < a1.size(); i++)
        std::cout << a1[i] << ", ";  // read
    std::cout << std::endl;

    std::cout << "--- Const array, non-const elements ---" << std::endl;
    const Array<int> a2 = a1;
    for (unsigned int i = 0; i < a2.size(); i++)
        std::cout << a2[i] << ", ";  // read only
    std::cout << std::endl;
    //a2[0] = 99; // ❌ compile error: a2 is const

    return 0;
}
