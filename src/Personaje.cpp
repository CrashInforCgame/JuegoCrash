#include "Personaje.h"
#include "glut.h"
#include "Vector3D.h"

Personaje::Personaje(void)
{
	radio=1.0f;
	aceleracion.x=0;
	aceleracion.y=0;
	aceleracion.z=0;
	velocidad.x=0;
	velocidad.y=0;
	velocidad.z=0;
	rojo=0;
	verde=0;
	azul=255;
	posicion.x=0;
	posicion.y=0;
	posicion.z=0;
}


void Personaje::SetPos(float ix, float iy, float iz)
{
	posicion.x=ix;
	posicion.y=iy;
	posicion.z=iz;
}

void Personaje::SetVel(float vx, float vy, float vz)
{
	velocidad.x=vx;
	velocidad.y=vy;
	velocidad.z=vz;
}

void Personaje::Dibuja()
{
	glColor3ub(rojo,verde,azul);//azul oscura
	glTranslatef(posicion.x,posicion.y,posicion.z);
	glutSolidSphere(radio,20,20);
	glTranslatef(-posicion.x,-posicion.y,-posicion.z);
}

void Personaje::Mueve(float t)
{
	posicion = posicion+velocidad*t+aceleracion*(0.5f*t*t);
	velocidad = velocidad+aceleracion*t;
	sprite.loop();
}
void Personaje::Pesaje(void)
{
	masa=4*3,14*radio*radio;
}