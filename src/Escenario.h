#pragma once
#include "Suelo.h" 
#include "Personaje.h" 
class Escenario
{
private:
	Suelo suelo1;
	Suelo suelo2;
	Suelo suelo3;
	Suelo suelo4;
	Suelo suelo5;
	int plano;
public:
	Escenario();
	void Dibuja(void);
friend class Interaccion;
};
