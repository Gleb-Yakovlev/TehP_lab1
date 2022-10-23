#pragma once
#include <iostream>
#include <string>
using namespace std;
inline int safe_input_int() {
	int a = 0;
	while (1) {
		cin >> a;
		if (cin.good()) {
			cin.ignore(100, '\n');
			return a;
		}
		cin.clear();
		cin.ignore(100, '\n');
	}
}

inline string safe_input_string() {
	string a = "";
	getline(cin, a);
	return a;
}