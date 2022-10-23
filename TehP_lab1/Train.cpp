#include "Train.h"

void Train::resize_route() {
    int new_size = size_ro + 1;
    string* new_r = new string[new_size];
    for (int i = 0; i < size_ro; ++i)
        new_r[i] = route[i];
    delete[] route;
    route = new_r;
	size_ro++;
}