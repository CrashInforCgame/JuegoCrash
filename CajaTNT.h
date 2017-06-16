#pragma once
#include "CajaExplosiva.h"

class CajaTNT:public CajaExplosiva
{
protected:
	int temporizador;
public:
	CajaTNT(void);
	~CajaTNT(void);
};

