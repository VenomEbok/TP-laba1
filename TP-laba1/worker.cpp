#include <iostream>
#include"worker.h"
#include <string>
Worker::Worker()
{
	std::cout << "������ ����������� �� ��������� Worker\n";
	full_name = "";
	post = "";
	adress = "";
	phone_number = "";
	pay = 0;
}

void Worker::ClearVirtual() {
	std::cin >> *this;
}

Worker::Worker(Worker& copy)
{
	std::cout << "������ ����������� ����������� Worker\n";
	*this = copy;
}

Worker::~Worker()
{
	std::cout << "������ ���������� Worker\n";
}

Worker& Worker::operator=(Worker& copy)
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
	std::cout << "���: ";
	getchar();
	std::getline(std::cin, object.full_name);
	std::cout << "���������: ";
	std::getline(std::cin, object.post);
	int check;
	while (1)
	{
		std::cout << "���������� �����: ";

		if (std::cin >> check)
		{
			if (check > 0)
			{
				object.pay=check;
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
	std::cout << "������ ����������: ";
	std::getline(std::cin, object.adress);
	std::cout << "�������: ";
	std::getline(std::cin, object.phone_number);
	return in;
}

std::ostream& operator<<(std::ostream& out, Worker& object)
{
	setlocale(LC_ALL, "russian");
	out << "���: " << object.full_name << std::endl;
	out << "���������: " << object.post << std::endl;
	out << "����� ����������: " << object.adress << std::endl;
	out << "�������: " << object.phone_number << std::endl;
	out << "���������� �����: " << object.pay << std::endl << std::endl;
	return out;
}

std::ofstream& operator<<(std::ofstream& fout, Worker& object)
{
	fout << object.full_name << std::endl;
	fout << object.post << std::endl;
	fout << object.adress << std::endl;
	fout << object.phone_number << std::endl;
	fout << object.pay << std::endl;
	return fout;
}
std::ifstream& operator>> (std::ifstream& fin, Worker& object)
{
	std::string first_name, second_name, surname, street;
	fin >> second_name >> first_name >> surname >> object.post>>object.adress;
	std::getline(fin, street);
	object.adress = object.adress + street;
	fin>> object.phone_number >> object.pay;
	object.full_name = second_name + " " + first_name + " " + surname;
	return fin;
}