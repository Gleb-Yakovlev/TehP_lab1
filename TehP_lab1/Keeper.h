#pragma once
#include "Car.h"
#include "Plane.h"
#include "Train.h"

class Keeper {
public:

	int Car_size = 1, Plane_size = 1, Train_size = 1;
	

	Car* c = new Car[Car_size];
	Plane* p = new Plane[Plane_size];
	Train* t = new Train[Train_size];

	void resize_c();
	void resize_p();
	void resize_t();

	void write_al();
	int Number; // номер 

	void add(int, string, string, int, d*, int);//car
	void add(string, string, int, int[], int, string*);//plane
	void add(string, int, int, string*, int, int);//train

	void delette(int);
	void save();
	void read();
	void change_data(int);

	void city_search(string);
};