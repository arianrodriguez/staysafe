#pragma once
#include "Estatico.h"

class BarraBalas : public Estatico
{
public:
	BarraBalas(int limX);
	BarraBalas();
	~BarraBalas();
	void pierdeMunicion();
	void recargaMunicion();
};

BarraBalas::BarraBalas(int limX) : Estatico(limX-180, 15, 11, 1)
{
	this->zoomH = this->zoomW = 0.4;
}

BarraBalas::BarraBalas() : Estatico(30, 70, 11, 1)
{
	this->zoomH = this->zoomW = 0.4;
}

BarraBalas::~BarraBalas()
{
}

void BarraBalas::pierdeMunicion() 
{
	if (indH < 10) indH++;
	else return;
}

void BarraBalas::recargaMunicion() {
	indH--;

	if (indH <= 0) { indH = 0; }
}