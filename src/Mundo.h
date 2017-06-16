#pragma once
#include"Escenario.h"
#include"Personaje.h"
#include "Caja.h"
#include "Manzana.h"
#include "MonstruoX.h"
#include "MonstruoZ.h"
#include "MonstruoSalto.h"
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
	MonstruoX monstruo1;
	MonstruoZ monstruo2;;
	MonstruoSalto monstruo3;
	Manzana manzana1;
public: 
	void Tecla(unsigned char key);
	void VariasTeclas(bool keystatus[], bool keyspecial[]);  // ESTA ES LA FUNCION QUE USAREMOSS
	void TeclaEspecial(unsigned char key);
	void Inicializa();
	void RotarOjo();
	void SeguirPersonaje();
	void Mueve();
	void Dibuja();
};
