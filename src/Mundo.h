#pragma once
#include <iostream>
#include"Escenario.h"
#include"Personaje.h"
#include "Caja.h"
#include "Manzana.h"
#include "MonstruoX.h"
#include "MonstruoZ.h"
#include "MonstruoSalto.h"
#include "ListaMonstruos.h"
#include "ListaManzanas.h"


class Mundo
{
	float x_ojo;
	float y_ojo;
	float z_ojo;

	float a,b,c,d,e,f;

	ListaMonstruos monstruos;
	ListaManzanas manzanas;
	Escenario escenario;
	Personaje personaje;
	Personaje personaje2;
	Caja caja1;
	Caja caja2;
	Caja caja3;
	int contador_pos; //PARA SACAR UNAS POSICIONES EN PANTALLA
	int contador_ciclos; //CUENTA LAS VECES QUE SE HA IMPRESO EN PANTALLA PARA LIMPIARLA CADA X VECES
	int contador_manzanas;	//CUENTA MANZANAS COMIDAS
	int contador_monstruos; //CUENTA MONSTRUOS MATADOS

public: 
	void Tecla(unsigned char key);
	void VariasTeclas(bool keystatus[], bool keyspecial[]);  // ESTA ES LA FUNCION QUE USAREMOSS
	void TeclaEspecial(unsigned char key);
	void Inicializa();
	void RotarOjo();
	void SeguirPersonaje();
	void Mueve();
	void Dibuja();
	void verpos_consola(); //NOS DA LA POSICION DEL PERSONAJE
	void funcion_gluLookAt();
	// EN CONSOLA, UTIL PARA COLOCAR MONSTRUOS

};
