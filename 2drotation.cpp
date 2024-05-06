#include<GL/glut.h>
#include<math.h>
GLfloat C1[3] = { 1.0f,0.0f,0.0f };
GLfloat C2[3] = { 0.0f,0.0f,1.0f };
GLfloat C3[3] = { 0.0f,1.0f,0.0f };
GLfloat C4[3] = { 1.0f,1.0f,1.0f };
GLfloat C5[3] = { 0.2f,0.75f,0.75f };

void polygunPlot(GLfloat vertices[3][2], GLfloat pic_color[3])
{
    glBegin(GL_LINE_LOOP);
    glColor3fv(pic_color);
    for (int i = 0;i < 3;i++)
    {
        glVertex2fv(vertices[i]);
    }
    glEnd();
}
void Rotate2D(GLfloat v[3][2], GLfloat angle)
{
    angle *= (22 / 7) / 180.0f; // Convert angle to radians

    for (int i = 0; i < 3; i++)
    {
        GLfloat x = v[i][0];
        GLfloat y = v[i][1];
        v[i][0] = x * cos(angle) - y * sin(angle);
        v[i][1] = x * sin(angle) + y * cos(angle);
    }
    polygunPlot(v, C3);
}
void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    GLfloat v[3][2] = {
        {0.3f,0.7f},
        {0.1f,0.4f},
        {0.3f,0.4f},
    };
    glBegin(GL_LINES);
    glColor3fv(C4);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    //points for Y axis
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 1.0f);
    glEnd();
    polygunPlot(v, C4);
    //reflectx(v);
    Rotate2D(v, 180.0f);


    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(150, 150);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(520, 520);
    glutCreateWindow("OpenGl Reflection");
    glutDisplayFunc(display);
    glutMainLoop();
    return  0;
}










