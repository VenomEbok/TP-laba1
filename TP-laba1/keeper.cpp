#include <iostream>
#include <fstream>
#include <exception>
#include "keeper.h"
template <class T>
Keeper<T>::Keeper()
{
	object = NULL;
	size = 0;
}

template <class T>
Keeper<T>::~Keeper()
{
	delete[]object;
}
template <class T>
Keeper<T>::Keeper(T& obj)
{
	object = obj;
}
template <class T>
void Keeper<T>::Push()
{
	T* temp = new T[size + 1];
	for (int i = 0; i < size; ++i)
		temp[i] = object[i];
	delete[] object;
	object = temp;
	std::cin >> object[size];
	++size;
	std::cout << "\nAdd new object\n";
}
template <class T>
void Keeper<T>::Pop(int num)
{
	try 
	{
		if (size == 0) {
			std::exception empty("Object is empty");
			throw empty;
		}
		if (num < 0 || num >= size)
		{
			std::exception wrong("Wrong value");
			throw wrong;
		}
		T* temp = new T[size - 1];
		for (int i = num; i < size; ++i)
			object[i] = object[i + 1];
		for (int i = 0; i < size - 1; ++i)
			temp[i] = object[i];
		delete[] object;
		object = temp;
		--size;
		std::cout << "\nObject deleted\n";
	}
	catch (std::exception& error)
	{
		std::cout << error.what() << std::endl;
	}
}
template<class T>
void Keeper<T>::Show()
{
	try
	{
		if (size == 0)
		{
			std::exception empty("Object is empty");
			throw empty;
		}
		for (int i = 0; i < size; ++i)
			std::cout << object[i] << endl;
	}
	catch (std::exception& error)
	{
		std::cout << error.what() << std::endl;
	}
}