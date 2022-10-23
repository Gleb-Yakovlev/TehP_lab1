#include "Plane.h"

void Plane::resize_City() {
    int new_size = size_ci + 1;
    string* new_c = new string[new_size];
    for (int i = 0; i < size_ci; ++i)
        new_c[i] = city[i];
    delete[] city;
    city = new_c;
	size_ci++;
}