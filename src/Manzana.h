#pragma once
#include "Vector3D.h"
#include "glut.h"
class Manzana
{
public:
	Manzana(void);
	~Manzana(void);
	friend class Interaccion;
	void Mueve(float t);
	void Dibuja();
	void SetPos(float x,float y,float z);
	Vector3D getPos(){return posicion;}
private:
	float radio;
	Vector3D posicion;
	int estado; // Entero que nos da el estado de si la manzana esta creciendo, decreciendo, etc
};

