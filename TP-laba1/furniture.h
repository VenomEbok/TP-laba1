#pragma once
#include <fstream>
#include "factory.h"
#include "keeper.h"
class Furniture :public Factory
{
public:
	Furniture();
	~Furniture();
	Furniture(Furniture& copy);
	void ClearVirtual() override;
	friend std::ostream& operator<< (std::ostream& out, Furniture& object);
	friend std::istream& operator>> (std::istream& in, Furniture& object);
	Furniture& operator =(Furniture& copy);
	friend std::ofstream& operator<< (std::ofstream& fout, Furniture& object);
	friend std::ifstream& operator>> (std::ifstream& fin, Furniture& object);
private:
	std::string type;
	std::string color;
	std::string material;
	double cost;
	double height;
	double width;
	double deep;
};
