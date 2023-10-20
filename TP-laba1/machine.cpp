#include <iostream>
#include"machine.h"
#include <string>
Machine::Machine()
{
	brand = "";
	model = "";
	state_number = "";
}

void Machine::ClearVirtual() {
	std::cin >> *this;
}

Machine::Machine(Machine& copy)
{
	*this = copy;
}

Machine::~Machine()
{

}

Machine& Machine::operator=(Machine& copy)
{
	this->brand = copy.brand;
	this->model = copy.model;
	this->state_number = copy.state_number;
	return *this;
}

std::istream& operator>>(std::istream& in, Machine& object)
{
	setlocale(LC_ALL, "russian");
	std::cout << "Enter the data\n";
	std::cout << "Марка: ";
	getchar();
	std::getline(std::cin, object.brand);
	std::cout << "Модель: ";
	std::getline(std::cin, object.model);
	std::cout << "Государственный номер: ";
	std::getline(std::cin, object.state_number);
	return in;
}

std::ostream& operator<<(std::ostream& out, Machine& object)
{
	setlocale(LC_ALL, "russian");
	out << "Марка: " << object.brand << std::endl;
	out << "Модель: " << object.model << std::endl;
	out << "Государственный номер: " << object.state_number << std::endl;
	return out;
}

std::ofstream& operator<<(std::ofstream& fout, Machine& object)
{
	fout << object.brand << std::endl;
	fout << object.model << std::endl;
	fout << object.state_number << std::endl;
	return fout;
}
std::ifstream& operator>> (std::ifstream& fin, Machine& object)
{
	fin >> object.brand >> object.model >> object.state_number;
	return fin;
}