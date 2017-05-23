#pragma once
#include "Personaje.h"
#include "Escenario.h"
#include "Caja.h"

class Interaccion
{
private:
public:
	Interaccion();
	virtual ~Interaccion();
	void Mueve(float t);
	static bool rebotecaja(Personaje &h, Caja c);
	static void rebote(Personaje &h, Suelo s);
	static bool localizacion(Personaje &h, Suelo s);
	static bool localizacion2(Personaje &h, Escenario &c);
	static void rebote(Personaje &h, Escenario &e);
};
