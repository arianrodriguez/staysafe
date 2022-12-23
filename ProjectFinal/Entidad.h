#pragma once
#include<vector>
#include<iostream>
#include<time.h>
#include <string>

using namespace std;
using namespace System::Drawing;
using namespace System;

class Entidad
{
protected:
	int x, y, w, h, indW, indH, numF, numC, lastindh;
	float zoomW, zoomH;
	bool visibilidad;

public:
	Entidad(int x, int y, int numF, int numC);
	Entidad();
	~Entidad();

	int getX() { return this->x; }
	int getY() { return this->y; }
	int getW() { return this->w; }
	int getH() { return this->h; }
	int getIndW() { return this->indW; }
	int getIndH() { return this->indH; }
	bool getVisibilidad() { return this->visibilidad; }

	void setX(int _x) { this->x = _x; }
	void setY(int _y) { this->y = _y; }
	void setIndW(int _indW) { this->indW = _indW; }
	void setIndH(int _indH) { this->indH = _indH; }
	void setVisibilidad(bool _visible) { this->visibilidad = _visible; }
	void setzoomw(int zoomw) { this->zoomW = zoomw; }
	void setzoomh(int zoomh) { this->zoomH = zoomh; }

	bool colision(Rectangle rec);
	void mostrar(Graphics^ gr, Bitmap^ bmp);
	void redimensionar(Bitmap^ bmp);
	Rectangle getRectangle();
	Rectangle futRectangle(int, int, int, int);
};

Entidad::Entidad(int x, int y, int numF, int numC)
{
	this->x = x;
	this->y = y;
	this->numF = numF;
	this->numC = numC;
	this->indW = this->indH = 0;
	this->zoomH = this->zoomW = 1;
	this->visibilidad = true;
}

Entidad::Entidad()
{
	this->x = this->y = 0;
	this->w = this->h = 0;
	this->indW = this->indH = 0;
	this->numF = this->numC = 1;
	this->zoomW = this->zoomH = 1;
	this->visibilidad = true;
}

Entidad::~Entidad()
{
}

void Entidad::mostrar(Graphics^ gr, Bitmap^ bmp)
{
	this->w = bmp->Width / numC;
	this->h = bmp->Height / numF;

	//bmp->MakeTransparent(bmp->GetPixel(1, 1));
	Rectangle porcionSprite = Rectangle(indW * w, indH * h, w, h);
	gr->DrawImage(bmp, getRectangle(), porcionSprite, GraphicsUnit::Pixel);
}

Rectangle Entidad::getRectangle()
{
	return Rectangle(x, y, w * zoomW, h * zoomH);
}

bool Entidad::colision(Rectangle rec)
{
	return getRectangle().IntersectsWith(rec);
}

void Entidad::redimensionar(Bitmap^ bmp)
{
}
Rectangle Entidad::futRectangle(int x, int y, int w, int h) { return Rectangle(x, y, w, h); }
