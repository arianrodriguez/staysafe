#pragma once
#include "Estatico.h"

class Pildora : public Estatico
{
public:
	Pildora();
	~Pildora() {};

};

Pildora::Pildora() : Estatico(50 + rand() % (700 - 50), 350 + rand() % (500 - 50), 1, 1)
{
	this->zoomH = this->zoomW = 0.10;
}

