#pragma once
#include <fstream>
#include "factory.h"
#include "keeper.h"
class Worker:public Factory
{
public:
	Worker();
	~Worker();
	Worker(const Worker& copy);
	friend std::ostream& operator << (ostream& out, Worker& object);
	friend std::istream& operator >> (istream& in, Worker& object);
	Worker& operator =(const Worker& copy);
private:
	std::string phone_number;
	std::string adress;
	std::string full_name;
	std::string post;
	double pay;
};
