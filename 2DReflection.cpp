#include<GL/glut.h>
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
void Reflectx(GLfloat v[3][2])
{
    glBegin(GL_LINES);
    glColor3fv(C2);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glEnd();
    for (int i = 0;i < 3;i++)
    {
        v[i][1] = -v[i][1];
    }
    polygunPlot(v, C5);
}
void ReflectY(GLfloat v[3][2])
{
    glBegin(GL_LINES);
    glColor3fv(C2);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 1.0f);
    glEnd();
    for (int i = 0;i < 3;i++)
    {
        v[i][0] = -v[i][0];
    }
    polygunPlot(v, C5);
}
void Reflect_XeqY(GLfloat v[3][2])
{
    glBegin(GL_LINES);
    glColor3fv(C4);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, -1.0f);
    glEnd();
    for (int i = 0;i < 3;i++)
    {
        GLfloat k = v[i][0];
        v[i][0] = v[i][1];
        v[i][1] = k;
    }
    polygunPlot(v, C3);

}
void Reflect_Xeq_mi_Y(GLfloat v[3][2])
{
    glBegin(GL_LINES);
    glColor3fv(C4);

    glEnd();
    for (int i = 0;i < 3;i++)
    {
        GLfloat k = -v[i][0];
        v[i][0] = -v[i][1];
        v[i][1] = k;
    }
    polygunPlot(v, C5);

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
    polygunPlot(v, C5);
    Reflectx(v);
    //Reflect_Xeq_mi_Y(v);



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










