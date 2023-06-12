#include <bits/stdc++.h>
#include <GL/glut.h>

//  define the application area size
#define XMAX 600
#define YMAX 600

using namespace std;


//  defining the clipping window
int xl = 200, yl = 200, xh = 400, yh = 400;
int flag = 0;
float u1, v1, u2, v2;

void initialize(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
}

//  structue for storing the region code
struct code
{
    int t, b, r, l;
};


//  getting the region code of the given co-ordinates
code getCode(int x, int y)
{
    code c = {0, 0, 0, 0};

    if (x < xl)
        c.l = 1;

    if (x > xh)
        c.r = 1;

    if (y < yl)
        c.b = 1;

    if (y > yh)
        c.t = 1;

    return c;
}

void displayPoint(float x, float y)
{
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void simpleLine(int x1, int y1, int x2, int y2)
{
    float x, y, dx, dy, step, Xin, Yin;

    dx = x2 - x1;
    dy = y2 - y1;

    step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    Xin = dx / step;
    Yin = dy / step;

    x = x1;
    y = y1;

    displayPoint(x, y);
    for (int i = 0; i <= step; i++)
    {
        x += Xin;
        y += Yin;
        displayPoint(x, y);
    }
    glFlush();
}


//  drawing the window
void draw_window()
{
    glColor3f(0, 0, 0);
    simpleLine(xl, yl, xh, yl);
    simpleLine(xh, yl, xh, yh);
    simpleLine(xh, yh, xl, yh);
    simpleLine(xl, yh, xl, yl);
    glFlush();
}

void mouseListener(int button, int state, int x, int y)
{
    glColor3f(0, 0, 0);
    if (state == GLUT_DOWN && flag == 0)
    {
        u1 = x;
        v1 = YMAX - y;
        flag = 1;
    }
    else if (state == GLUT_DOWN && flag == 1)
    {
        u2 = x;
        v2 = YMAX - y;
        flag = 2;
        simpleLine(u1, v1, u2, v2);
    }
    cout << "The mouse click co-ordinates are ";
    cout << x << y << endl;
}

void cohen()
{
    code c1, c2, c;
    int xi, yi, flag;
    float m;

    m = (v2 - v1) / (u2 - u1);

    c1 = getCode(u1, v1);
    c2 = getCode(u2, v2);

    while (1)
    {

        //  if both endpoints are inside the window, then simply draw the line
        if (c1.l == 0 && c2.l == 0 && c1.r == 0 && c2.r == 0 && c1.t == 0 && c2.t == 0 && c1.b == 0 && c2.b == 0)
        {
            break;
        }

        //  if both endpoints are outside the window, then don't draw the line
        else if (((c1.l && c2.l) || (c1.r && c2.r) || (c1.t && c2.t) || (c1.b && c2.b)) != 0)
        {
            u1 = v1 = u2 = v2 = 0;
            break;
        }

        //  if line is partially inside, then there are four possibilities
        else
        {
            if (c1.l == 1 || c2.l == 1)
            {
                xi = xl;
                yi = v1 + m * (xl - u1);

                if (c1.l == 1)
                    flag = 0;

                else
                    flag = 1;
            }

            else if (c1.r == 1 || c2.r == 1)
            {
                xi = xh;
                yi = v1 + m * (xh - u1);

                if (c1.r == 1)
                    flag = 0;

                else
                    flag = 1;
            }

            else if (c1.b == 1 || c2.b == 1)
            {
                xi = u1 + (1 / m) * (yl - v1);
                yi = yl;

                if (c1.b == 1)
                    flag = 0;

                else
                    flag = 1;
            }

            else if (c1.t == 1 || c2.t == 1)
            {
                xi = u1 + (1 / m) * (yh - v1);
                yi = yh;

                if (c1.t == 1)
                    flag = 0;

                else
                    flag = 1;
            }

            c = getCode(xi, yi);

            if (flag == 0)
            {
                u1 = xi;
                v1 = yi;
                c1 = c;
            }
            else if (flag == 1)
            {
                u2 = xi;
                v2 = yi;
                c2 = c;
            }
        }   //  end else
    }   //  end while

    draw_window();
    simpleLine(u1, v1, u2, v2);
}

void keyboard(char unsigned key, int x, int y)
{
    if (key == 'c')
    {
        initialize();
        cohen();
    }

    if (key == 'r')
    {
        initialize();
        draw_window();
        flag = 0;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(XMAX, YMAX);
    glutCreateWindow("Line Clipping");

    gluOrtho2D(0, XMAX, 0, YMAX);
    initialize();
    glutDisplayFunc(draw_window);
    glutMouseFunc(mouseListener);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
