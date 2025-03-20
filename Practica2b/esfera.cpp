#include "freeglut.h"
#include "esfera.h"

void Esfera::setColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}
void Esfera::setRadio(double r)
{
	if (r < 0.1F)
		r = 0.1F;
	radio = r;
}
void Esfera::setPos(double ix, double iy)
{
	x = ix;
	y = iy;
}
void Esfera::dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslated(x, y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslated(-x, -y, 0);
}
void Esfera::mueve()
{
	radio += 0.01;
	if (radio > 2)
		radio = 0.5;
}