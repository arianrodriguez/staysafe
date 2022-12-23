#pragma once
#include "Estatico.h"

class BarraVidas : public Estatico
{
public:
	BarraVidas();
	~BarraVidas();

	void quitarVida();
	void llenarVida();
};

BarraVidas::BarraVidas() : Estatico(30, 20, 5, 1)
{
	this->zoomH = this->zoomW = 0.50;
}

BarraVidas::~BarraVidas()
{
}

void BarraVidas::llenarVida()
{
	indH--;

	if (indH <= 0) {
		indH = 0;
	}
}

void BarraVidas::quitarVida()
{
	indH++;
}