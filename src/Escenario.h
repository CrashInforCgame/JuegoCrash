#pragma once
#include "Suelo.h" 

class Escenario
{
private:
	Suelo suelo1;
	Suelo suelo2;
	Suelo suelo3;
	Suelo suelo4;
	Suelo suelo5;
public:
	Escenario();
	void Dibuja(void);

friend class Interaccion;
};
