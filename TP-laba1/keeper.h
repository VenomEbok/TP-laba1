#pragma once
//добавление и удаление производных объектов абстрактного класса Base(базовый
//класс определяется согласно варианту задания);
//полное сохранение себя в файле;
//полное восстановление себя из файла
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
template <class T>
class Keeper
{
public:
	Keeper();
	~Keeper();
	Keeper(T& obj);
	void Push();//добавление объекта
	void Pop();//удаление объекта
	void Show();//вывод на экран
	void Edit(const int& change);//редактирование объекта
	void InFile(std::string& file);//запись в файл
	void FromFile(std::string& file);//чтение из файла

private:
	T* object;
	int size;
};

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
void Keeper<T>::Pop()
{
	try
	{
		if (size == 0) {
			std::exception empty("Object is empty");
			throw empty;
		}
		int num;
		std::cout << "Chose which element to delete: ";
		std::cin >> num;
		if (num < 0 || num >= size)
		{
			std::exception wrong("Wrong value");
			throw wrong;
		}

		T* temp = new T[size - 1];
		for (int i = 0, j = 0; i < num && size>1 && j < size - 1; ++i, ++j)
			temp[j] = object[i];
		for (int i = num+1,j=num; i < size && size>1 && j<size-1; ++i)
			temp[j] = object[i];
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
			std::cout << object[i] << std::endl;
	}
	catch (std::exception& error)
	{
		std::cout << error.what() << std::endl;
	}
}

template<class T>
void Keeper<T>::Edit(const int& change)
{
	try {
		if (size == 0) {
			std::exception empty("Object is empty");
			throw empty;
		}
		if (change < 0 || change >= size) {
			std::exception wrong("Wrong value");
			throw wrong;
		}
		std::cin >> object[change];
	}
	catch (std::exception& error) {
		std::cout << error.what() << std::endl;
	}
}

template<class T>
void Keeper<T>::InFile(std::string& file)
{
	std::ofstream fout(file, std::ios::out);
	try {
		if (size == 0) {
			std::exception empty("Object is empty");
			throw empty;
		}
		fout << size << std::endl;
		for (int i = 0; i < size; ++i)
		{
			fout << object[i];
		}
		fout.close();
		std::cout << "Recording successful" << std::endl;
	}
	catch (std::exception& error) {
		std::cout << error.what() << std::endl;
		fout.close();
	}
}
template<class T>
void Keeper<T>::FromFile(std::string& file)
{
	std::ifstream fin(file, std::ios::in);
	try {
		if (!fin.is_open()) {
			std::exception error("File didn't open");
			throw error;
		}
		if (fin.peek() == EOF) {
			std::exception empty("File is empty");
			throw empty;
		}
		delete[] object;
		fin >> size;
		object = new T[size];
		for (int i = 0; i < size; ++i)
		{
			fin >> object[i];
		}
		fin.close();
		std::cout << "Reading successful" << std::endl;
	}
	catch (std::exception& error)
	{
		std::cout << error.what() << std::endl;
		fin.close();
	}
}