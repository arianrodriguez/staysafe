#pragma once
#include <fstream>
#include <string>
using namespace std;
using namespace System;

class Fichero {
private:
	ofstream escribir_arch;
	ifstream leer_arch;

	string txt;
	int xjug, yjug, vacjug, maxvacjug;

public:
	Fichero() {}
	~Fichero(){}

	int getxjug() { return this->xjug; }
	int getyjug() { return this->yjug; }
	int getvacjug() { return this->vacjug; }
	int getmaxvacjug() { return this->maxvacjug; }

	void leer_datos() {
		leer_arch.open("config.txt", ios::in);
		if (leer_arch.fail()) {
			leer_arch.close();
			escribir_arch.open("config.txt", ios::out);
			escribir_arch << "0\n"; //x
			escribir_arch << "500\n"; // y
			escribir_arch << "10\n"; //num vacunas
			escribir_arch << "10\n"; // max vacunas
			escribir_arch.close();
			leer_arch.open("config.txt", ios::in);
		}
		int* i = new int;
		*i = 0;
		while (!leer_arch.eof()) {

			getline(leer_arch, txt);
			switch (*i) {
			case 0: this->xjug = atoi(txt.c_str()); break;
			case 1: this->yjug = atoi(txt.c_str()); break;
			case 2: this->vacjug = atoi(txt.c_str()); break;
			case 3: this->maxvacjug = atoi(txt.c_str()); break;
			default: break;
			}

			*i += 1;
		}

		leer_arch.close();
		delete i;
	}
};