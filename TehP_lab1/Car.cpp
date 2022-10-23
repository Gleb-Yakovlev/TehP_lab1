#include "Car.h"

void Car::resize_D() {
	int new_size = size_delivery + 1;
	d* new_d = new d[new_size];
    for (int i = 0; i < size_delivery; ++i)
        new_d[i] = delivery[i];
    delete[] delivery;
    delivery = new_d;
	size_delivery++;
}