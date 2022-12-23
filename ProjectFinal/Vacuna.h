#pragma once
#include "Movil.h"

class Vacuna : public Movil {
public:
	Vacuna(int x, int y, char direccion) : Movil(x, y, 2, 2) {
		this->direccion = direccion;
		this->zoomH = this->zoomW = 0.15;
	}
	Vacuna() : Movil() {
		this->x = this->y = 0;
		//this->direccion = 'N';
	}
	~Vacuna() {}

	void mover(int limx, int limy) {

		//if (direccion == 'S' && y + h * zoomH <= limx) {
		//	y += dy;
		//}
		//if (direccion == 'W' && y >= 0) {
		//	y -= dy;
		//}
		//if (direccion == 'A' && x >= 0) {
		//	x -= dx;
		//}
		//if (direccion == 'D' && x + w * zoomW <= limy) {
		//	x += dx;
		//}

		//direccion = letter;

		switch (this->direccion) {
		case 'W': indH = 0; indW = 0; dx = 0; dy = -20; break;
		case 'A': indH = 1; indW = 1; dx = -20; dy = 0; break;
		case 'S': indH = 1; indW = 0; dx = 0; dy = 20; break;
		case 'D': indH = 0; indW = 1; dx = 20; dy = 0; break;
		case 'N': indH = 0; indW = 0; dx = 0; dy = 0; break;
		}

		//if (x + dx<0 || x + dx + w>limx) { this->visibilidad = false; }
		//if (y + dy<0 || y + dy + h>limy) { this->visibilidad = false; }
		x += dx;
		y += dy;
	}
};