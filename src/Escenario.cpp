#include "Escenario.h"
#include "glut.h"

Escenario::Escenario()
{
	suelo1.setColor(0,100,0);
	suelo1.SetPos(-5.0F,0,-30.0F,-5.0F,0,5.0F,5.0F,0,-30.0F,5.0F,0,5.0F);

	suelo2.setColor(0,100,0);
	suelo2.SetPos(5.0F,0,-30.0F,5.0F,0,-20.0F,25.0F,0,-30.0F,25.0F,0,20.0F);

	suelo3.setColor(0,100,0);
	suelo3.SetPos(15.0F,0,-50.0F,15.0F,0,-30.0F,25.0F,0,-50.0F,25.0F,0,-30.0F);

	suelo4.setColor(0,100,0);
	suelo4.SetPos(5.0F,0,-50.0F,5.0F,0,-40.0F,15.0F,0,-50.0F,15.0F,0,-40.0F);

	suelo5.setColor(0,100,0);
	suelo5.SetPos(5.0F,0,-70.0F,5.0F,0,-50.0F,15.0F,0,-70.0F,15.0F,0,-50.0F);
}

void Escenario::Dibuja()
{
	suelo1.Dibuja();
	suelo2.Dibuja();
	suelo3.Dibuja();
	suelo4.Dibuja();
	suelo5.Dibuja();
}

/*
		SUELO 1

Suelo1.limite1.x=-5.0F;
Suelo1.limite1.z=-30.0F;

Suelo1.limite2.x=-5.0F;
Suelo1.limite2.z=5.0F;

Suelo1.limite3.x=5.0F;
Suelo1.limite3.z=-30.0F;

Suelo1.limite4.x=5.0F;
Suelo1.limite4.z=5.0F;

(-5.0F,0,-30.0F,-5.0F,0,5.0F,5.0F,0,-30.0F,5.0F,0,5.0F);

		SUELO 2

Suelo2.limite1.x=5.0F;
Suelo2.limite1.z=-30.0F;

Suelo2.limite2.x=5.0F;
Suelo2.limite2.z=-20.0F;

Suelo2.limite3.x=25.0F;
Suelo2.limite3.z=-30.0F;

Suelo2.limite4.x=25.0F;
Suelo2.limite4.z=-20.0F;

(5.0F,0,-30.0F,5.0F,0,-20.0F,25.0F,0,-30.0F,25.0F,0,20.0F);

		SUELO 3

Suelo3.limite1.x=15.0F;
Suelo3.limite1.z=-50.0F;

Suelo3.limite2.x=15.0F;
Suelo3.limite2.z=-30.0F;

Suelo3.limite3.x=25.0F;
Suelo3.limite3.z=-50.0F;

Suelo3.limite4.x=25.0F;
Suelo3.limite4.z=-30.0F;

(15.0F,0,-50.0F,15.0F,0,-30.0F,25.0F,0,-50.0F,25.0F,0,-30.0F);

		SUELO 4

Suelo4.limite1.x=5.0F;
Suelo4.limite1.z=-50.0F;

Suelo4.limite2.x=5.0F;
Suelo4.limite2.z=-40.0F;

Suelo4.limite3.x=15.0F;
Suelo4.limite3.z=-50.0F;

Suelo4.limite4.x=15.0F;
Suelo4.limite4.z=-40.0F;

(5.0F,0,-50.0F,5.0F,0,-40.0F,15.0F,0,-50.0F,15.0F,0,-40.0F);

		SUELO 5

Suelo5.limite1.x=5.0F;
Suelo5.limite1.z=-70.0F;

Suelo5.limite2.x=5.0F;
Suelo5.limite2.z=-50.0F;

Suelo5.limite3.x=15.0F;
Suelo5.limite3.z=-70.0F;

Suelo5.limite4.x=15.0F;
Suelo5.limite4.z=-50.0F;

(5.0F,0,-70.0F,5.0F,0,-50.0F,15.0F,0,-70.0F,15.0F,0,-50.0F);

*/