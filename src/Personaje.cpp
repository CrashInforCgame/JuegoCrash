#include "Personaje.h"
#include "glut.h"
#include "Vector3D.h"

Personaje::Personaje(void)
{
}
void Personaje::SetRadio(float r)
{
	radio=r;
}

void Personaje::SetPos(float ix,float iy,float iz)
{
	posicion.x=ix;
	posicion.y=iy;
	posicion.z=iz;
}

void Personaje::SetColor( unsigned char r,unsigned char v, unsigned char a)
{
	rojo=r;
	verde=v;
	azul=a;
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
	glTranslatef(posicion.x,posicion.y,0);
	glutSolidSphere(radio,20,20);
	glTranslatef(-posicion.x,-posicion.y,0);
}

void Personaje::Mueve(float t)
{
	posicion = posicion+velocidad*t+aceleracion*(0.5f*t*t);
	velocidad = velocidad+aceleracion*t;
}
void Personaje::Pesaje(void)
{
	masa=4*3,14*radio*radio;
}