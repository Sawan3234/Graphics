#include<windows.h>
#include<GL/glut.h>
void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
    //plotting the axes
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 1.0f);//blue
    //vertex for x axis
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    //vertex for y axis
    glVertex2f(0.0f, 1.0f);
    glVertex2f(0.0f, -1.0f);

    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); //initialize glut
    glutCreateWindow("Simple Square"); //position the window's initial top-left corner
    glutInitWindowSize(320, 320); //set window's initial width and height
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}