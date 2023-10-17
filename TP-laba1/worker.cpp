#include <iostream>
#include"worker.h"

Worker::Worker()
{
	full_name = "";
	post = "";
	adress = "";
	phone_number = "";
	pay = 0;
}

Worker::Worker(const Worker& copy)
{
	*this = copy;
}

Worker::~Worker()
{

}

Worker& Worker::operator=(const Worker& copy)
{
	this->full_name = copy.full_name;
	this->adress = copy.adress;
	this->pay = copy.pay;
	this->phone_number = copy.phone_number;
	this->post = copy.post;
	return *this;
}

std::istream& operator>>(std::istream& in, Worker& object)
{
	setlocale(LC_ALL, "russian");
	std::cout << "Enter the data\n";
	cout:: << "ФИО: ";
	getchar();
	getline(std::cin, object.full_name);
	std::cout << "Должность: ";
	getchar();
	getline(std::cin, object.post);
	while (1)
	{
		std::cout << "Заработная плата: ";
		int check
		std::cin >> check;
		if (isdigit(chek) && check > 0)
		{
			std::cin.unget(check);
			std::cin >> object.pay;
			break;
		}
		else
			std::cout << "Incorrect value\n";
	}
	std::cout << "Адресс проживания: ";
	getline(std::cin, object.adress);
	std::cout << "Телефон: ";
	getchar();
	getline(std::cin, object.phone_number);
	return in;
}

std::ostream& operator<<(std::ostream& out, Worker& object)
{
	setlocale(LC_ALL, "russian");
	out << "ФИО: " << object.full_name << std::endl;
	out << "Должность: " << object.post << std::endl;
	out << "Адрес проживания: " << object.adress << std::endl;
	out << "Телефон: " << object.phone_number << std::endl;
	out << "Заработная плата: " << object.pay << endl << std::endl;
	return out;
}