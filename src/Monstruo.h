#pragma once
#include "Vector3D.h"
#include "Personaje.h"
#include "glut.h"

class Monstruo
{
public:
	friend class Interaccion;
	Monstruo(void);
	virtual ~Monstruo(void);
	Vector3D GetPos();
	void Dibuja(void);
	void Mueve(float);
	void SetPos(float x, float y, float z);
private:
	float radio;
	Vector3D posicion;
	float limitestrayectoria[2];
	Vector3D velocidad;
	Vector3D aceleracion;
	int estado;
	};

