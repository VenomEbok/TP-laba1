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
	cout:: << "���: ";
	getchar();
	getline(std::cin, object.full_name);
	std::cout << "���������: ";
	getchar();
	getline(std::cin, object.post);
	while (1)
	{
		std::cout << "���������� �����: ";
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
	std::cout << "������ ����������: ";
	getline(std::cin, object.adress);
	std::cout << "�������: ";
	getchar();
	getline(std::cin, object.phone_number);
	return in;
}

std::ostream& operator<<(std::ostream& out, Worker& object)
{
	setlocale(LC_ALL, "russian");
	out << "���: " << object.full_name << std::endl;
	out << "���������: " << object.post << std::endl;
	out << "����� ����������: " << object.adress << std::endl;
	out << "�������: " << object.phone_number << std::endl;
	out << "���������� �����: " << object.pay << endl << std::endl;
	return out;
}