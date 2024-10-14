#include "freeglut-3.2.1/include/GL/freeglut.h"
#include <iostream>
#include <math.h>
using namespace std;

float x1 = 0.5, x2 = -0.5, x3 = -0.5, x4 = 0.5, Y1 = 0.5, y2 = 0.5, y3 = -0.5,
      y4 = -0.5;

void scalex(float x1, float Y1, float x2, float y2, float x3, float y3,
            float x4, float y4, float scale) {
  x1 *= scale;
  x2 *= scale;
  x3 *= scale;
  x4 *= scale;
  glBegin(GL_LINE_LOOP);
  glVertex2f(x1, Y1);
  glVertex2f(x2, y2);
  glVertex2f(x3, y3);
  glVertex2f(x4, y4);
  glEnd();
}

void rotate(float x1, float Y1, float x2, float y2, float x3, float y3,
            float x4, float y4, float angle) {
  scalex(x1, Y1, x2, y2, x3, y3, x4, y4, 0.5);
  x1 *= 0.5;
  x2 *= 0.5;
  x3 *= 0.5;
  x4 *= 0.5;
  angle = angle * 3.14159 / 180;
  float x1_n = x1 * cos(angle) - Y1 * sin(angle);
  float Y1_n = x1 * sin(angle) + Y1 * cos(angle);

  float x2_n = x2 * cos(angle) - y2 * sin(angle);
  float y2_n = x2 * sin(angle) + y2 * cos(angle);

  float x3_n = x3 * cos(angle) - y3 * sin(angle);
  float y3_n = x3 * sin(angle) + y3 * cos(angle);

  float x4_n = x4 * cos(angle) - y4 * sin(angle);
  float y4_n = x4 * sin(angle) + y4 * cos(angle);

  glBegin(GL_LINE_LOOP);
  glVertex2f(x1_n, Y1_n);
  glVertex2f(x2_n, y2_n);
  glVertex2f(x3_n, y3_n);
  glVertex2f(x4_n, y4_n);
  glEnd();
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINE_LOOP);
  glVertex2f(x1, Y1);
  glVertex2f(x2, y2);
  glVertex2f(x3, y3);
  glVertex2f(x4, y4);
  glEnd();
  rotate(x1, Y1, x2, y2, x3, y3, x4, y4, -90);
  glFlush();
}

void init(void) {
  glPointSize(4);
  glClearColor(0, 0, 0, 1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-5, 5, -5, 5);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Problem Statement 5");

  glutDisplayFunc(display);
  init();
  glutMainLoop();
  return 0;
}

// p5:
// Apply following sequence of transformations in c++:
// to a unit square centred at origin, scale the image x-direction to 1/2 as
// large. Rotate clockwise 90 about origin
