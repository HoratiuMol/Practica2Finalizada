#include <iostream> // para usar cout
#include <cstring>  // para las funciones de C
#include <afx.h>    // para usar las MFC: CStringA
#include <afxdlgs.h>
#include "esfera.h"
#include "toroide.h"
#include "plano.h"
#include "freeglut.h"

#pragma warning(disable : 4996) // deshabilita el error por unsafe

using namespace std;

// Espacio de nombres para las variables globales
namespace Global {
    Esfera esfera;
    Esfera esfera2;
	Toroide toroide;
    Plano plano;

    // Variables globales para la cámara
    float theta = 0.0f;          // Ángulo de la órbita de la cámara
    float radio_camara = 20.0f;  // Distancia de la cámara al origen (escena)
    float altura_camara = 10.0f; // Altura de la cámara sobre el plano XY
}

// Declaraciones de funciones
void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
void Camara();

int main(int argc, char* argv[]) {
    // Inicializar el gestor de ventanas GLUT y crear la ventana
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("MiJuego");

    // Habilitar luces y definir perspectiva
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

    // Registrar los callbacks
    glutDisplayFunc(OnDraw);
    glutTimerFunc(25, OnTimer, 0); // le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
    glutKeyboardFunc(OnKeyboardDown);

    // Inicialización de los datos de la simulación
    Global::esfera.setColor(200, 0, 0);
    Global::esfera.setRadio(1);
    Global::esfera.setPos(2, 0);
    Global::esfera2.setColor(0, 200, 0);
    Global::esfera2.setRadio(1);
    Global::esfera2.setPos(3, 0);

	// Inicialización del toroide
	Global::toroide.setColor(0, 0, 200);
	Global::toroide.setRadioInterior(1);
	Global::toroide.setRadioExterior(5);
	Global::toroide.setSides(20);
	Global::toroide.setRings(20);
	Global::toroide.setPos(0, 0);

    //inicializamos Plano
    Global::plano.setColor(200, 255, 255);
    //Global::plano.setPos(0, 0);

    // Pasarle el control a FREEGLUT, que llamará a los callbacks
    //siempre llamar los callbacks antes de glutMainLoop
    glutMainLoop();

    return 0;
}

void OnDraw(void) {
    // Borrado de la pantalla
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Para definir el punto de vista
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Invocamos cámara
    Camara();

    // Llamadas a los métodos de Esfera
    Global::esfera.dibuja();
    Global::esfera2.dibuja();
	Global::toroide.dibuja();
    Global::plano.dibuja();
    // Llamada a método de Esfera
    Global::esfera2.mueve();

    // No borrar esta línea ni poner nada después
    glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x, int y) {
    if (key == 'r')
        Global::esfera.setColor(255, 0, 0);
    if (key == 'g')
        Global::esfera.setColor(0, 255, 0);
    if (key == 'b')
        Global::esfera.setColor(0, 0, 255);

    glutPostRedisplay();
}

void OnTimer(int value) {
    Global::theta += 0.02f; // Incrementamos el ángulo para hacer la rotación
    if (Global::theta > 2 * 3.14) {
        Global::theta -= 2 * 3.14; // Reseteamos el ángulo si pasa de 360°
    }
    // Poner aquí el código de animación

    glutTimerFunc(25, OnTimer, 0);
    glutPostRedisplay();
}

void Camara() {
    // Calculamos la posición de la cámara en función del ángulo theta
    float x = Global::radio_camara * cos(Global::theta);
    float z = Global::radio_camara * sin(Global::theta);
    float y = Global::altura_camara; // Altura fija de la cámara

    // Definimos la vista con gluLookAt
    gluLookAt(x, y, z,   // Posición de la cámara (orbita alrededor del origen)
        0.0, 0.0, 0.0, // Punto al que mira (centro de la escena)
        0.0, 1.0, 0.0); // Vector "up" (hacia arriba en el eje Y)
}
