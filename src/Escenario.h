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
	Suelo suelo6;
	Suelo suelo7;
	Suelo suelo8;
	Suelo suelo9;
	Suelo suelo10;
	Suelo suelo11;
	Suelo suelo12;
	Suelo suelo13;
	Suelo suelo14;
	Suelo suelo15;
	Suelo suelo16;

	int plano;
public:
	Escenario();
	void Dibuja(void);
friend class Interaccion;
};
