#pragma once
#include "Vector3D.h"

class Suelo
{
public: 	
	void Dibuja(void);
	void setColor(unsigned char rojo, unsigned char verde, unsigned char azul);
	void SetPos(float x1, float y1, float x2, float y2);
	float distancia(Vector2D punto, Vector2D *direccion=0);
private:
	unsigned char rojo;
	unsigned char azul;
	unsigned char verde;
	
	Vector3D limite1;
	Vector3D limite2;
	Vector3D limite3;
	Vector3D limite4;

};

