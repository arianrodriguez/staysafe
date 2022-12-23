#pragma once
#include "Jugador.h"
#include "Vacuna.h"
#include "NPC.h";
#include "Botiquin.h"
#include "BarraVidas.h"
#include "BarraBalas.h"
#include "Ambulancia.h"
#include "Pildora.h"
#include "GlobosTexto.h"
#include "Virus.h"
#include "Fichero.h"
// Controlador para el nivel dificil

class Controlador2
{
private:
	Fichero* datos_fichero;
	Jugador* objJug;
	vector<Vacuna*>* arrV;
	vector<NPC*>* arrNPC;
	vector<Virus*>* arrVirus;
	vector<Botiquin*>* arrBot;
	vector<Pildora*>* arrPil;
	BarraVidas* objVida;
	BarraBalas* objBarraBalas;
	Ambulancia* ambulancia;
	GlobosTexto* gb_texto;

	vector<GlobosTexto*>* dosis;


	bool botiquin_suelto, refill;
	int temp;	// para validar el tiempo de inmunidad del personaje
	int tempPildoras;	// para validar el tiempo de vida de una pildora en el escenario de juego
	int cont_seg, cont_min, cont_ax, aux_globos, aux_dosis;
	int numNPC, numVirus;
	int puntos;
public:
	Controlador2(Graphics^ g);
	~Controlador2();

	Jugador* getJugador();
	int getNumNPC() { return this->numNPC; }
	int getNumVirus() { return this->numVirus; }
	void agregarBala();
	void agregarNPC();
	void agregarVirus();
	void agregarBotiquin();
	void agregarPildora();
	void agregarDosisNPC(int x, int y);

	void desaparecerPildora();
	void tiempoInmunidad();
	void jugar(Graphics^ gr, Bitmap^ imgJugador, Bitmap^ imgVacuna, Bitmap^ imgInfectado1,
		Bitmap^ imgInfectado2, Bitmap^ imgSano1, Bitmap^ imgSano2, Bitmap^ imgBotiquin, Bitmap^ imgVidas, Bitmap^ imgBarraBalas,
		Bitmap^ bmp_ambu, Bitmap^ imgPildora, Bitmap^, Bitmap^, Bitmap^, Bitmap^, Bitmap^, Bitmap^, Bitmap^, Bitmap^);

	void moverTodo(Graphics^ gr);
	void mostrarTodo(Graphics^ gr, Bitmap^ imgJugador, Bitmap^ imgVacuna, Bitmap^ imgInfectado1,
		Bitmap^ imgInfectado2, Bitmap^ imgSano1, Bitmap^ imgSano2, Bitmap^ imgBotiquin, Bitmap^ imgVidas, Bitmap^ imgBarraBalas,
		Bitmap^ bmp_ambu, Bitmap^ imgPildora, Bitmap^, Bitmap^, Bitmap^, Bitmap^, Bitmap^, Bitmap^, Bitmap^, Bitmap^);
	bool gameOver();
	bool gameWin();

	void colision(vector<Rectangle*>*);
	void refill_balas(Graphics^);
	bool getBotiquinSuelto() { return this->botiquin_suelto; }
	void setBotiquinSuelto(bool botiquin_suelto) { this->botiquin_suelto = botiquin_suelto; }
	int getrefill() { return this->refill; }
	int getcontseg() { return this->cont_seg; }
	int getcontmin() { return this->cont_min; }
	vector<NPC*>* getvectornpc() { return arrNPC; }

	bool time_over();
	void actualizar_seg();
};

