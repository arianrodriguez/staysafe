#pragma once
#include "Movil.h"

class NPC : public Movil
{
private:
	char estado;
	char genero;
	int cantDosis;
	bool salvado;
public:
	NPC();
	~NPC();

	char getEstado() { return this->estado; }
	int getCantDosis() { return this->cantDosis; }
	bool getsalvado() { return this->salvado; }

	void setsalvado(bool salvado) { this->salvado = salvado; }
	void setCantDosis(int cantdosis) { this->cantDosis = cantdosis; }
	void aumentarCantDosis() { this->cantDosis++; }
	void setEstado(char _estado) { this->estado = _estado; }
	void hallaDireccion();

	void mover(int limx, int limy);
	void cambiarDireccion();

	char getGenero() { return this->genero; }
	void setGenero(char _genero) { this->genero = _genero; }
};

NPC::NPC() : Movil(100 + rand() % 1200, 360 + rand() % 300, 4, 4)
{
	this->estado = 'E'; // enfermo 
	this->cantDosis = 0;
	this->salvado = false;

	char generos[2] = { 'F', 'M' };
	this->genero = generos[rand() % 2];

	if (x < 750 && y < 535) // solo es temporal, cambiar luego:0 (aparece en la parte superior izq)
	{
		do {
			dx = ((rand() % 2) * 5);
			dy = ((rand() % 2) * 5);
		} while (dx == dy);
		hallaDireccion();
	}
	if (x < 750 && y > 535) // (aparece en la parte inferior izq)
	{
		do {
			dx = ((rand() % 2) * 5);
			dy = ((rand() % 2) * 5) * -1;
		} while ((dx * dx) == (dy * dy));
		hallaDireccion();
	}
	if (x > 750 && y > 535) // (aparece en la parte inferior derecha)
	{
		do {
			dx = ((rand() % 2) * 5) * -1;
			dy = ((rand() % 2) * 5) * -1;
		} while (dx == dy);
		hallaDireccion();
	}
	if (x > 750 && y < 535) // (aparece en la parte superior derecha)
	{
		do {
			dx = ((rand() % 2) * 5) * -1;
			dy = ((rand() % 2) * 5);
		} while ((dx * dx) == (dy * dy));
		hallaDireccion();
	}

}

NPC::~NPC()
{
}

void NPC::hallaDireccion() {
	if (this->dx * this->dx > this->dy * this->dy) {
		if (dx < 0) { this->direccion = 'A'; indH = 1; }
		else { this->direccion = 'D'; indH = 2; }
	}
	else {
		if (dy < 0) { this->direccion = 'W'; indH = 3; }
		else { this->direccion = 'S'; indH = 0; }
	}
}

void NPC::cambiarDireccion()
{
	switch (this->direccion)
	{
	case 'A':
		this->direccion = 'D';
		//this->indW = 0;
		this->indH = 2;
		break;
	case 'D':
		this->direccion = 'A';
		//this->indW = 0;
		this->indH = 1;
		break;
	case 'W':
		this->direccion = 'S';
		//this->indW = 0;
		this->indH = 0;
		break;
	case 'S':
		this->direccion = 'W';
		//this->indW = 0;
		this->indH = 3;
		break;
	}

}

void NPC::mover(int limx, int limy) {
	if (x + dx < 0 || x + dx + w > limx) {
		cambiarDireccion();
		dx *= -1;
	}
	if (y + dy < 0 || y + dy + h > limy) {
		cambiarDireccion();
		dy *= -1;
	}

	x += dx;
	y += dy;

	indW++;

	if (indW >= numC)
	{
		indW = 0;
	}
}

//class NPCs
//{
//private:
//	vector<NPC*> arreglo;
//public:
//	NPCs() { }
//	~NPCs() {
//		for (NPC* n : arreglo)
//			delete n;
//	}
//
//	void agregar(NPC* nuevo) {
//		arreglo.push_back(nuevo);
//	}
//	void mover(Graphics^ gr) {
//		for (int i = 0; i < arreglo.size(); ++i) {
//			arreglo.at(i)->mover(gr);
//		}
//	}
//	void mostrar(Graphics^ gr, Bitmap^ bmp) {
//		for (int i = 0; i < arreglo.size(); ++i) {
//			arreglo.at(i)->mostrar(gr, bmp);
//		}
//	}
//	void eliminar(int pos) {
//		arreglo.erase(arreglo.begin() + pos);
//	}
//};