#include "freeglut.h"
#pragma once

class Toroide
{
private:
	double radioInterior;
	double radioExterior;
	double sides;
	double rings;
	double x;
	double y;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
public:
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void setRadioInterior(double ri);
	void setRadioExterior(double re);
	void setSides(double s);
	void setRings(double rng);
	void setPos(double ix, double iy);
	void dibuja();
	//void mueve();
};