Controlador2::Controlador2(Graphics^ g)
{
	datos_fichero = new Fichero();
	datos_fichero->leer_datos();
	objJug = new Jugador();
	arrV = new vector<Vacuna*>();
	arrNPC = new vector<NPC*>();
	arrVirus = new vector<Virus*>();
	arrBot = new vector<Botiquin*>();
	objVida = new BarraVidas();
	arrPil = new vector<Pildora*>();
	objBarraBalas = new BarraBalas(); //	objBarraBalas = new BarraBalas(g->VisibleClipBounds.Width); -> para colocarlo esquina super der
	ambulancia = new Ambulancia(g->VisibleClipBounds.Width);
	dosis = new vector<GlobosTexto*>();

	this->botiquin_suelto = this->refill = false;
	this->temp = 50;	// aqui controlas el tiempo de inmunidad del jugador
	this->tempPildoras = 100;	// (lo cambie a 10s por la dificultad dx) 

	this->cont_min = 1; //se puede cambiar dependiendo la dificultad
	this->cont_seg = 60; //igual los segundos
	this->cont_ax = 2; //es de ayuda xd, depende de los min + seg

	this->aux_globos = this->aux_dosis = 0;
	this->numNPC = 12;
	this->numVirus = 5;
	this->puntos = 0;

	objJug->setX(datos_fichero->getxjug());
	objJug->setY(datos_fichero->getyjug());
	objJug->setnumVacunas(datos_fichero->getvacjug());
	objJug->setMaxVacunas(datos_fichero->getmaxvacjug());

	/*Aqui se le da el nuevo valor para validar la dificultad (dificil) - falta validar mas dx*/
	objVida->setIndH(2);
	objJug->setVidas(3);
}

Controlador2::~Controlador2()
{
}

Jugador* Controlador2::getJugador()
{
	return objJug;
}

void Controlador2::agregarBotiquin()
{
	arrBot->push_back(new Botiquin());
}

void Controlador2::agregarPildora()
{
	arrPil->push_back(new Pildora());
}

void Controlador2::desaparecerPildora()
{
	if (tempPildoras == 0) {
		for (int i = 0; i < arrPil->size(); i++)
		{
			arrPil->at(i)->setVisibilidad(false);
		}
		tempPildoras = 100;	// aqui tambien se cambio con lo de arriba dx
	}
	else {
		tempPildoras--;
	}
}

void Controlador2::tiempoInmunidad()
{
	if (temp == 0) {
		objJug->setinmunidad(false);
	}
	else {
		temp--;
	}
}

void Controlador2::agregarBala()
{
	if (objJug->getNumVacunas() > 0) {
		objJug->actNumVacunas(0); // pierde una municion
		objBarraBalas->pierdeMunicion();
		arrV->push_back(new Vacuna(objJug->getX() + 15, objJug->getY() + 15, objJug->getDireccion()));
	}
	else return;
}

void Controlador2::agregarNPC()
{
	arrNPC->push_back(new NPC());
}

void Controlador2::agregarVirus()
{
	arrVirus->push_back(new Virus());
}

void Controlador2::agregarDosisNPC(int x, int y) {
	dosis->push_back(new GlobosTexto(x, y));
}

void Controlador2::jugar(Graphics^ gr, Bitmap^ imgJugador, Bitmap^ imgVacuna, Bitmap^ imgInfectado1,
	Bitmap^ imgInfectado2, Bitmap^ imgSano1, Bitmap^ imgSano2, Bitmap^ imgBotiquin, Bitmap^ imgVidas, Bitmap^ imgBarraBalas,
	Bitmap^ bmp_ambu, Bitmap^ imgPildora, Bitmap^ imgPersonajeInmune, Bitmap^ txt_soyinmune, Bitmap^ txt_recargando,
	Bitmap^ dosis1, Bitmap^ dosis2, Bitmap^ dosis3, Bitmap^ sindosis, Bitmap^ imgVirus)
{
	moverTodo(gr);
	mostrarTodo(gr, imgJugador, imgVacuna, imgInfectado1, imgInfectado2, imgSano1, imgSano2, imgBotiquin,
		imgVidas, imgBarraBalas, bmp_ambu, imgPildora, imgPersonajeInmune, txt_soyinmune, txt_recargando,
		dosis1, dosis2, dosis3, sindosis, imgVirus);
}

