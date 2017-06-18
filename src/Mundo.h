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
	ListaMonstruos monstruos;
	ListaManzanas manzanas;
	Escenario escenario;
	Personaje personaje;
	Personaje personaje2;
	Caja caja1;
	Caja caja2;
	Caja caja3;
	Manzana manzana1;
	int contador; //PARA SACAR UNAS POSICIONES EN PANTALLA

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
	// EN CONSOLA, UTIL PARA COLOCAR MONSTRUOS
};
