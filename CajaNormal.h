#pragma once
#include "Caja.h"
#include "Personaje.h"

class CajaNormal:public Caja
{
public:
	CajaNormal(void);
	void DestruirCaja(CajaNormal C, Personaje h)
	{

	}
	~CajaNormal(void);
};