void Controlador2::moverTodo(Graphics^ gr)
{
	objJug->mover(gr->VisibleClipBounds.Width, gr->VisibleClipBounds.Height);

	for (int i = 0; i < arrNPC->size(); i++)
	{
		arrNPC->at(i)->mover(gr->VisibleClipBounds.Width, gr->VisibleClipBounds.Height);
		dosis->at(i)->setX(arrNPC->at(i)->getX());
		dosis->at(i)->setY(arrNPC->at(i)->getY() - 35);
	}

	for (int i = 0; i < arrV->size(); i++)
	{
		arrV->at(i)->mover(gr->VisibleClipBounds.Width, gr->VisibleClipBounds.Height);
	}

	if (objJug->getNumVacunas() == 0)
		ambulancia->mover(gr->VisibleClipBounds.Width, gr->VisibleClipBounds.Height);

	for (int i = 0; i < arrVirus->size(); i++)
	{
		arrVirus->at(i)->mover(gr->VisibleClipBounds.Width, gr->VisibleClipBounds.Height);
	}
}

void Controlador2::mostrarTodo(Graphics^ gr, Bitmap^ imgJugador, Bitmap^ imgVacuna, Bitmap^ imgInfectado1,
	Bitmap^ imgInfectado2, Bitmap^ imgSano1, Bitmap^ imgSano2, Bitmap^ imgBotiquin, Bitmap^ imgVidas, Bitmap^ imgBarraBalas,
	Bitmap^ bmp_ambu, Bitmap^ imgPildora, Bitmap^ imgPersonajeInmune, Bitmap^ txt_soyinmune, Bitmap^ txt_recargando,
	Bitmap^ dosis1, Bitmap^ dosis2, Bitmap^ dosis3, Bitmap^ sindosis, Bitmap^ imgVirus)
{

	/*cambio de sprite en el jugador - INMUNE*/
	if (!objJug->getinmunidad()) {
		this->aux_globos = 0;
		objJug->mostrar(gr, imgJugador);
	}
	else {
		if (this->aux_globos == 0)
			gb_texto = new GlobosTexto(objJug->getX(), objJug->getY() - 25);

		gb_texto->setX(objJug->getX());
		gb_texto->setY(objJug->getY() - 25);
		objJug->mostrar(gr, imgPersonajeInmune);

		if (!this->refill)
			gb_texto->mostrar(gr, txt_soyinmune);
		else
			gb_texto->mostrar(gr, txt_recargando);
		this->aux_globos++;
	}


	for (int i = 0; i < arrNPC->size(); i++)
	{
		if (arrNPC->at(i)->getGenero() == 'M') {
			if (arrNPC->at(i)->getEstado() == 'E') {
				arrNPC->at(i)->mostrar(gr, imgInfectado1);
				if (!arrNPC->at(i)->getsalvado()) {
					switch (arrNPC->at(i)->getCantDosis()) {
					case 0:	dosis->at(i)->mostrar(gr, sindosis); break;
					case 1:	dosis->at(i)->mostrar(gr, dosis1); break;
					case 2:	dosis->at(i)->mostrar(gr, dosis2); break;
					case 3:	dosis->at(i)->mostrar(gr, dosis3); break;
					default: break;
					}
				}
			}
			else {
				arrNPC->at(i)->mostrar(gr, imgSano1);
				if (!arrNPC->at(i)->getsalvado()) {
					switch (arrNPC->at(i)->getCantDosis()) {
					case 0:	dosis->at(i)->mostrar(gr, sindosis); break;
					case 1:	dosis->at(i)->mostrar(gr, dosis1); break;
					case 2:	dosis->at(i)->mostrar(gr, dosis2); break;
					case 3:	dosis->at(i)->mostrar(gr, dosis3); break;
					default: break;
					}
				}
			}
		}
		else if (arrNPC->at(i)->getGenero() == 'F') {
			if (arrNPC->at(i)->getEstado() == 'E') {
				arrNPC->at(i)->mostrar(gr, imgInfectado2);
				if (!arrNPC->at(i)->getsalvado()) {
					switch (arrNPC->at(i)->getCantDosis()) {
					case 0:	dosis->at(i)->mostrar(gr, sindosis); break;
					case 1:	dosis->at(i)->mostrar(gr, dosis1); break;
					case 2:	dosis->at(i)->mostrar(gr, dosis2); break;
					case 3:	dosis->at(i)->mostrar(gr, dosis3); break;
					default: break;
					}
				}
			}
			else {
				arrNPC->at(i)->mostrar(gr, imgSano2);
				if (!arrNPC->at(i)->getsalvado()) {
					switch (arrNPC->at(i)->getCantDosis()) {
					case 0:	dosis->at(i)->mostrar(gr, sindosis); break;
					case 1:	dosis->at(i)->mostrar(gr, dosis1); break;
					case 2:	dosis->at(i)->mostrar(gr, dosis2); break;
					case 3:	dosis->at(i)->mostrar(gr, dosis3); break;
					default: break;
					}
				}
			}
		}
	}

	for (int i = 0; i < arrV->size(); i++)
	{
		arrV->at(i)->mostrar(gr, imgVacuna);
	}

	for (int i = 0; i < arrBot->size(); ++i) {
		arrBot->at(i)->animacion(gr, imgBotiquin);
	}

	for (int i = 0; i < arrPil->size(); i++)
	{
		arrPil->at(i)->mostrar(gr, imgPildora);
	}

	objVida->mostrar(gr, imgVidas);
	objBarraBalas->mostrar(gr, imgBarraBalas);

	if (objJug->getNumVacunas() == 0) {
		this->refill = true;
		objJug->setinmunidad(true);
		ambulancia->mostrar(gr, bmp_ambu);
	}

	for (int i = 0; i < arrVirus->size(); i++)
	{
		arrVirus->at(i)->mostrar(gr, imgVirus);
	}
}

