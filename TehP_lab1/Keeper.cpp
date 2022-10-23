#include"Keeper.h"

void Keeper::resize_c() {
	int new_size = Car_size + 1;
	Car* new_c = new Car[new_size];
	for (int i = 0; i < Car_size; ++i)
		new_c[i] = c[i];
	delete[] c;
	c = new_c;
	Car_size++;
	return;
}

void Keeper::resize_p() {
	int new_size = Plane_size + 1;
	Plane* new_p = new Plane[new_size];
	for (int i = 0; i < Plane_size; ++i)
		new_p[i] = p[i];
	delete[] p;
	p = new_p;
	Plane_size++;
	return;
}

void Keeper::resize_t() {
	int new_size = Train_size + 1;
	Train* new_t = new Train[new_size];
	for (int i = 0; i < Train_size; ++i)
		new_t[i] = t[i];
	delete[] t;
	t = new_t;
	Train_size++;
	return;
}


void Keeper::read() {
	ifstream out("database.txt");

	int size = 0;
	out >> size;
	for (int i = 0; i < size; i++) {
		cout << "+++++++++++++" << endl;
		int year, size_c, volume;
		string stamp, model;

		out >> year
			>> stamp
			>> model;
		out >> size_c;
		d* delivery = new d[size_c];
		for (int j = 0; j < size_c; j++) out >> delivery[j].city >> delivery[j].time;
		out >> volume;

		add(year, stamp, model, size_c, delivery, volume);
		cout << "+++++++++++++" << endl;
	}

	out >> size;
	for (int i = 0; i < size; i++) {
		cout << "+++++++++++++" << endl;
		string type, name;
		int volume, size_city;
		int size[3];

		out >> type
			>> name
			>> volume
			>> size[0]
			>> size[1]
			>> size[2];
		out >> size_city;
		string* city = new string[size_city];
		for (int j = 0; j < size_city; j++) out >> city[j];
		add(type, name, volume, size, size_city, city);
		cout << "+++++++++++++" << endl;
	}

	out >> size;
	for (int i = 0; i < size; i++) {
		cout << "+++++++++++++" << endl;
		string name;
		int year, size_r, nVan, volume;

		out >> name
			>> year
			>> size_r;
		string* route = new string[size_r];
		for (int j = 0; j < size_r; j++) out >> route[j];

		out >> nVan
			>> volume;
		add(name, year, size_r, route, nVan, volume);
		cout << "+++++++++++++" << endl;
	}
}

void Keeper::add(int year, string stamp, string model, int size_c, d* delivery, int volume) {//car
	c[Car_size-1].year_of_realize = year;
	c[Car_size - 1].stamp = stamp;
	c[Car_size - 1].model = model;
	for (int i = 0; i < size_c; i++) {
		c[Car_size - 1].delivery[i] = delivery[i];
		c[Car_size - 1].resize_D();
	}

	c[Car_size - 1].volume = volume;
	resize_c();

}

void Keeper::add(string type, string name, int volume, int size [], int size_city, string* city) {
	p[Plane_size-1].type = type;
	p[Plane_size - 1].name = name;
	p[Plane_size - 1].volume = volume;
	p[Plane_size - 1].size[0] = size[0];
	p[Plane_size - 1].size[1] = size[1];
	p[Plane_size - 1].size[2] = size[2];
	for (int i = 0; i < size_city; i++) {
		p[Plane_size - 1].resize_City();
		p[Plane_size - 1].city[i] = city[i];
	}
	resize_p();
}

void Keeper::add(string name, int year, int size_r, string* route, int nVan, int volume) {
	t[Train_size-1].name = name;
	t[Train_size - 1].year_of_release = year;
	for (int i = 0; i < size_r; i++) {
		t[Train_size - 1].resize_route();
		t[Train_size - 1].route[i] = route[i];
	}
	t[Train_size - 1].nVan = nVan;
	t[Train_size - 1].volume = volume;
	resize_t();
}


void Keeper::save() {
	ofstream in("database.txt", ios_base::out | ios_base::trunc);
	
	in << Car_size-1 << endl;
	for (int i = 0; i < Car_size - 1; i++) {
		in << c[i].year_of_realize << endl
			<< c[i].stamp << endl
			<< c[i].model << endl
			<< c[i].size_delivery-1 << endl;
		for (int j = 0; j < c[i].size_delivery - 1; j++)
			in << c[i].delivery[j].city << endl
			<< c[i].delivery[j].time << endl;
		in << c[i].volume << endl;
	}

	in << Plane_size-1 << endl;
	for (int i = 0; i < Plane_size - 1; i++) {
		in << p[i].type << endl
			<< p[i].name << endl
			<< p[i].volume << endl
			<< p[i].size[0] << endl
			<< p[i].size[1] << endl
			<< p[i].size[2] << endl
			<< p[i].size_ci-1 << endl;
		for (int j = 0; j < p[i].size_ci - 1; j++)
			in << p[i].city[j] << endl;
	}

	in << Train_size-1 << endl;
	for (int i = 0; i < Train_size - 1; i++) {
		in << t[i].name << endl
			<< t[i].year_of_release << endl
			<< t[i].size_ro-1 << endl;
		for (int j = 0; j < t[i].size_ro - 1; j++)
			in << t[i].route[j] << endl;

		in << t[i].nVan << endl
			<< t[i].volume << endl;
	}
	in.close();
	return;
}

