#pragma once
#include "Entidad.h"

class Movil : public Entidad
{
protected:
	int dx, dy;
	char direccion;

public:
	Movil(int x, int y, int numF, int numC);
	Movil();
	~Movil();

	int getDX() { return this->dx; }
	int getDY() { return this->dy; }
	char getDireccion() { return this->direccion; }

	void setDX(int _dx) { this->dx = _dx; }
	void setDY(int _dy) { this->dy = _dy; }
	void setDireccion(char _direccion) { this->direccion = _direccion; }

	virtual void mover(int limx, int limy) = 0;
};
Movil::Movil(int x, int y, int numF, int numC) : Entidad(x, y, numF, numC)
{
	this->dx = this->dy = 0;
}

Movil::Movil() : Entidad() {
	this->dx = this->dy = 0;
}

Movil::~Movil()
{
}