void Controlador2::colision(vector<Rectangle*>* paredes)
{
	/*jugador con alguna pared*/

	for (int i = 0; i < paredes->size(); ++i) {
		if (objJug->futRectangle(objJug->getX() + objJug->getDX(), objJug->getY() + objJug->getDY(), objJug->getW(), objJug->getH()).IntersectsWith(*paredes->at(i))) {
			objJug->setMovValido(false);
		}
		else {
			objJug->setMovValido(true);
		}
	}

	/*personajes con alguna pared*/

	for (int i = 0; i < paredes->size(); ++i) {
		for (int j = 0; j < arrNPC->size(); ++j) {
			if (arrNPC->at(j)->colision(*paredes->at(i))) {
				arrNPC->at(j)->cambiarDireccion();
				arrNPC->at(j)->setDY(-arrNPC->at(j)->getDY());
				//arrNPC->at(j)->setDX(-arrNPC->at(j)->getDX());
			}
		}
	}

	// personaje con algun virus

	for (int i = 0; i < arrVirus->size(); i++)
	{
		if(objJug->colision(arrVirus->at(i)->getRectangle()) && objJug->getinmunidad() == false){
			arrVirus->at(i)->setVisibilidad(false);
			objJug->pierdeVida();	// metodo de la clase jugador revisar
			objVida->quitarVida();	// intercambio de sprite
		}
	}

	// persona sana con algun virus

	for (int i = 0; i < arrVirus->size(); i++)
	{
		for (int j = 0; j < arrNPC->size(); j++)
		{
			if (arrVirus->at(i)->colision(arrNPC->at(j)->getRectangle()) && arrNPC->at(j)->getEstado() == 'S') {

				arrVirus->at(i)->setVisibilidad(false);
				arrNPC->at(j)->setCantDosis(0);
				arrNPC->at(j)->setEstado('E');
				arrNPC->at(j)->setsalvado(false);
				puntos--;
			}
		}
	}

	// choque de vacuna contra infectados
	for (int i = 0; i < arrV->size(); i++)
	{
		for (int j = 0; j < arrNPC->size(); j++)
		{
			if (arrV->at(i)->colision(arrNPC->at(j)->getRectangle()) && arrNPC->at(j)->getEstado() == 'E') {
				arrV->at(i)->setVisibilidad(false);
				arrNPC->at(j)->aumentarCantDosis();

				if (arrNPC->at(j)->getCantDosis() == 3) {// cuando reciba 3 dosis
					arrNPC->at(j)->setEstado('S');			// está sano
					arrNPC->at(j)->setsalvado(true);
					puntos++;
				}
			}
		}
	}

	// choque infectado contra personaje principal(doctor)

	for (int i = 0; i < arrNPC->size(); i++)
	{
		if (objJug->colision(arrNPC->at(i)->getRectangle()) && arrNPC->at(i)->getEstado() == 'E'
			&& objJug->getinmunidad() == false)
		{
			objJug->pierdeVida();	// metodo de la clase jugador revisar
			objVida->quitarVida();	// intercambio de sprite
			objJug->reposicion();	// nueva posicion en x , y al morir
		}
	}

	/*el jugador con las pildoras (le otorga inmunidad)*/
	for (int i = 0; i < arrPil->size(); i++)
	{
		if (objJug->colision(arrPil->at(i)->getRectangle())) {
			arrPil->at(i)->setVisibilidad(false);
			objJug->setinmunidad(true);// le da inmunidad al colisionar con la pildora
			temp = 50;	// reiniciar contador (NO BORRAR)
		}
	}

	// funcion para controlar el tiempo de inmunidad del jugador
	tiempoInmunidad();

	// funcion para validar los seg de aparacion de la pildora una vez se genero
	desaparecerPildora();

	/*el jugador con los botiquines*/

	for (int i = 0; i < arrBot->size(); ++i) {
		if (objJug->colision(arrBot->at(i)->getRectangle())) {
			arrBot->at(i)->setVisibilidad(false);
			objJug->actVida(1); //opcion 1: vidas++, otra opcion: vidas--
			objVida->llenarVida(); //intercambio sprite
			this->botiquin_suelto = false;
		}
	}

	// para eliminar del arreglo
	for (int i = 0; i < arrV->size(); i++)
	{
		if (arrV->at(i)->getVisibilidad() == false) {
			arrV->erase(arrV->begin() + i);
		}
	}

	for (int i = 0; i < arrPil->size(); i++)
	{
		if (arrPil->at(i)->getVisibilidad() == false) {
			arrPil->erase(arrPil->begin() + i);
		}
	}

	for (int i = 0; i < arrNPC->size(); i++)
	{
		if (arrNPC->at(i)->getVisibilidad() == false) {
			arrNPC->erase(arrNPC->begin() + i);
		}
	}

	for (int i = 0; i < arrBot->size(); ++i) {
		if (!arrBot->at(i)->getVisibilidad())
			arrBot->erase(arrBot->begin() + i);
	}

	for (int i = 0; i < arrVirus->size(); i++)
	{
		if(!arrVirus->at(i)->getVisibilidad()){
			arrVirus->erase(arrVirus->begin() + i);
		}
	}
}

