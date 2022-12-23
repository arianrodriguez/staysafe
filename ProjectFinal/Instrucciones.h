#pragma once
using namespace System;
using namespace System::Drawing;

class Instrucciones {
private:
	int indw, indh, w, h;

public:
	Instrucciones(Bitmap^ bmp) {
		this->indw = this->indh = 0;
		this->w = bmp->Width / 3;
		this->h = bmp->Height / 10;
	}
	~Instrucciones(){}

	void animacion_gif(Graphics^ g, Bitmap^ bmp, int limx, int limy) {
		Rectangle porcion = Rectangle(indw * w, indh * h, w, h);
		Rectangle zoom = Rectangle((limx-w)/2, (limy-h)/2, w, h);
		g->DrawImage(bmp, zoom, porcion, GraphicsUnit::Pixel);
	}
	void actualizar_indices() {
		indw++;
		if (indw > 2) {
			indw = 0;
			indh++;
			if (indh > 9)
				indh = 0;
		}
	}
};