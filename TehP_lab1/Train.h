#pragma once
/*��� ������ ����������: ������������, ��� �������,
������ ������� ����������, ���������� �������, ����� ������������ �����.*/
#include "Cargo_carrier.h"

class Train : public Transport {
public:
	string name;
	int year_of_release;
	int size_ro = 1;
	string* route = new string[size_ro];
	void resize_route();
	int nVan;
	int volume;
};