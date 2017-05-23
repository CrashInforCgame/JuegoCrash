#include "Mundo.h"
#include "Escenario.h"
#include "Caja.h"
#include"Interaccion.h"
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
void Mundo::SeguirPersonaje()
{
	x_ojo=personaje.GetPos().x;
	y_ojo=personaje.GetPos().y + 4;
	z_ojo=personaje.GetPos().z + 10;  //Seguimiento cutre de camara
	
}
void Mundo::Dibuja()
{

	//Look at sin seguir al personaje
	/*
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
			*/

	// Lookat siguiendo al personaje
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			personaje.GetPos().x, personaje.GetPos().y, personaje.GetPos().z,      // hacia que punto mira, en 
																				   // este caso al personaje
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	escenario.Dibuja();
	personaje.Dibuja();
	caja1.Dibuja();
	caja2.Dibuja();
	caja3.Dibuja();
	manzana1.Dibuja();
	monstruo1.Dibuja();
}

void Mundo::Mueve()
{
	personaje.Mueve(0.025f); // Con 25 ms funciona bien la gravedad
	manzana1.Mueve(0.025f);
	monstruo1.Mueve(0.025f);
	Interaccion::rebote(personaje,escenario);
	Interaccion::rebotecaja(personaje,caja1);
	Interaccion::rebotecaja(personaje,caja2);
	Interaccion::rebotecaja(personaje,caja3);
	SeguirPersonaje(); // Desactivar para no seguirlo
}

void Mundo::Inicializa()
{
	x_ojo=0;
	y_ojo=10;
	z_ojo=20;
	
	caja1.SetPos(4.5,0.5,-5);
	caja2.SetPos(4.5,1.5,-5);
	caja3.SetPos(0.5,0.5,-2);
	manzana1.SetPos(3,0.5,-2);
	monstruo1.SetPos(8,1,-25);

}


void Mundo::Tecla(unsigned char key)  // NO HACE FALTA USARLA YA
{
	switch(key)
	{
	case 'a':
	case 'A':
		personaje.SetDesplazamientoX(-0.25f);
		break;
	case 'd':
	case'D':
		personaje.SetDesplazamientoX(0.25f);
		break;
	case 'w':
	case 'W':
		personaje.SetDesplazamientoZ(-0.25f);
		break;
	case 's':
	case 'S':
		personaje.SetDesplazamientoZ(0.25f);
		break;
	case 'n':
	case 'N':// Para el salto
	case ' ':
		if(personaje.posicion.y<=personaje.radio)//Solo puede dar un salto si est� en el suelo
		personaje.SetVel(6.0f);//para ello he tenido que poner en public el Vector3D posicion
		break;						//en personaje.h-->Buscar otra alternativa

		// Podriamos hacer una funcion que compruebe que hay colision con cajas o suelo y si la hay que deje saltar
	}
}

void Mundo::TeclaEspecial(unsigned char key)
{

	switch(key)
	{
	case GLUT_KEY_LEFT:
		personaje.SetDesplazamientoX(-1.0f);
		break;
	case GLUT_KEY_RIGHT:
		personaje.SetDesplazamientoX(1.0f);
		break;
	case GLUT_KEY_UP:
		personaje.SetDesplazamientoZ(-1.0f);
		break;
	case GLUT_KEY_DOWN:
		personaje.SetDesplazamientoZ(1.0f);
		break;
	}
}
void Mundo::VariasTeclas(bool keystatus[])  // LA FUNCION IMPORTANTE PARA EL MOVIMIENTO
{
	if(keystatus['a'] || keystatus['A'])personaje.SetDesplazamientoX(-0.075f);
	if(keystatus['d'] || keystatus['D'])personaje.SetDesplazamientoX(0.075f);
	if(keystatus['w'] || keystatus['W'])personaje.SetDesplazamientoZ(-0.075f);
	if(keystatus['s'] || keystatus['S'])personaje.SetDesplazamientoZ(0.075f);
	if(keystatus[' '] || keystatus['n'] || keystatus['N'])
	{
		if(personaje.posicion.y<=personaje.radio)//Solo puede dar un salto si est� en el suelo
		personaje.SetVel(6.0f);		
	}

}
