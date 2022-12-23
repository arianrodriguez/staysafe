#pragma once
using namespace System;
using namespace System::Drawing;

class YouWin {
private:
	int indw, indh, w, h;

public:
	YouWin(Bitmap^ bmp) {
		this->indw = this->indh = 0;
		this->w = bmp->Width / 1;
		this->h = bmp->Height / 2;
	}
	~YouWin() {}

	void animacion_gif(Graphics^ g, Bitmap^ bmp) {
		Rectangle porcion = Rectangle(indw * w, indh * h, w, h);
		Rectangle zoom = Rectangle(0, 0, w * 2, h * 1.6);
		g->DrawImage(bmp, zoom, porcion, GraphicsUnit::Pixel);
	}
	void actualizar_indices() {
		indw++;
		if (indw > 1) {
			indw = 0;
			indh++;
			if (indh > 2)
				indh = 0;
		}
	}
};