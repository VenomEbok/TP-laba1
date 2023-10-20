#pragma once
#include <fstream>
#include "factory.h"
#include "keeper.h"
class Machine :public Factory
{
public:
	Machine();
	~Machine();
	Machine(Machine& copy);
	void ClearVirtual() override;
	friend std::ostream& operator<< (std::ostream& out, Machine& object);
	friend std::istream& operator>> (std::istream& in, Machine& object);
	Machine& operator =(Machine& copy);
	friend std::ofstream& operator<< (std::ofstream& fout, Machine& object);
	friend std::ifstream& operator>> (std::ifstream& fin, Machine& object);
private:
	std::string brand;
	std::string model;
	std::string state_number;
};
