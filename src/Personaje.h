#pragma once
#include "Vector3D.h"

class Personaje
{
public:
	void Dibuja(void);
	void Mueve(float);
	void setVel(float vx, float vy);

private:
	float altura;
	Vector3D posicion;
	Vector3D velocidad;
	Vector3D aceleracion;

	friend class Interaccion;
};
