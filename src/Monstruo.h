#pragma once
#include "Vector3D.h"
#include "Personaje.h"

// PODEMOS VER LUEGO SI HACER HERENCIA CON PERSONAJE Y MONSTRUO
class Monstruo : public Personaje
{


public:
	Monstruo(void);
	virtual ~Monstruo(void);
};

