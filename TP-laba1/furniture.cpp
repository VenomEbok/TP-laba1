#include <iostream>
#include"furniture.h"
#include <string>
Furniture::Furniture()
{
	std::cout << "������ ����������� �� ��������� Furniture\n";
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
	std::cout << "������ ����������� ����������� Furniture\n";
	*this = copy;
}

Furniture::~Furniture()
{
	std::cout << "������ ���������� Furniture\n";
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
	std::cout << "��� ������: ";
	getchar();
	std::getline(std::cin, object.type);
	int check;
	while (1)
	{
		std::cout << "������: ";

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
		std::cout << "������: ";

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
		std::cout << "�������: ";

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
	std::cout << "����: ";
	std::getline(std::cin, object.color);
	std::cout << "��������: ";
	std::getline(std::cin, object.material);
	while (1)
	{
		std::cout << "���������: ";

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
	out << "��� ������: " << object.type << std::endl;
	out << "������: " << object.height << std::endl;
	out << "������: " << object.width << std::endl;
	out << "�������: " << object.deep << std::endl;
	out << "����: " << object.color << std::endl;
	out << "��������: " << object.material << std::endl;
	out << "���������: " << object.cost << std::endl << std::endl;
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