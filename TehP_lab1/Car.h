#pragma once
#include "Cargo_carrier.h"

/*��� ���������� ����������: ��� �������, �����, ������, � ����� ������
�������������� �������� � ��� ������� ������ ���������� ���������� �����
��������, ����� �����*/

struct d
{
	string city;
	int time;
};

class Car : public Transport {
public:
	int year_of_realize;
	string stamp;
	string model;
	int size_delivery = 1;
	d* delivery = new d[size_delivery];
	int volume;
	void resize_D();
};