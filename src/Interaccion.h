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
	static void rebote(Personaje &h, Escenario c);
};
