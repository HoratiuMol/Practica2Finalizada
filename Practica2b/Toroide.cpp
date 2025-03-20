#include "freeglut.h"
#include "toroide.h"

void Toroide::setColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}
void Toroide::setRadioInterior(double ri)
{
	radioInterior = ri;
}
void Toroide::setRadioExterior(double re)
{
	radioExterior = re;
}
void Toroide::setSides(double s)
{
	sides = s;
}
void Toroide::setPos(double ix, double iy)
{
	x = ix;
	y = iy;
}
void Toroide::setRings(double rng)
{
	rings = rng;
}
void Toroide::dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslated(x, y, 0);
	glutSolidTorus(radioInterior, radioExterior, sides, rings);
	glTranslated(-x, -y ,0);
}
/*void Toroide::mueve()
{
	el código del movimiento del toroide irá aqui
}*/