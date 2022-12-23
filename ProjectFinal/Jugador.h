#pragma once
#include "Movil.h"

class Jugador : public Movil {
private:
	int maxVacunas, numVacunas, vidas;
	bool inmunidad;
	string nombre;
	bool movValido;

public:
	Jugador() : Movil(0, 500, 4, 4) {
		this->maxVacunas = 10; //va a tener 10 vacunas como limite?si six2 okidoki dx
		this->numVacunas = 10;
		this->vidas = 5;
		this->zoomH = this->zoomW = 0.03;
		this->direccion = 'S';	// empieza con la tecla abajo
		this->inmunidad = false;
		this->movValido = true;
	}
	/*
	Jugador() {
		this->nombre = "Unknown";
		this->maxVacunas = 10;
		this->numVacunas = 10;
		this->vidas = 5;
	}*/
	~Jugador() {}

	void setinmunidad(bool inmunidad) { this->inmunidad = inmunidad; }
	bool getinmunidad() { return this->inmunidad; }
	void setVidas(int _vidas) { this->vidas = _vidas; }
	void setMaxVacunas(int maxVacunas) { this->maxVacunas = maxVacunas; }
	void setnumVacunas(int numVacunas) { this->numVacunas = numVacunas; }
	void actNumVacunas(int opc) { (opc == 1) ? this->numVacunas++ : this->numVacunas--; }
	int getVidas() { return this->vidas; }
	void actVida(int opc) { (opc == 1) ? this->vidas++ : this->vidas--; }
	int getMaxVacunas() { return this->maxVacunas; }
	int getNumVacunas() { return this->numVacunas; }
	int getVida() { return this->vidas; }
	void setnombre(String^ nombre) { this->nombre = Convert::ToInt32(nombre); }
	string getnombre() { return this->nombre; }

	bool getMovValido() { return this->movValido; }
	void setMovValido(bool _movValido) { this->movValido = _movValido; }

	void mover(int limx, int limy) {
		if (movValido) {	// el personaje no ha colisionado con ninguna pared
			if (x + dx >= 0 && x + dx + w * zoomW <= limx) {
				x += dx;
			}
			if (y + dy >= 0 && y + dy + h * zoomH <= limy) {
				y += dy;
			}
			if (dx == 0 && dy == 0) {
				indW = 0;
			}

			indW++;
			if (indW >= numC) indW = 0;
		}
	};

	void pierdeVida()
	{
		vidas--;
	}

	//nueva funcion
	void cambiarDireccion(char letra) {
		direccion = letra;
		switch (this->direccion) { //la direccion cambiarlo con el setdireccion directamente del controlador(? - okey
		case 'W':
			indH = 3;
			//y -= dx;
			lastindh = indH;
			break;
		case 'A':
			indH = 1;
			//x -= dx;
			lastindh = indH;
			break;
		case 'D':
			indH = 2;
			//x += dx;
			lastindh = indH;
			break;
		case 'S':
			indH = 0;
			//y += dy;
			lastindh = indH;
			break;
			//case 'N':
			//	indH = lastindh;
			//	dx = 0; dy = 0;
			//	break;
		}

	}

	void reposicion()
	{
		x = 0;
		y = 500;
	}
};