#pragma once
#include "Estatico.h"

class Botiquin : public Estatico
{
private:

public:
	Botiquin();
	~Botiquin();

	void animacion(Graphics^ g, Bitmap^ bmp);
};

Botiquin::Botiquin() : Estatico(50 + rand() % (700 - 50), 350 + rand() % (500 - 50), 1, 12)
{
	this->zoomW = this->zoomH = 0.05;
}

Botiquin::~Botiquin()
{
}

// para validar el intercambio de sprites, imagen en el drive
void Botiquin::animacion(Graphics^ g, Bitmap^ bmp)
{
	indW++;

	if (indW >= numC)
	{
		indW = 0;
	}
	mostrar(g, bmp);
}

