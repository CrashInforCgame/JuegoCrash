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
	monstruos.Dibuja();

	manzanas.dibuja();
}

void Mundo::Mueve()
{
	personaje.Mueve(0.025f); // Con 25 ms funciona bien la gravedad
	manzana1.Mueve(0.025f);

	monstruos.Mueve(0.025f);
	monstruos.choque(personaje);
	if(personaje.atacando == 1)
	{
			Monstruo *aux = monstruos.ataque(personaje);
			if(aux!=0) monstruos.eliminar(aux);
	}
	manzanas.choque(personaje);
	manzanas.mueve(0.025f);

	Interaccion::rebote(personaje,escenario);
	Interaccion::rebotecaja(personaje,caja1);
	Interaccion::rebotecaja(personaje,caja2);
	Interaccion::rebotecaja(personaje,caja3);
	Interaccion::apoyo(personaje, escenario);
	SeguirPersonaje(); // Desactivar para no seguirlo
	verpos_consola(); //ESTA FUNCION NOS VA DANDO LA POSICION EN CONSOLA, UTIL PARA LUEGO PONER COSAS
}

void Mundo::verpos_consola()
{
	if(contador%40 == 0) {
		std::cout << personaje.posicion.x << " " << personaje.posicion.y << " " << personaje.posicion.z << std::endl;
		contador = 0;	
	}
	contador++;

}
void Mundo::Inicializa()
{
	x_ojo=0;
	y_ojo=10;
	z_ojo=20;
	//Inicializando monstruos para lista
	
	float y1xz=(new MonstruoZ)->getRadio(); // LA ALTURA A LA QUE ESTARAN LOS MONSTRUOS X Y Z EN EL PRIMER PLANO
	float y2xz=y1xz+3; //ALTURA 2o plano
	//Monstruos que se mueven en X
	monstruos+=new MonstruoX(0,y1xz,-17);
	monstruos+=new MonstruoX(0,y1xz,-8.5);
	monstruos+=new MonstruoX(20,y1xz,-35);
	monstruos+=new MonstruoX(10,y1xz,-50);
	monstruos+=new MonstruoX(10,y1xz,-54);

	//Monstruos que se mueven en Z
	monstruos+=new MonstruoZ(10,y1xz,-25);
	monstruos+=new MonstruoZ(15,y1xz,-25);
	monstruos+=new MonstruoZ(15,y1xz,-45);
	monstruos+=new MonstruoZ(9,y2xz,-76);
	monstruos+=new MonstruoZ(12.65,y2xz,-83);
	//Monstruos que saltan						//HACEMOS QUE CAIGAN DESDE ALTURAS DIFERENTES PARA DESINCRONIZAR LOS SALTOS
	monstruos+=new MonstruoSalto(15,y1xz+1,-26);
	monstruos+=new MonstruoSalto(-2,y1xz,-25);
	monstruos+=new MonstruoSalto(12.3,y1xz+3,-48);
	monstruos+=new MonstruoSalto(9,y1xz,-44);
	monstruos+=new MonstruoSalto(8,y1xz+5,-59);

	Manzana *n1=new Manzana;
	n1->SetPos(4,3,-20);
	manzanas.agregar(n1);

	caja1.SetPos(4.5,0.5,-5);
	caja2.SetPos(4.5,1.5,-5);
	caja3.SetPos(0.5,0.5,-2);
	manzana1.SetPos(3,0.5,-2);


}


/*void Mundo::Tecla(unsigned char key)  // NO HACE FALTA USARLA YA
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
		if(personaje.posicion.y<=personaje.radio)//Solo puede dar un salto si está en el suelo
		personaje.SetVel(6.0f);//para ello he tenido que poner en public el Vector3D posicion
		break;						//en personaje.h-->Buscar otra alternativa

		// Podriamos hacer una funcion que compruebe que hay colision con cajas o suelo y si la hay que deje saltar
	}
}*/

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
void Mundo::VariasTeclas(bool keystatus[], bool keyspecial[])  // LA FUNCION IMPORTANTE PARA EL MOVIMIENTO
{
	if(keystatus['a'] || keystatus['A'] || keyspecial[GLUT_KEY_LEFT])personaje.SetDesplazamientoX(-0.075f);
	if(keystatus['d'] || keystatus['D'] || keyspecial[GLUT_KEY_RIGHT])personaje.SetDesplazamientoX(0.075f);
	if(keystatus['w'] || keystatus['W'] || keyspecial[GLUT_KEY_UP])personaje.SetDesplazamientoZ(-0.075f);
	if(keystatus['s'] || keystatus['S']|| keyspecial[GLUT_KEY_DOWN])personaje.SetDesplazamientoZ(0.075f);
	if(keystatus[' '] || keystatus['n'] || keystatus['N'])
	{
		if(personaje.posicion.y<=(personaje.apoyo+personaje.radio))//Solo puede dar un salto si está en el suelo
		//if(personaje.posicion.y<=personaje.radio)//Solo puede dar un salto si está en el suelo
		personaje.SetVel(6.0f);		
	}

	if(keystatus['p']||keystatus['P'])
		{
			personaje.atacando=1;
		}
	else
		personaje.atacando=0;

}
