#include "Interaccion.h"
#include "Escenario.h"
#include "math.h"


Interaccion::Interaccion(void)
{
}

Interaccion::~Interaccion(void)
{

}


bool Interaccion::rebotecaja(Personaje &h, Caja c)
{
	float xmin=c.posicion.x-c.lado/2-h.radio;
	float xmax=c.posicion.x+c.lado/2+h.radio;
	float zmin=c.posicion.z-c.lado/2-h.radio;
	float zmax=c.posicion.z+c.lado/2+h.radio;
	float ymax=c.posicion.y+c.lado/2+h.radio;
	
	float x=h.posicion.x;
	float y=h.posicion.y;
	float z=h.posicion.z;


	if((z>zmin && z<zmax) && (x>xmin && x<xmax))
		{
			if(ymax>=h.posicion.y)  // En caso de estar a la altura de la caja, ya estando en los limites establecidos de x y z
				// si no no se activan colisiones
			{
				if((c.posicion.x)>(x+h.radio))h.posicion.x=xmin;
				if((c.posicion.x)<(x-h.radio))h.posicion.x=xmax;
				if((c.posicion.z)>(z+h.radio))h.posicion.z=zmin;
				if((c.posicion.z)<(z-h.radio))h.posicion.z=zmax;
				if((c.posicion.y)<(y-h.radio))h.posicion.y=ymax; // Para que caiga encima de la caja si esta entre los limites y su y encima de ella
				// Como antes se activan todos los limitadores de posicion nunca va a meterse el personaje dentro de una caja por error
				return true;
			}
		}
	return false;
	
}
void Interaccion::rebote(Personaje &h, Suelo s) //FUNCION PLANTEADA PARA TODO
{
		float xmax=s.limite4.x;
		float xmin=s.limite1.x;
		//float yplano=s.Ypuntoplano(h); // Esta funcion nos da la Y DEL PLANO EN ESA COORDENADA para que no caiga
		//float ypersonaje=yplano+h.radio; //PARA QUE SE VEA EL RADIO ENTERO LUEGO
		float ypersonaje=s.limite2.y+h.radio;
	// float ymin=s.limite1.y; // ESTO FUNCIONA SIEMPRE QUE SEAN PLANOS CON Y CONSTANTE SOLO
		float zmax=s.limite2.z;
		float zmin=s.limite1.z;
		if(h.posicion.x>xmax)h.posicion.x=xmax;
		if(h.posicion.x<xmin)h.posicion.x=xmin;
	// if(h.posicion.y<ymin)h.posicion.x=ymin; //PARA LA Y
		if(h.posicion.z>zmax)h.posicion.z=zmax;
		if(h.posicion.z<zmin)h.posicion.z=zmin;
		//if(ypersonaje>h.posicion.y)h.posicion.y=ypersonaje;  //PARA QUE NO SE CAIGA DEL PLANO Y SE VEA LA ESFERA ENTERA
		if((h.posicion.y-h.radio<s.limite2.y))h.posicion.y=h.radio+s.limite2.y;
		// YPERSONAJE está cogido como la y del plano + el radio
		//if(ypersonaje>h.posicion.y)h.posicion.z=s.limite1.z;
}

void Interaccion::apoyo(Personaje &h, Escenario &e)// se puede optimizar con un contenedor
{
	switch(e.plano)
	{
	case 1:
		h.apoyo=e.suelo1.limite2.y;
		break;
	case 2:
		h.apoyo=e.suelo3.limite2.y;
		break;
	case 3:
		h.apoyo=e.suelo3.limite2.y;
		break;
	case 4:
		h.apoyo=e.suelo4.limite2.y;
		break;
	case 5:
		h.apoyo=e.suelo5.limite2.y;
		break;
	case 6:
		h.apoyo=e.suelo6.limite2.y;
		break;
	case 7:
		h.apoyo=e.suelo7.limite2.y;
		break;
	case 8:
		h.apoyo=e.suelo8.limite2.y;
		break;
	case 9:
		h.apoyo=e.suelo9.limite2.y;
		break;
	case 11:
		h.apoyo=e.suelo11.limite2.y;
		break;
	case 12:
		h.apoyo=e.suelo12.limite2.y;
		break;
	case 13:
		h.apoyo=e.suelo13.limite2.y;
		break;
	case 14:
		h.apoyo=e.suelo14.limite2.y;
		break;
	case 15:
		h.apoyo=e.suelo15.limite2.y;
		break;
	case 16:
		h.apoyo=e.suelo16.limite2.y;
		break;
	}
}


