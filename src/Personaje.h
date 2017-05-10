#pragma once
#include "Vector3D.h"

class Personaje
{
public:

	Personaje();
	void Dibuja(void);
	void Mueve(float);
	void SetColor(unsigned char rojo, unsigned char verde, unsigned char azul);
	void SetRadio(float radio);
	void SetPos(float x, float y, float vz);
	void SetVel(float vx, float vy, float vz);
	void Pesaje(void);

public:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	float radio;
	float masa;
	Vector3D posicion;
	Vector3D velocidad;
	Vector3D aceleracion;
};