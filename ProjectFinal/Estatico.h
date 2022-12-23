#pragma once
#include "Entidad.h"

class Estatico : public Entidad
{
protected:

public:
	Estatico(int x, int y, int numF, int numC);
	Estatico();
	~Estatico();
};

Estatico::Estatico(int x, int y, int numF, int numC) : Entidad(x, y, numF, numC)
{
}

Estatico::Estatico() : Entidad()
{

}

Estatico::~Estatico()
{
}