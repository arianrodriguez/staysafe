#pragma once
#include "Movil.h"

class Ambulancia : public Movil {
private:
	int cant_vac;

public:
	Ambulancia(int limx) : Movil(limx, 500, 1, 1) {
		this->cant_vac = 10;
		this->dx = -40;
		this->zoomH = this->zoomW = 0.25;
		this->visibilidad = false;
	}
	~Ambulancia(){}

	void setcantvac(int cantvac) { this->cant_vac = cantvac; }
	int getcantvac() { return this->cant_vac; }
	void reposicion(int limx) {
		this->x = limx;
		this->y = 500;
	}
	void mover(int limx, int limy){
		if (x + dx + w < 0)this->visibilidad = false;
		x += dx;
	}
};