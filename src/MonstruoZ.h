#pragma once
#include "Monstruo.h"
#include "glut.h"
class MonstruoZ : public Monstruo
{
public:
	MonstruoZ();
	virtual ~MonstruoZ(void);
	void Mueve(float);
	void SetPos(float x, float y, float z);
private:
};

