#pragma once
#include "Cargo_carrier.h"
/*��� �������� ����������: ���, ������������, ����� ������������ �����, ��������,
����� ������ ��������.*/

class Plane : public Transport {
public:
	string type;
	string name;
	int volume;
	int size[3];
	int size_ci = 1;
	string* city = new string[size_ci];
	void resize_City();
};