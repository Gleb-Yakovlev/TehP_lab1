#include "Car.h"
#include "Plane.h"
#include "Train.h"
#include "Keeper.h"

#include <iostream>
using namespace std;

int main() {

	Keeper k;

	k.read();
	while (1) {
		system("cls");
		cout << "CARGO_CARRIER" << endl;

		k.write_al();
		
		cout << "---------------------------------" << endl;
		cout << "Select an action:" << endl
			<< "1)Add" << endl
			<< "2)Delete" << endl
			<< "3)Change" << endl
			<< "4)City Search" << endl
			<< "0)Safe and close" << endl;
		int action = safe_input_int();


		switch (action) {


		case 1: {
			cout << "Choose a transport:" << endl
				<< "Car" << endl
				<< "Plane" << endl
				<< "Train" << endl;
			int transp = 0;
			cin >> transp;
			switch (transp) {

			case 1: {
				int year, size_c, volume;
				string stamp, model;
				cout << "Enter the year of release" << endl;
				year = safe_input_int();

				cout << "Enter the stamp" << endl;
				stamp = safe_input_string();

				cout << "Enter the model" << endl;
				model = safe_input_string();

				size_c = 1;
				d* delivery = new d[size_c];
				cout << "Enter the cities(don't use a space) and delivery time(in hours), if the input is finished, enter 0" << endl;
				while (1) {
					cout << "City or 0" << endl;
					string s = safe_input_string();
					if (s == "0") break;
					delivery[size_c - 1].city = s;
					cout << "Time:" << endl;
					delivery[size_c - 1].time = safe_input_int();
					int new_size = size_c + 1;
					d* new_d = new d[new_size];
					for (int i = 0; i < size_c; ++i)
						new_d[i] = delivery[i];
					delete[] delivery;
					delivery = new_d;
					size_c++;
				}

				size_c--;
				cout << "Enter the volume" << endl;
				volume = safe_input_int();

				k.add(year, stamp, model, size_c, delivery, volume);
				break;
			}



			case 2: {
				string type, name;
				int volume, size_city;
				int size[3];
				cout << "Enter the type" << endl;
				type = safe_input_string();

				cout << "Enter the name" << endl;
				name = safe_input_string();

				cout << "Enter the volume" << endl;
				volume = safe_input_int();

				cout << "Enter the size" << endl;
				cout << "Enter the length" << endl;
				size[0] = safe_input_int();
				cout << "Enter the width" << endl;
				size[1] = safe_input_int();
				cout << "Enter the height" << endl;
				size[2] = safe_input_int();

				size_city = 1;
				string* city = new string[size_city];
				while (1) {

					cout << "Enter the cities, if the input is finished, enter 0" << endl;
					string s = safe_input_string();
					if (s == "0") break;
					city[size_city - 1] = s;

					int new_size = size_city + 1;
					string* new_c = new string[new_size];
					for (int i = 0; i < size_city; ++i)
						new_c[i] = city[i];
					delete[] city;
					city = new_c;
					size_city++;

				}
				size_city--;
				k.add(type, name, volume, size, size_city, city);
				break;
			}

			case 3: {
				string name;
				int year, size_r, nVan, volume;

				cout << "Enter the name" << endl;
				name = safe_input_string();

				cout << "Enter the year of release" << endl;
				year = safe_input_int();

				size_r = 1;
				string* route = new string[size_r];
				while (1) {
					cout << "Enter the cities, if the input is finished, enter 0" << endl;
					string s = safe_input_string();
					if (s == "0") break;
					route[size_r - 1] = s;

					int new_size = size_r + 1;
					string* new_r = new string[new_size];
					for (int i = 0; i < size_r; ++i)
						new_r[i] = route[i];
					delete[] route;
					route = new_r;
					size_r++;
				}
				size_r--;

				cout << "Enter the number of wagons" << endl;
				nVan = safe_input_int();

				cout << "Enter the volume" << endl;
				volume = safe_input_int();
				k.add(name, year, size_r, route, nVan, volume);
				break;
			}

			default: {
				system("cls");
				cout << "ERROR!!" << endl;
				break;
			}
			}
			break;
		}


		case 2: {
			cout << "Enter the number: ";
			int n;
			n = safe_input_int();

			k.delette(n);
			break;
		}


		case 3: {
			cout << "Enter the number: ";
			int n;
			n = safe_input_int();
			k.change_data(n);
			break;
		}

		case 4: {
			cout << "Enter the city: ";
			string s = safe_input_string();
			k.city_search(s);
			break;
		}

		case 0: {
			k.save();
			return 0;
		}


		default: {
			system("cls");
			cout << "ERROR!!" << endl;
			break;
		}


		}

		
	}
}