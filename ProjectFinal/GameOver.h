#pragma once
using namespace System;
using namespace System::Drawing;

class GameOver {
private:
	int indw, indh, w, h;

public:
	GameOver(Bitmap^ bmp) {
		this->indw = this->indh = 0;
		this->w = bmp->Width / 6;
		this->h = bmp->Height / 5;
	}
	~GameOver() {}

	void animacion_gif(Graphics^ g, Bitmap^ bmp) {
		Rectangle porcion = Rectangle(indw * w, indh * h, w, h);
		Rectangle zoom = Rectangle(0, 0, w * 1.6, h * 1.67);
		g->DrawImage(bmp, zoom, porcion, GraphicsUnit::Pixel);
	}
	void actualizar_indices() {
		indw++;
		if (indw > 5) {
			indw = 0;
			indh++;
			if (indh > 4)
				indh = 0;
		}
	}
};