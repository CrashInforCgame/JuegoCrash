#pragma once
#include"Escenario.h"
#include"Personaje.h"
#include "Caja.h"
#include "Manzana.h"

class Mundo
{
	float x_ojo;
	float y_ojo;
	float z_ojo;
	Escenario escenario;
	Personaje personaje;
	Personaje personaje2;
	Caja caja1;
	Caja caja2;
	Caja caja3;
	Manzana manzana1;
public: 
	void Tecla(unsigned char key);
	void TeclaEspecial(unsigned char key);
	void Inicializa();
	void RotarOjo();
	void SeguirPersonaje();
	void Mueve();
	void Dibuja();
};
