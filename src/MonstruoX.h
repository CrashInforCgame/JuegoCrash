#pragma once
#include "Vector3D.h"
#include "Personaje.h"
#include "glut.h"
#include "Monstruo.h"

class MonstruoX :public Monstruo
{
public:
	MonstruoX();
	virtual ~MonstruoX(void);
	void Mueve(float);
	void SetPos(float x, float y, float z);
private:
};

