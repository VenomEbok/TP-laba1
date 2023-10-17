#pragma once
//добавление и удаление производных объектов абстрактного класса Base(базовый
//класс определяется согласно варианту задания);
//полное сохранение себя в файле;
//полное восстановление себя из файла
#include <iostream>
#include <fstream>
template <class T>
class Keeper
{
	T* object;
	int size;
public:
	Keeper();
	~Keeper();
	Keeper(T& obj);
	void Push();//добавление объекта
	void Pop(int num);//удаление объекта
	void Show();//вывод на экран
	void Edit();//редактирование объекта
	void InFile();//запись в файл
	void FromFile();//чтение из файла

private:

};
