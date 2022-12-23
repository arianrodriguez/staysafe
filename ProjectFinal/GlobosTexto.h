#pragma once
#include "Estatico.h"

class GlobosTexto : public Estatico {
private:
	int ind_npc;

public:
	GlobosTexto(int x, int y) : Estatico(x, y, 1, 1) {
		this->zoomH = this->zoomW = 0.15;
		this->ind_npc = 0;
	}
	~GlobosTexto(){}

	int getindnpc() { return this->ind_npc; }
	void setindnpc(int indnpc) { this->ind_npc = ind_npc; }

};