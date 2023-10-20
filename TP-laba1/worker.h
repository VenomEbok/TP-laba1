#pragma once
#include <fstream>
#include "factory.h"
#include "keeper.h"
class Worker:public Factory
{
public:
	Worker();
	~Worker();
	Worker(Worker& copy);
	void ClearVirtual() override;
	friend std::ostream& operator<< (std::ostream& out, Worker& object);
	friend std::istream& operator>> (std::istream& in,  Worker& object);
	Worker& operator =(Worker& copy);
	friend std::ofstream& operator<< (std::ofstream& fout,Worker& object);
	friend std::ifstream& operator>> (std::ifstream& fin, Worker& object);
private:
	std::string phone_number;
	std::string adress;
	std::string full_name;
	std::string post;
	double pay;
};
