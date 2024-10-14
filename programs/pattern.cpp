#include "freeglut-3.2.1/include/GL/freeglut.h"
#include <iostream>
#include <math.h>
#include <unistd.h>
using namespace std;

void circle(float r, float h = 0, float k = 0) {
  glBegin(GL_POINTS);
  for (int i = 0; i < 360; i++) {
    glVertex2f(h + r * cos(i), k + r * sin(i));
  }
  glEnd();
}

float r1 = 1000, r2 = 2000, v1 = 8, v2 = 13, a1 = 0, a2 = 0;

void display(void) {
  a1 += v1 * 3.14159 / 180;
  a2 += v2 * 3.14159 / 180;

  glBegin(GL_LINES);
  glColor4f(1, 1, 0, 0.5);
  glVertex2f(r1 * cos(a1), r1 * sin(a1));
  glColor4f(1, 0, 1, 0.5);
  glVertex2f(r2 * cos(a2), r2 * sin(a2));
  glEnd();
  glutSwapBuffers();
}

void timer(int iunused) {
  glutPostRedisplay();
  glutTimerFunc(100, timer, 0);
}

void init(void) {
  glPointSize(0.5);
  glClearColor(0, 0, 0, 1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-5000, 5000, -5000, 5000);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0, 0, 1);
  circle(r1);
  glColor3f(1, 0, 0);
  circle(r2);
  glColor3f(1, 1, 1);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Problem Statement 5");

  glutDisplayFunc(display);
  timer(0);
  init();
  glutMainLoop();
  return 0;
}
