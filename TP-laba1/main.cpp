//Класс Фабрика хранит данные о мебели, работниках и машинах.Для мебели
//определено : тип мебели, габариты(высота, ширина, глубина), цвет, материал,
//стоимость.Для работника определено : ФИО, должность, заработная плата,
//адрес проживания, телефон.Для машины определено : марка, модель,
//гос.номер.
#include <iostream>
#include "keeper.h"
#include "factory.h"
#include "furniture.h"
#include "machine.h"
#include "worker.h"
#include "menu.h"
std::string main_menu = "1-Furniture\n2-Worker\n3-Machine\n4-Exit from program\n";
int main()
{
	setlocale(LC_ALL, "russian");
	Keeper<Machine> machine;
	Keeper<Furniture> furniture;
	Keeper<Worker> worker;
	int button;
	bool flag = true;
	while (flag)
	{
		system("cls");
		std::cout << main_menu;
		std::cin >> button;
		switch (button) {
		case 1:
			Menu(furniture, "Furniture.txt");
			break;
			break;
		case 2:
			Menu(worker, "Worker.txt");
			break;
		case 3:
			Menu(machine, "Machine.txt");
			break;
		case 4:
			flag = false;
			std::cout << "Work is over\n";
			break;
		default:
			std::cout << "Wrong value\n";
			system("pause");
			break;
		}
	}
	return 0;
}