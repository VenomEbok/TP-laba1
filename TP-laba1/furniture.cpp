#include <iostream>
#include"furniture.h"
#include <string>
Furniture::Furniture()
{
	std::cout << "Вызван конструктор по умолчанию Furniture\n";
	type = "";
	color = "";
	material = "";
	cost = 0;
	height = 0;
	width = 0;
	deep = 0;
}

void Furniture::ClearVirtual() {
	std::cin >> *this;
}

Furniture::Furniture(Furniture& copy)
{
	std::cout << "Вызван конструктор копирования Furniture\n";
	*this = copy;
}

Furniture::~Furniture()
{
	std::cout << "Вызван деструктор Furniture\n";
}

Furniture& Furniture::operator=(Furniture& copy)
{
	this->type = copy.type;
	this->height = copy.height;
	this->width = copy.width;
	this->deep = copy.deep;
	this->color = copy.color;
	this->material=copy.material;
	this->cost = copy.cost;
	return *this;
}

std::istream& operator>>(std::istream& in, Furniture& object)
{
	setlocale(LC_ALL, "russian");
	std::cout << "Enter the data\n";
	std::cout << "Тип мебели: ";
	getchar();
	std::getline(std::cin, object.type);
	int check;
	while (1)
	{
		std::cout << "Высота: ";

		if (std::cin >> check)
		{
			if (check > 0)
			{
				object.height = check;
				getchar();
				break;
			}
		}
		else
		{
			std::cout << "Incorrect value\n";
			std::cin.clear();
			std::cin.ignore(1024, '\n');
		}
	}
	while (1)
	{
		std::cout << "Ширина: ";

		if (std::cin >> check)
		{
			if (check > 0)
			{
				object.width = check;
				getchar();
				break;
			}
		}
		else
		{
			std::cout << "Incorrect value\n";
			std::cin.clear();
			std::cin.ignore(1024, '\n');
		}
	}
	while (1)
	{
		std::cout << "Глубина: ";

		if (std::cin >> check)
		{
			if (check > 0)
			{
				object.deep = check;
				getchar();
				break;
			}
		}
		else
		{
			std::cout << "Incorrect value\n";
			std::cin.clear();
			std::cin.ignore(1024, '\n');
		}
	}
	std::cout << "Цвет: ";
	std::getline(std::cin, object.color);
	std::cout << "Материал: ";
	std::getline(std::cin, object.material);
	while (1)
	{
		std::cout << "Стоимость: ";

		if (std::cin >> check)
		{
			if (check > 0)
			{
				object.cost=check;
				getchar();
				break;
			}
		}
		else
		{
			std::cout << "Incorrect value\n";
			std::cin.clear();
			std::cin.ignore(1024, '\n');
		}
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, Furniture& object)
{
	setlocale(LC_ALL, "russian");
	out << "Тип мебели: " << object.type << std::endl;
	out << "Высота: " << object.height << std::endl;
	out << "Ширина: " << object.width << std::endl;
	out << "Глубина: " << object.deep << std::endl;
	out << "Цвет: " << object.color << std::endl;
	out << "Материал: " << object.material << std::endl;
	out << "Стоимость: " << object.cost << std::endl << std::endl;
	return out;
}

std::ofstream& operator<<(std::ofstream& fout, Furniture& object)
{
	fout << object.type << std::endl;
	fout << object.height << std::endl;
	fout << object.width << std::endl;
	fout << object.deep << std::endl;
	fout << object.color << std::endl;
	fout << object.material << std::endl;
	fout << object.cost << std::endl;
	return fout;
}
std::ifstream& operator>> (std::ifstream& fin, Furniture& object)
{
	fin>> object.type>>object.height>>object.width >> object.deep >> object.color >> object.material >> object.cost;
	return fin;
}