#include "Mundo.h"
#include "Escenario.h"
#include "glut.h"
#include <math.h>

void Mundo::RotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	escenario.Dibuja();
	personaje.Dibuja();
}

void Mundo::Mueve()
{
	personaje.Mueve(0.025f);
}

void Mundo::Inicializa()
{
	x_ojo=0;
	y_ojo=10;
	z_ojo=20;
	
}

void Mundo::Tecla(unsigned char key)
{
	switch(key)
	{
	case 'a':
	case 'A':
		personaje.SetVel(-3.0f,0,0);
		break;
	case 'd':
	case'D':
		personaje.SetVel(3.0f,0,0);
		break;
	case 'w':
	case 'W':
		personaje.SetVel(0,0,-3.0f);
		break;
	case 's':
	case 'S':
		personaje.SetVel(0,0,3.0f);
		break;
	}
}
void Mundo::TeclaEspecial(unsigned char key)
{

	switch(key)
	{
	case GLUT_KEY_LEFT:
		personaje.SetVel(-3.0f,0,0);
		break;
	case GLUT_KEY_RIGHT:
		personaje.SetVel(3.0f,0,0);
		break;
	case GLUT_KEY_UP:
		personaje.SetVel(0,0,-3.0f);
		break;
	case GLUT_KEY_DOWN:
		personaje.SetVel(0,0,3.0f);
		break;
	}
}

