#pragma once
#include "keeper.h"
#include "factory.h"
#include "furniture.h"
#include "machine.h"
#include "worker.h"
#include <iostream>
std::string menu = "1-Add object\n2-Delete object\n3-Display object\n4-Change data\n5-Save in file\n6-Read from file\n7-Return to previos menu\n";
template<typename T>
void Menu(T& object, std::string file)
{
	int choose, i;
	bool flag = true;
	setlocale(LC_ALL, "russian");
	while (flag)
	{
		system("cls");
		std::cout << menu;
		std::cin >> choose;
		system("cls");
		switch (choose) {
		case 1:
			object.Push();
			system("pause");
			break;
		case 2:
			object.Show();
			object.Pop();
			system("pause");
			break;
		case 3:
			object.Show();
			system("pause");
			break;
		case 4:
			object.Show();
			std::cout << "Chose which element to change: ";
			std::cin >> i;
			object.Edit(i);
			system("pause");
			break;
		case 5:
			object.InFile(file);
			system("pause");
			break;
		case 6:
			object.FromFile(file);
			system("pause");
			break;
		case 7:
			flag = false;
			std::cout << "Returning\n";
			system("pause");
			break;
		default:
			std::cout << "Wrong input\n";
			system("pause");
			break;
		}
	}
}