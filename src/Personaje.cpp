#include "Personaje.h"
#include "glut.h"
#include "Vector3D.h"

Personaje::Personaje(void)
{
	radio=1.0f;
	aceleracion.x=0;
	aceleracion.y=-2.0f;
	aceleracion.z=0;
	velocidad.x=0;
	velocidad.y=0;
	velocidad.z=0;
	rojo=0;
	verde=0;
	azul=255;
	posicion.x=0;
	posicion.y=4+radio;
	posicion.z=0;
}


void Personaje::SetPos(float ix, float iy, float iz)
{
	posicion.x=ix;
	posicion.y=iy;
	posicion.z=iz;
}

void Personaje::SetVel(float vy)
{
	velocidad.y=vy;

}
void Personaje::SetDesplazamiento(float px, float pz)
{
	posicion.x = posicion.x + px;
	posicion.z = posicion.z + pz;
}

void Personaje::Dibuja()
{
	glColor3ub(rojo,verde,azul);//azul oscura
	glTranslatef(posicion.x,posicion.y,posicion.z);
	glutSolidSphere(radio,20,20);
	glTranslatef(-posicion.x,-posicion.y,-posicion.z);
}

void Personaje::Mueve(float t)//Esta parte irá en la clase movimientos y habra que poner esto de forma más
							// simplificada como en lo comentado abajo
{

	posicion.y = posicion.y+velocidad.y*t+aceleracion.y*(0.5f*t*t);
	if(posicion.y<=radio)
	{
		velocidad.y=0;
		aceleracion.y=0;
	}
	else
	{
		velocidad.y = velocidad.y+aceleracion.y*t;
		aceleracion.y=-2;
	}
	/*posicion = posicion+velocidad*t+aceleracion*(0.5f*t*t);
	velocidad = velocidad+aceleracion*t;
	if(posicion.y==0)
		velocidad.y=0;*/
//	sprite.loop();
}
void Personaje::Pesaje(void)
{
	masa=4*3,14*radio*radio;
}
Vector3D Personaje::GetPos(){return posicion;}
