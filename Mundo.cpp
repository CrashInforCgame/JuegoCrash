#include "Mundo.h"
#include "Escenario.h"
#include "Caja.h"
#include"Interaccion.h"
#include "glut.h"
#include <math.h>


void inicializaMonstruos(ListaMonstruos &monstruos)  //USAREMOS ESTA FUNCION PARA INICIALIZAR LOS MONSTRUOS
	// DE ESTA MANERA ADEMAS CUANDO NOS MATEN PODREMOS VOLVER A GENERAR TODOS LOS MONSTRUOS DE NUEVO UNA VEZ DESTRUIDA LA LISTA
{
		//Inicializando monstruos para lista
	
	float y1xz=(new MonstruoZ)->getRadio()-0.3; // LA ALTURA A LA QUE ESTARAN LOS MONSTRUOS X Y Z EN EL PRIMER PLANO
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

}

/*void Mundo::RotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}*/
void Mundo::SeguirPersonaje()
{
	x_ojo=personaje.GetPos().x + 0;
	y_ojo=personaje.GetPos().y + 4;
	z_ojo=personaje.GetPos().z + 10;  //Seguimiento cutre de camara
}
	/*x_ojo=0;
	y_ojo=4;
	z_ojo=personaje.GetPos().z + 10;*/

	/*if(Interaccion::Comprobacion1(escenario))
	{
		if(Interaccion::Comprobacion2(personaje,escenario))
		{
			if((x_ojo+1)<personaje.GetPos().x)
			{
				x_ojo = 2*(personaje.GetPos().x-a); //EL 2 es el factor de giro de la cámara que hay que regularlo
				//z_ojo = c - 1.5*(personaje.GetPos().x-5); 
				return;
			}
			else
			{
				x_ojo = personaje.GetPos().x;
				return;
			}
		}
	}
// principal, más largo que ancho el suelo
	{
		x_ojo = 0;
		y_ojo = 4;
		z_ojo = personaje.GetPos().z + 10;
		a = x_ojo;
		b = y_ojo;
		c = z_ojo;
		return;
	}
	
}
/*void Mundo::funcion_gluLookAt() //La del ojo es la de arriba y aquí gestionamos hacia donde apunta
{
	if(Interaccion::Comprobacion1(escenario))
	{
		if(Interaccion::Comprobacion2(personaje,escenario))
		{
			if((x_ojo+1)<personaje.GetPos().x)
			{
				d=personaje.GetPos().x*0.4;
				gluLookAt(x_ojo, y_ojo, z_ojo, 
				   d, e, f,
					0.0, 1.0, 0.0);    
				return;
			}
			else
			{
				d=personaje.GetPos().x;
				f=personaje.GetPos().z;
				gluLookAt(x_ojo, y_ojo, z_ojo, 
				   d, e, f,
					0.0, 1.0, 0.0);    
				return;
			}
		}
	}
 // principal, más largo que ancho el suelo
	{
		d=personaje.GetPos().x*0.4;
		e=0;
		f=personaje.GetPos().z;
		gluLookAt(x_ojo, y_ojo, z_ojo, 
		    d, e, f,
			0.0, 1.0, 0.0);   
		return;     
	}
}*/
void Mundo::Dibuja()
{

	//Look at sin seguir al personaje
	/*
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
			*/
	//funcion_gluLookAt();
	// Lookat siguiendo al personaje
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			personaje.GetPos().x, personaje.GetPos().y, personaje.GetPos().z,      // hacia que punto mira, en 
																				   // este caso al personaje
		   //personaje.GetPos().x*0.4, 0, personaje.GetPos().z,
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) */

	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	escenario.Dibuja();
	personaje.Dibuja();
	caja1.Dibuja();
	caja2.Dibuja();
	caja3.Dibuja();
	monstruos.Dibuja();

	manzanas.dibuja();
}

void Mundo::Mueve()
{
	personaje.Mueve(0.025f); // Con 25 ms funciona bien la gravedad

	monstruos.Mueve(0.025f);
	if(monstruos.choque(personaje))
	{
		std::cout<< "HAS MUERTO" << std::endl;	//AQUI HABRIA QUE PONER QUE PASA SI TE DA
		monstruos.destruirContenido();
		inicializaMonstruos(monstruos);
		personaje.SetPos(0,0,0);
		contador_monstruos=0; // AL RESETEARSE LOS MONSTRUOS TAMBIEN LO HACE LA CUENTA
	}
	if(personaje.estado_ataque == 1) //AQUI EL PERSONAJE REVISA LAS INTERACCIONES DE ATAQUE PARA MATAR MONSTRUOS
	{
			Monstruo *aux = monstruos.ataque(personaje);
			if(aux!=0) 
			{
				monstruos.eliminar(aux);
				contador_monstruos++;
			}
	}
	personaje.ataca(); // AQUI PERSONAJE SE ENCARGA DE SUS ESTADOS DE ATAQUE
	manzanas.choque(personaje);
	manzanas.mueve(0.025f);
	Manzana *aux=manzanas.choque(personaje); 
	if(!aux==0)
	{
		manzanas.eliminar(aux);
		contador_manzanas++;	// AUMENTA LA CUENTA DE MANZANAS
	}
	Interaccion::rebote(personaje,escenario);
	Interaccion::rebotecaja(personaje,caja1);
	Interaccion::rebotecaja(personaje,caja2);
	Interaccion::rebotecaja(personaje,caja3);
	Interaccion::apoyo(personaje, escenario);
	SeguirPersonaje(); // Desactivar para no seguirlo
	//funcion_gluLookAt();
	verpos_consola(); //ESTA FUNCION NOS VA DANDO LA POSICION EN CONSOLA, UTIL PARA LUEGO PONER COSAS
}

void Mundo::verpos_consola()
{
	if(contador_pos%80 == 0) { // AQUI SE AJUSTA CADA CUANTO TIEMPO QUEREMOS QUE SE ACTUALICE LA CONSOLA. MAS O MENOS 40 ES CADA 1 SEGUNDO, POR TANTO 80 ES CADA 2

		if(contador_ciclos>0)  
		{
			system("cls");
			contador_ciclos=0;
		} 

		std::cout << "Posicion personaje [X Y Z]:               "<< personaje.posicion.x << "       " << personaje.posicion.y << "      " << personaje.posicion.z << std::endl;
		std::cout << "Manzanas:       "<< contador_manzanas << std::endl;
		std::cout << "Monstruos muertos:         " << contador_monstruos << std::endl;
		std::cout << "Quedan " << monstruos.getNumero() << std::endl;
		std::cout<< c << std::endl;
		contador_pos = 0;	
		contador_ciclos++;
	}
	contador_pos++;
}

void Mundo::Inicializa()
{
	x_ojo=0;
	y_ojo=10;
	z_ojo=20;

	a=x_ojo;
	b=y_ojo;
	c=z_ojo;

	inicializaMonstruos(monstruos);

	Manzana *n1=new Manzana;
	n1->SetPos(4,3,-20);
	manzanas.agregar(n1);
	Manzana *n2=new Manzana;
	n2->SetPos(-2,0.3,-7);
	manzanas.agregar(n2);

	manzanas+=new Manzana(3,-10); // AL USAR NEW MANZANA AHORA LOS PARAMETROS SON: (X,Z,Y=0.3)

	caja1.SetPos(4.5,0.5,-5);
	caja2.SetPos(4.5,1.5,-5);
	caja3.SetPos(0.5,0.5,-2);


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
			if(personaje.estado_ataque==0) personaje.estado_ataque=1;
		}

}


//
