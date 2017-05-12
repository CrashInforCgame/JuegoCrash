#pragma once
#include "Vector3D.h"

class Suelo
{
private:
	unsigned char rojo;
	unsigned char azul;
	unsigned char verde;
	
	Vector3D limite1;
	Vector3D limite2;
	Vector3D limite3;
	Vector3D limite4;
public: 	
	void Dibuja(void);
	void setColor(unsigned char rojo, unsigned char verde, unsigned char azul);
	void SetPos(float x1, float y1, float z1,float x2, float y2, float z2,float x3, float y3,
				 float z3,float x4, float y4, float z4);

	friend class Interaccion;
};

