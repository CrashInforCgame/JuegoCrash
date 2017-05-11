#pragma once
#include "Vector3D.h"

class Personaje
{
private:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	//float radio;
	float masa;

public:
	float radio;
	Personaje();
	Vector3D GetPos();
	void Dibuja(void);
	void Mueve(float);
	void SetPos(float x, float y, float z);
	void SetVel(float vx, float vy, float vz);
	void Pesaje(void);

	Vector3D posicion;
	Vector3D velocidad;
	Vector3D aceleracion;

};