bool Interaccion::localizacion(Personaje &h, Suelo s)
{
	if((s.limite1.x)<=h.posicion.x && (s.limite4.x)>=h.posicion.x 
		&& (s.limite1.z)<=h.posicion.z && (s.limite2.z)>=h.posicion.z)
		return 1;
	return 0;
}
bool Interaccion::localizacion2(Personaje &h, Suelo s) //Para planos con altura
{
	if((s.limite1.x)<=h.posicion.x && (s.limite4.x)>=h.posicion.x 
		&& (s.limite1.z)<=h.posicion.z && (s.limite2.z)>=h.posicion.z
		&& (s.limite1.y+h.radio)<h.posicion.y)//No poner menor o igual, solo menor
		return 1;
	return 0;
}


bool Interaccion::localizacion2(Personaje &h,Escenario &e)
{
	if(Interaccion::localizacion(h,e.suelo1)){e.plano=1;return 0;}
	if(Interaccion::localizacion(h,e.suelo2)){e.plano=2;return 0;}
	if(Interaccion::localizacion(h,e.suelo3)){e.plano=3;return 0;}
	if(Interaccion::localizacion(h,e.suelo4)){e.plano=4;return 0;}
	if(Interaccion::localizacion(h,e.suelo5)){e.plano=5;return 0;}
	if(Interaccion::localizacion2(h,e.suelo6)){e.plano=6;return 0;}
	if(Interaccion::localizacion2(h,e.suelo7)){e.plano=7;return 0;}
	if(Interaccion::localizacion2(h,e.suelo8)){e.plano=8;return 0;}
	if(Interaccion::localizacion2(h,e.suelo9)){e.plano=9;return 0;}
	if(Interaccion::localizacion2(h,e.suelo10)){e.plano=10;return 0;}
	if(Interaccion::localizacion2(h,e.suelo11)){e.plano=11;return 0;}
	if(Interaccion::localizacion2(h,e.suelo12)){e.plano=12;return 0;}
	if(Interaccion::localizacion2(h,e.suelo13)){e.plano=13;return 0;}
	if(Interaccion::localizacion2(h,e.suelo14)){e.plano=14;return 0;}
	if(Interaccion::localizacion2(h,e.suelo15)){e.plano=15;return 0;}
	if(Interaccion::localizacion2(h,e.suelo16)){e.plano=16;return 0;}
	return 1;
}
void Interaccion::rebote(Personaje &h, Escenario &e)
{
	if(Interaccion::localizacion2(h,e))
	{
		switch(e.plano)
		{
		case 1:
			Interaccion::rebote(h,e.suelo1);
			break;
		case 2:
			Interaccion::rebote(h,e.suelo2);
			break;
		case 3:
			Interaccion::rebote(h,e.suelo3);
			break;
		case 4:
			Interaccion::rebote(h,e.suelo4);
			break;
		case 5:
			Interaccion::rebote(h,e.suelo5);
			break;
		case 6:
			Interaccion::rebote(h,e.suelo6);
			break;
		case 7:
			Interaccion::rebote(h,e.suelo7);
			break;
		case 8:
			Interaccion::rebote(h,e.suelo8);
			break;
		case 9:
			Interaccion::rebote(h,e.suelo9);
			break;
		case 10:
			Interaccion::rebote(h,e.suelo10);
			break;
		case 11:
			Interaccion::rebote(h,e.suelo11);
			break;
		case 12:
			Interaccion::rebote(h,e.suelo12);
			break;
		case 13:
			Interaccion::rebote(h,e.suelo13);
			break;
		case 14:
			Interaccion::rebote(h,e.suelo14);
			break;
		case 15:
			Interaccion::rebote(h,e.suelo15);
			break;
		case 16:
			Interaccion::rebote(h,e.suelo16);
			break;
		}
	}
}

bool Interaccion::choque(Personaje &h, Monstruo &m)
{
	float distancia=(h.posicion-m.posicion).modulo(); 

	if(distancia < h.getRadio()+m.getRadio()) 
		{
			return true;
		}
	return false;

}

bool Interaccion::choque(Personaje &h, Manzana &n)
{
	float distancia=(h.posicion-n.posicion).modulo(); 

	if(distancia < h.getRadio()+n.getRadio()) return true;
	return false;

}
bool Interaccion::ataque(Personaje &h, Monstruo &m) // es como el 
	//choque pero esta se activara a una distancia inferior
	// y dentro del keypressed
{
	float distancia=(h.posicion-m.posicion).modulo(); 
	if(distancia < h.getRadio()+m.getRadio()+0.16) 
	{
			return true;
	}
	return false;
}