#pragma once
#include "Monstruo.h"
#include "glut.h"
class MonstruoSalto : public Monstruo
{
public:
	MonstruoSalto(void);
	~MonstruoSalto(void);
	void Mueve(float);
	void SetPos(float x, float y, float z);
private:
	float contador; // para contar tiempo en reposo para luego saltar
};

