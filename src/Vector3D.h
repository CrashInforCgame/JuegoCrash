#pragma once

class Vector3D
{
public:		//atributos
	float x;
	float y;
	float z;
public:		//metodos
	Vector3D(float xv=0.0f,float yv=0.0f, float zv=0.0f); // (1)
	Vector3D operator - (Vector3D &); // (5) resta de vectores
	Vector3D operator + (Vector3D &); // (6) suma de vectores
	float operator *(Vector3D &); // (7) producto escalar
	Vector3D operator *(float); // (8) producto por un escalar 
};