void Keeper::write_al() {
	Number = 0;

	cout << "--------------CAR--------------" << endl;
	for (int i = 0; i < Car_size-1; i++) {
		cout << "(" << Number+1 << ")" << endl;

		cout << "Year of release: " << c[i].year_of_realize << endl
			<< "Stamp: " << c[i].stamp << endl
			<< "Model: " << c[i].model << endl;

		cout << "Delivery cities" << endl;
		for (int j = 0; j < c[i].size_delivery-1; j++)
			cout << "City: " << c[i].delivery[j].city << endl
			<< "Delivery time: " << c[i].delivery[j].time << endl;

		cout << "Volume: " << c[i].volume << endl;
		Number++;
	}

	cout << "--------------PLANE--------------" << endl;

	for (int i = 0; i < Plane_size-1; i++) {
		cout << "(" << Number + 1 << ")" << endl;

		cout << "Type: " << p[i].type << endl
			<< "Name: " << p[i].name << endl
			<< "Volume: " << p[i].volume << endl
			<< "Size: [" << p[i].size[0] << "; " << p[i].size[1] << "; " << p[i].size[2] << "]" << endl;

		cout << "City: [";
		for (int j = 0; j < p[i].size_ci-1; j++)
			cout << p[i].city[j] << " -> ";

		cout << "END]" << endl;
		Number++;
	}

	cout << "--------------TRAIN--------------" << endl;
	for (int i = 0; i < Train_size-1; i++) {
		cout << "(" << Number + 1 << ")" << endl;

		cout << "Name: " << t[i].name << endl
			<< "Year of release: " << t[i].year_of_release << endl;

		cout << "Route: [";
		for (int j = 0; j < t[i].size_ro-1; j++)
			cout << t[i].route[j] << " -> ";
		cout << "END]" << endl;

		cout << "Number of wagons: " << t[i].nVan << endl
			<< "Volume: " << t[i].volume << endl;
		Number++;
	}
}

void Keeper::delette(int n) {
	n--;

	if (Number < n + 1) return;

	n = n - Car_size + 1;
	if (n <= 0) {
		n += Car_size - 1;
		for (int i = n; i < Car_size-1; i++) c[i] = c[i + 1];
		Car_size--;
		return;
	}

	n = n - Plane_size + 1;
	if (n <= 0) {
		n += Plane_size - 1;
		for (int i = n; i < Plane_size - 1; i++) p[i] = p[i + 1];
		Plane_size--;
		return;
	}

	n = n - Train_size + 1;
	if (n <= 0) {
		n += Train_size - 1;
		for (int i = n; i < Train_size - 1; i++) t[i] = t[i + 1];
		Train_size--;
		return;
	}
}

