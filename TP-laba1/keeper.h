#pragma once
//���������� � �������� ����������� �������� ������������ ������ Base(�������
//����� ������������ �������� �������� �������);
//������ ���������� ���� � �����;
//������ �������������� ���� �� �����
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
	void Push();//���������� �������
	void Pop(int num);//�������� �������
	void Show();//����� �� �����
	void Edit();//�������������� �������
	void InFile();//������ � ����
	void FromFile();//������ �� �����

private:

};
