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
	void SetVel(float vy);
	void SetDesplazamientoX(float px);
	void SetDesplazamientoZ(float pz);
	void Pesaje(void);

	Vector3D posicion;
	Vector3D velocidad;
	Vector3D aceleracion;

	friend class Interaccion;

};