void Keeper::change_data(int n) {
	n--;

	if (Number < n + 1) return;

	n = n - Car_size + 1;
	if (n <= 0) {
		n += Car_size - 1;
		while (1) {
			cout << "Choose which data needs to be changed: " << endl
				<< "1)Year of realize" << endl
				<< "2)Stamp" << endl
				<< "3)Model" << endl
				<< "4)Delivery" << endl
				<< "5)Volume" << endl
				<< "0)Return" << endl;
			int ch = safe_input_int();

			switch (ch)
			{
			case 1: {
				cout << "New year: " << endl;
				int y = safe_input_int();
				c[n].year_of_realize = y;
				break; 
			}
			case 2: {
				cout << "New stamp: " << endl;
				string y = safe_input_string();
				c[n].stamp = y;
				break;
			}
			case 3: {
				cout << "New model: " << endl;
				string y = safe_input_string();
				c[n].model = y;
				break;
			}
			case 4: {
				c[n].size_delivery = 1;
				cout << "Enter the cities and delivery time(in hours), if the input is finished, enter 0" << endl;
				while (1) {
					cout << "City or 0" << endl;
					string s = safe_input_string();
					if (s == "0") break;
					c[n].delivery[c[n].size_delivery - 1].city = s;
					cout << "Time:" << endl;
					c[n].delivery[c[n].size_delivery - 1].time = safe_input_int();
					c[n].resize_D();
				}
				break;
			}
			case 5: {
				cout << "New volume: " << endl;
				int y = safe_input_int();
				c[n].volume = y;
				break;
			}

			case 0:	return;

			default:
				break;
			}
		}
	}

	n = n - Plane_size + 1;
	if (n <= 0) {
		n += Plane_size - 1;
		while (1) {
			cout << "Choose which data needs to be changed: " << endl
				<< "1)Type" << endl
				<< "2)Name" << endl
				<< "3)Volume" << endl
				<< "4)Size" << endl
				<< "5)City" << endl
				<< "0)Return" << endl;
			int ch = safe_input_int();

			switch (ch)
			{
			case 1: {
				cout << "New type: " << endl;
				string y = safe_input_string();
				p[n].type = y;
				break;
			}
			case 2: {
				cout << "New name: " << endl;
				string y = safe_input_string();
				p[n].name = y;
				break;
			}
			case 3: {
				cout << "New volume: " << endl;
				int y = safe_input_int();
				p[n].volume = y;
				break;
			}
			case 4: {
				cout << "New length" << endl;
				p[n].size[0] = safe_input_int();
				cout << "New width" << endl;
				p[n].size[1] = safe_input_int();
				cout << "New height" << endl;
				p[n].size[2] = safe_input_int();
				break;
			}
			case 5: {
				p[n].size_ci = 1;
				cout << "Enter the cities if the input is finished, enter 0" << endl;
				while (1) {
					string s = safe_input_string();
					if (s == "0") break;
					p[n].city[p[n].size_ci - 1] = s;
					p[n].resize_City();
				}
				break;
			}

			case 0:	return;

			default:
				break;
			}
		}
	}

	n = n - Train_size + 1;
	if (n <= 0) {
		n += Train_size - 1;
		while (1) {
			cout << "Choose which data needs to be changed: " << endl
				<< "1)Name" << endl
				<< "2)Year of realize" << endl
				<< "3)Route" << endl
				<< "4)Number of wagons" << endl
				<< "5)Volume" << endl
				<< "0)Return" << endl;
			int ch = safe_input_int();

			switch (ch)
			{
			case 1: {
				cout << "New name: " << endl;
				t[n].name = safe_input_string();
				break;
			}
			case 2: {
				cout << "New year of realize: " << endl;
				t[n].year_of_release = safe_input_int();
				break;
			}
			case 3: {
				cout << "New Route: " << endl;
				t[n].size_ro = 1;
				cout << "Enter the cities if the input is finished, enter 0" << endl;
				while (1) {
					string s = safe_input_string();
					if (s == "0") break;
					t[n].route[t[n].size_ro - 1] = s;
					t[n].resize_route();
				}
				break;
			}
			case 4: {
				cout << "New number of wagons: " << endl;
				t[n].nVan = safe_input_int();
				break;
			}
			case 5: {
				cout << "New volume: " << endl;
				t[n].volume = safe_input_int();
				break;
			}

			case 0:	return;

			default:
				break;
			}
		}
	}
}

void Keeper::city_search(string city) {

	system("cls");

	cout << "--------------CAR--------------" << endl;
	for (int i = 0; i < Car_size - 1; i++) {
		for (int j = 0; j < c[i].size_delivery; j++) {
			if (c[i].delivery[j].city == city) {
				cout << "Year of release: " << c[i].year_of_realize << endl
					<< "Stamp: " << c[i].stamp << endl
					<< "Model: " << c[i].model << endl;

				cout << "Delivery cities" << endl;
				for (int k = 0; k < c[i].size_delivery - 1; k++)
					cout << "City: " << c[i].delivery[k].city << endl
					<< "Delivery time: " << c[i].delivery[k].time << endl;

				cout << "Volume: " << c[i].volume << endl;
				break;
			}
		}
	}
	cout << "--------------Plane--------------" << endl;
	for (int i = 0; i < Plane_size - 1; i++) {
		for (int j = 0; j < p[i].size_ci; j++) {
			if (p[i].city[j] == city) {
				cout << "Type: " << p[i].type << endl
					<< "Name: " << p[i].name << endl
					<< "Volume: " << p[i].volume << endl
					<< "Size: [" << p[i].size[0] << "; " << p[i].size[1] << "; " << p[i].size[2] << "]" << endl;

				cout << "City: [";
				for (int k = 0; k < p[i].size_ci - 1; k++) cout << p[i].city[k] << " -> ";

				cout << "END]" << endl;
				break;
			}
		}
	}
	cout << "--------------Train--------------" << endl;
	for (int i = 0; i < Train_size - 1; i++) {
		for (int j = 0; j < t[i].size_ro; j++) {
			if (t[i].route[j] == city) {
				cout << "Name: " << t[i].name << endl
					<< "Year of release: " << t[i].year_of_release << endl;

				cout << "Route: [";
				for (int k = 0; k < t[i].size_ro - 1; k++) cout << t[i].route[k] << " -> ";
				cout << "END]" << endl;

				cout << "Number of wagons: " << t[i].nVan << endl
					<< "Volume: " << t[i].volume << endl;
				break;
			}
		}
	}

	system("pause");
}
