#include <GL/glut.h>
#include <cmath>

// Circle
void circle(float x, float y, float radius, float glTranslatefX, float glTranslatefY, float glTranslatefZ, int red,
            int green, int blue)
{
    double p = 0.0;
    double q = 0.0;
    double angle = 1.0;

    glPushMatrix();
    glTranslatef(glTranslatefX, glTranslatefY, glTranslatefZ);
    glColor3f(red, green, blue);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p, q);
    while (true)
    {
        if (angle <= 360)
        {
            p = x + sin(angle) * radius;
            q = y + cos(angle) * radius;
            glVertex2f(p, q);
        }
        else
        {
            break;
        }
        angle += 0.1;
    }
    glEnd();
    glPopMatrix();
}

// Display
void display()
{
    // Middle Circle
    circle(0.0, 0.0, 0.25,
           0, 0, 0,
           1, 1, 1);

    // Up Circle
    circle(0.0, 0.0, 0.25,
           0, 0.5, 0,
           1, 0, 0);

    // Down Circle
    circle(0.0, 0.0, 0.25,
           0, -0.5, 0,
           0, 1, 0);

    // Up Left Circle
    circle(0.0, 0.0, 0.25,
           -0.425, 0.25, 0,
           0, 0, 1);

    // Up Right Circle
    circle(0.0, 0.0, 0.25,
           0.425, 0.25, 0,
           1, 1, 0);

    // Down Left Circle
    circle(0.0, 0.0, 0.25,
           -0.425, -0.25, 0,
           1, 0, 1);

    // Right Right Circle
    circle(0.0, 0.0, 0.25,
           0.425, -0.25, 0,
           0, 1, 1);

    glFlush(); // Render Now
}

// Initialization
void initialize()
{
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

// Main
int main(int argc, char *argv[])
{
    glutInit(&argc, argv); // Initialize GLUT
    int x = 512, y = 512;  // x and y value
    glutInitWindowPosition(
        (int)(glutGet(GLUT_SCREEN_WIDTH) - x) / 2,
        (int)(glutGet(GLUT_SCREEN_HEIGHT) - y) / 2); // Position the window's center
    glutInitWindowSize(x, y);                        // Set the window's initial width & height
    glutCreateWindow("Flower Shape Circle");         // Create a window with the given title
    initialize();                                    // Initializing
    glutDisplayFunc(display);                        // Register display callback handler for window re-paint
    glutMainLoop();                                  // Enter the event-processing loop
    return 0;
}

// End