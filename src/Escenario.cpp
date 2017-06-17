#include "Escenario.h"
#include "Suelo.h"
#include "glut.h"

Escenario::Escenario()
{
	plano=1;

	suelo1.setColor(140,50,0);
	suelo1.SetPos(-5.0F,0,-30.0F,
		-5.0F,0,5.0F,
		5.0F,0,5.0F,
		5.0F,0,-30.0F);

	suelo2.setColor(140,50,0);
	suelo2.SetPos(5.0F,0,-30.0F,
		5.0F,0,-20.0F,
		25.0F,0,-20.0F,
		25.0F,0,-30.0F);

	suelo3.setColor(140,50,0);
	suelo3.SetPos(15.0F,0,-50.0F
		,15.0F,0,-30.0F,
		25.0F,0,-30.0F,
		25.0F,0,-50.0F);

	suelo4.setColor(140,50,0);
	suelo4.SetPos(5.0F,0,-50.0F,
		5.0F,0,-40.0F,
		15.0F,0,-40.0F,
		15.0F,0,-50.0F);

	suelo5.setColor(140,50,0);
	suelo5.SetPos(5.0F,0,-70.0F,
		5.0F,0,-50.0F,
		15.0F,0,-50.0F,
		15.0F,0,-70.0F);

	suelo6.setColor(140,50,0);
	suelo6.SetPos(5.0F,3,-100.0F,
		5.0F,3,-70.0F,
		15.0F,3,-70.0F,
		15.0F,3,-100.0F);

	suelo7.setColor(140,50,0);
	suelo7.SetPos(5.0F,3,-100.0F,
		5.0F,3,-85.0F,
		50.0F,3,-85.0F,
		50.0F,3,-100.0F);

	suelo8.setColor(140,50,0);
	suelo8.SetPos(50.0F,6,-100.0F,
		50.0F,6,-85.0F,
		58.0F,6,-85.0F,
		58.0F,6,-100.0F);

	suelo9.setColor(140,50,0);
	suelo9.SetPos(58.0F,9.5,-100.0F,
		58.0F,9.5,-85.0F,
		74.0F,9.5,-85.0F,
		74.0F,9.5,-100.0F);
	
	suelo10.setColor(140,50,0);
	suelo10.SetPos(74.0F,8,-100.0F,
		74.0F,8,-85.0F,
		80.0F,8,-85.0F,
		80.0F,8,-100.0F);
	
	suelo11.setColor(140,50,0);
	suelo11.SetPos(80.0F,6,-100.0F,
		80.0F,6,-85.0F,
		105.0F,6,-85.0F,
		105.0F,6,-100.0F);

	suelo12.setColor(140,50,0);
	suelo12.SetPos(90.0F,6,-85.0F,
		90.0F,6,-78.0F,
		105.0F,6,-78.0F,
		105.0F,6,-85.0F);

	suelo13.setColor(140,50,0);
	suelo13.SetPos(90.0F,2,-78.0F,
		90.0F,2,-68.0F,
		105.0F,2,-68.0F,
		105.0F,2,-78.0F);


	suelo14.setColor(140,50,0);
	suelo14.SetPos(90.0F,0,-68.0F,
		90.0F,0,-45.0F,
		105.0F,0,-45.0F,
		105.0F,0,-68.0F);

	suelo15.setColor(140,50,0);
	suelo15.SetPos(90.0F,0,-45.0F,
		90.0F,0,-35.0F,
		160.0F,0,-35.0F,
		160.0F,0,-45.0F);

	suelo16.setColor(140,50,0);
	suelo16.SetPos(140.0F,0,-128.0F,
		140.0F,0,-55.0F,
		160.0F,0,-55.0F,
		160.0F,0,-128.0F);


}

void Escenario::Dibuja()
{
	suelo1.Dibuja();
	suelo2.Dibuja();
	suelo3.Dibuja();
	suelo4.Dibuja();
	suelo5.Dibuja();
	suelo6.Dibuja();
	suelo7.Dibuja();
	suelo8.Dibuja();
	suelo9.Dibuja();
	suelo10.Dibuja();
	suelo11.Dibuja();
	suelo12.Dibuja();
	suelo13.Dibuja();
	suelo14.Dibuja();
	suelo15.Dibuja();
	suelo16.Dibuja();
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

(-5.0F,0,-30.0F,-5.0F,0,5.0F,5.0F,0,5.0F,5.0F,0,-30.0F);

		SUELO 2

Suelo2.limite1.x=5.0F;
Suelo2.limite1.z=-30.0F;

Suelo2.limite2.x=5.0F;
Suelo2.limite2.z=-20.0F;

Suelo2.limite4.x=25.0F;
Suelo2.limite4.z=-30.0F;

Suelo2.limite3.x=25.0F;
Suelo2.limite3.z=-20.0F;

(5.0F,0,-30.0F,5.0F,0,-20.0F,25.0F,0,-20.0F,25.0F,0,-30.0F);

		SUELO 3

Suelo3.limite1.x=15.0F;
Suelo3.limite1.z=-50.0F;

Suelo3.limite2.x=15.0F;
Suelo3.limite2.z=-30.0F;

Suelo3.limite4.x=25.0F;
Suelo3.limite4.z=-50.0F;

Suelo3.limite3.x=25.0F;
Suelo3.limite3.z=-30.0F;

(15.0F,0,-50.0F,15.0F,0,-30.0F,25.0F,0,-30.0F,25.0F,0,-50.0F);

		SUELO 4

Suelo4.limite1.x=5.0F;
Suelo4.limite1.z=-50.0F;

Suelo4.limite2.x=5.0F;
Suelo4.limite2.z=-40.0F;

Suelo4.limite4.x=15.0F;
Suelo4.limite4.z=-50.0F;

Suelo4.limite3.x=15.0F;
Suelo4.limite3.z=-40.0F;

(5.0F,0,-50.0F,5.0F,0,-40.0F,15.0F,0,-40.0F,15.0F,0,-50.0F);

		SUELO 5

Suelo5.limite1.x=5.0F;
Suelo5.limite1.z=-70.0F;

Suelo5.limite2.x=5.0F;
Suelo5.limite2.z=-50.0F;

Suelo5.limite4.x=15.0F;
Suelo5.limite4.z=-70.0F;

Suelo5.limite3.x=15.0F;
Suelo5.limite3.z=-50.0F;

(5.0F,0,-70.0F,5.0F,0,-50.0F,15.0F,0,-50.0F,15.0F,0,-70.0F);

*/