bool Controlador2::gameOver()
{
	if (objJug->getVida() == 0)
	{
		return true;
	}
	else return false;
}

bool Controlador2::gameWin()
{
	if (puntos >= numNPC) {
		return true;
	}
	else return false;
}

void Controlador2::refill_balas(Graphics^ g) {
	if (objJug->getNumVacunas() < 10) {
		if (objJug->colision(ambulancia->futRectangle(ambulancia->getX(), 0,	//**entidad tiene un futuro rectangulo para cualquiera**
			ambulancia->getW(), g->VisibleClipBounds.Height))) {		//la ambulancia tiene un rectangulo aparte, que abarca todo el eje y
			ambulancia->setDX(0);									//y asi no ser necesario que el jugador esté cerca a la ambulancia para que
			objJug->actNumVacunas(1);									//haya colisión
			objBarraBalas->recargaMunicion();
			objJug->setinmunidad(true);
		}
	}
	else {
		ambulancia->reposicion(g->VisibleClipBounds.Width);
		ambulancia->setDX(-25);
		this->refill = false;
		objJug->setinmunidad(false);
	}
}
void Controlador2::actualizar_seg() {
	if (this->cont_ax > 0) {
		this->cont_seg--;
		if (this->cont_seg == 0) {
			if (this->cont_min != 0) this->cont_min--;
			this->cont_seg = 60;
			this->cont_ax--;
			if (this->cont_ax == 0) this->cont_seg = 0; //para que no se muestre un 60 al final
		}
	}
}
bool Controlador2::time_over() { return(this->cont_ax == 0) ? true : false; }
