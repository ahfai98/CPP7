#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template<typename T>
class Array
{
	public:
		Array():_array(NULL), _size(0)
		{
		}
		Array(unsigned int n):_size(n)
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = T();
		}
		~Array()
		{
			delete[] _array;
		}
		Array(const Array& src): _size(src._size)
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = src._array[i];
		}
		Array &operator=(const Array& src)
		{
			if (this != &src)
			{
				delete[] _array;
				_size = src._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = src._array[i];
			}
			return (*this);
		}
		T &operator[](unsigned int i)
		{
			if (i >= _size)
				throw OutofBoundsException();
			return _array[i];
		}
		unsigned int size() const
		{
			return (_size);
		}
		void	printElements() const
		{
			unsigned int length = (_size > 10) ? 10: _size;
			for (unsigned int i = 0; i < length; i++)
				std::cout << _array[i] << ", ";
			std::cout << std::endl;
		}
		class OutofBoundsException: public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error :Index is out of bounds.");
				}
		};
	private:
		T* _array;
		unsigned int _size;
};

#endif