#include "freeglut.h"
#include "plano.h"

void Plano::setColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}
/*void Plano::setPos(double x, double y)
{
	glTranslatef(x, y, 0);
	glBegin(GL_QUADS);
	glVertex3f(-5, 0, -5);
	glVertex3f(5, 0, -5);
	glVertex3f(5, 0, 5);
	glVertex3f(-5, 0, 5);
	glEnd();
	glTranslatef(x, y, 0);
}*/
void Plano::dibuja()
{
	//glColor3ub(e.rojo, e.verde, e.azul);
	glPushMatrix();  // Guardamos la matriz actual
	glTranslatef(x, y, 0); // Trasladamos el plano a la posición deseada

	glBegin(GL_QUADS);
	glColor3ub(rojo, verde, azul);

	// Definir las coordenadas del plano (puedes ajustar los valores según el tamaño deseado)
	glVertex3f(-5.0f, 0.0f, -5.0f);
	glVertex3f(5.0f, 0.0f, -5.0f);
	glVertex3f(5.0f, 0.0f, 5.0f);
	glVertex3f(-5.0f, 0.0f, 5.0f);

	glEnd();
	glPopMatrix();  // Restauramos la matriz original
	/*glColor3ub(255, 0, 0);
	glColor3ub(255, 255, 0);
	glColor3ub(255, 255, 255);
	glColor3ub(0, 255, 255);*/
}
/*void Plano::mueve()
{
	aqui va el codigo para mover el plano
}*/