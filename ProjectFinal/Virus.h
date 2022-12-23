#pragma once
#include "Movil.h"

class Virus : public Movil
{
private:
	// hereda del padre
	int randon;
public:
	Virus();
	~Virus();

	void mover(int limx, int limy);
};

Virus::Virus() : Movil(50 + rand() % (1400 - 50), 100 + rand() % (700 - 100), 1, 1)
{
	this->dx = this->dy = 8;
	this->zoomW = this->zoomH = 0.08;
	this->randon = 1 + rand() % (3 - 1);
}

Virus::~Virus()
{
}

void Virus::mover(int limx, int limy)
{
	if (x + dx < 0 || x + dx + w * zoomW > limx) {
		dx *= -1;
	}
	if (y + dy < 0 || y + dy + h  * zoomH > limy) {
		dy *= -1;
	}

	x += dx;
	y += dy;
	
}


