// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

using namespace std;

void dibujarTriangulos() {
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);

	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, 0);
	glVertex3f(1, -1, 0);

	//138,43,226
	glColor3f(138.0f / 255.0f, 43.0f / 255.0f, 226.0f / 255.0f);
	glVertex3f(0, 0, 0);
	glColor3f(1.0f, 0.5f, 0.1f);
	glVertex3f(1, 1, 0);
	glColor3f(0.1f, 0.6f, 0.34f);
	glVertex3f(1, 0, 0);

	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(1, 1, 0);

	glEnd();
}

void dibujarPuntos() {
	glBegin(GL_POINTS);
	glColor3f(1, 1, 1);
	glVertex3f(0.5f, 0.1f, 0.0f);
	glColor3f(0, 0, 0);
	glVertex3f(0.55f, 0.1f, 0.0f);
	glEnd();
}

void dibujarLineas() {
	glBegin(GL_LINES);

	glColor3f(1, 1, 1);
	glVertex3f(0, 0, 0);
	glColor3f(0,0,0);
	glVertex3f(0, 0.4, 0);

	glVertex3f(0.2, 0.5, 0);
	glVertex3f(-0.2, 0.5, 0);

	glEnd();
}

void dibujarLineaContinua() {
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, -0.2, 0);
	glVertex3f(0.3, -0.2, 0);
	glVertex3f(0.3, 0, 0);
	glVertex3f(0, 0, 0);
	glEnd();
}

void dibujarTrianguloContinuo() {
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1, 1, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(-0.2, -0.2, 0);
	glVertex3f(0.2, -0.2, 0);
	glColor3f(0, 0, 0);
	glVertex3f(0.2, -0.4, 0);
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(0.4, -0.4, 0);
	glEnd();
}

void dibujar() {
	//dibujarTriangulos();
	//dibujarPuntos();
	//dibujarLineas();
	//dibujarLineaContinua();
	dibujarTrianguloContinuo();
}

void actualizar() {

}

int main()
{
	//Declaramos apuntador de ventana
	GLFWwindow *window;
	
	//Si no se pudo iniciar glfw
	//terminamos ejcución
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW
	//entonces inicializamos la ventana
	window =
		glfwCreateWindow(1024, 768, "Ventana", 
			NULL, NULL);
	//Si no podemos iniciar la ventana
	//Entonces terminamos ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Establecemos el contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido  el contexto
	//Activamos funciones modernas
	glewExperimental = true;
	GLenum errorGlew = glewInit();
	if (errorGlew != GLEW_OK) {
		cout << 
			glewGetErrorString(errorGlew);
	}

	const GLubyte *versionGL =
		glGetString(GL_VERSION);
	cout << "Version OpenGL: "
		<< versionGL;

	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Esablecer region de dibujo
		glViewport(0, 0, 1024, 768);
		//Establece el color de borrado
		glClearColor(1, 0.2, 0.5, 1);
		//Borramos
		glClear(
			GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		actualizar();

		//Cambiar los buffers
		glfwSwapBuffers(window);
		//Reconocer si hay entradas
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}

