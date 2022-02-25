#include<windows.h>
#include <GL/glut.h>
#include <math.h>
#include<stdio.h>

#define PI 3.1416
#define window_height 600 //Window Height and Width has been taken as a macro so that we can customize easily.
#define window_width 600

float tgt_x=0;
float tgt_y=0;
static float tx	=  0.0;
static float ty	=  0.0;

float minus_x=-25.0;
float plus_x=25.0;
float minus_y= -25.0;
float plus_y= 25.0;

float u= 0.0;  // Controlling the Translation of the car..in this case autonomous movement
//float u= rand();
float v = 0.0;

float bee_autox=0.0;
float bee_autoy=0.0;


float bee_x1=0.0;   //to translate bee1
float bee_y1=0.0;
float bee_x2=0.0;  //to translate bee2
float bee_y2=0.0;

float x=1.0;
float y=1.0;
int state = 1; //For bouncing the Car Object
float spin = 0.0;//initial degree for spinning, as initially still, so spin is set to 0

int drawaxes;
void drawAxes()
{
    if(drawaxes==1)
    {
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex3f(plus_x,0,0);
        glVertex3f(minus_x,0,0);

        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(0,plus_y,0);
        glVertex3f(0, minus_y,0);

        glEnd();
    }
}

void quads(float x1, float x2, float x3, float x4, float x5, float x6, float x7, float x8)
{
     glBegin(GL_QUADS);
     glVertex2f(x1, x2);
     glVertex2f(x3, x4);
     glVertex2f(x5, x6);
     glVertex2f(x7, x8);
     glEnd();
}


void circle(float radius_x, float radius_y)
{
    int i=0;
    float angle = 0.0;

    glBegin(GL_POLYGON);

    for(i = 0; i < 100; i++)
    {
        angle = 2 * PI * i / 100;
        glVertex2f (cos(angle) * radius_x, sin(angle) * radius_y);
        //glVertex2f (cos(angle) * radius_x+5, sin(angle) * radius_y);
    }

    glEnd();
}

void init(void)
{
    drawaxes=1;
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glOrtho(minus_x, plus_x, minus_y,plus_y, -25.0,25.0);

}

void sky()
{
    glBegin(GL_QUADS);
    //glColor3f(0.93f, 0.53f, 0.18f);

    glColor3f(1.0f, 0.55f, 0.0f);
    glVertex3f(-25.0, 5.0, 0.0);

    //glColor3f(0.97f, 0.91f, 0.81f);
     //glColor3f(0.83f, 0.95f, 0.92f);
      glColor3f(1.0f, 0.60f, 0.20f);
    glVertex3f(25.0, 5.0, 0.0);

    //glColor3f(0.11f, 0.67f, 0.84f);
    glColor3f(0.54f, 0.81f, 0.94f);
     //glColor3f(0.94f, 0.87f, 0.73f);

    glVertex3f(25.0, 25.0, 0.0);
    glVertex3f(-25.0, 25.0, 0.0);
    glEnd();
}


void ground()
{
    glBegin(GL_POLYGON);

     glColor3f(0.13f, 0.55f, 0.13f);
     glVertex3f(25.0f, 5.0f, 0.0f);

     glColor3f(0.0f, 0.29f, 0.29f);
     glVertex3f(25.0f, -25.0f, 0.0f);
     glVertex3f(-25.0f, -25.0f, 0.0f);

     glColor3f(0.0f, 0.34f, 0.25f);
     glVertex3f(-25.0f, 5.0f, 0.0f);

    glEnd();
}


void tree1()
{
    glColor3f(0.47,0.27,0.23);
    quads(25.0,12.0, 22.0,12.0,  22.0,-25.0, 25.0,-25.0  );
    quads(22.0,10.0, 23.0,12.5,  10.0,17.0, 9.0,15.0  );

    glColor3f(0.0,0.42,0.24);
    quads(25.0,25.0, 11.0,25.0,  11.0,14.0, 25.0,14.0  );

    glPushMatrix();
    glTranslatef(23.0,12.0,0);
    circle(6,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9.0,20.0,0);
    circle(6,6);
    glPopMatrix();


}



void tree2()
{
     glColor3f(0.47,0.27,0.23);
    quads(-25.0, 9.0,  -22.0, 9.0,  -22.0, -25.0, -25.0,-25.0);


     glColor3f(0.0,0.42,0.24);
    quads(-25.0, 12.0,  -15.0, 12.0,  -15.0,  8.0, -25.0,8.0);


    glPushMatrix();
    glTranslatef(-20.0,5.0,0);
    circle(5,5);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-12.0,10.0,0);
    circle(5,5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-19.0, 15.0,0);
    circle(7,5);
    glPopMatrix();


}



void honey_comb()
{
    glColor3f(1.0,0.60,0.20); ///1
    glPushMatrix();
    glTranslatef(10.0,13.0,0);
    circle(1.5,2.0);
    glPopMatrix();

    glColor3f(1.0,0.60,0.20);///2
    glPushMatrix();
    glTranslatef(12.0,12.0,0);
    circle(1.5,2.0);
    glPopMatrix();


    glColor3f(1.0,0.830,0.0); ///3
    glPushMatrix();
    glTranslatef(14.0,11.0,0);
    circle(1.5,2.0);
    glPopMatrix();

     glColor3f(1.0,0.60,0.20); ///4
    glPushMatrix();
    glTranslatef(16.0,11.0,0);
    circle(1.5,2.0);
    glPopMatrix();

   glColor3f(1.0,0.830,0.0); ///5
    glPushMatrix();
    glTranslatef(18.0,11.0,0);
    circle(1.5,2.0);
    glPopMatrix();

  glColor3f(1.0,0.60,0.20); ///6
    glPushMatrix();
    glTranslatef(20.0,11.0,0);
   circle(1.5,2.0);
    glPopMatrix();

     glColor3f(1.0,0.60,0.20); ///1
    glPushMatrix();
    glTranslatef(10.0,10.0,0);
    circle(1.5, 2.0);
    glPopMatrix();

     glColor3f(1.0,0.830,0.0);///2
    glPushMatrix();
    glTranslatef(12.0,9.0,0);
    circle(1.5, 2.0);
    glPopMatrix();

  glColor3f(1.0,0.60,0.20);///3
    glPushMatrix();
    glTranslatef(14.0,9.0,0);
    circle(1.5,2.0);
    glPopMatrix();

   glColor3f(1.0,0.830,0.0);///4
    glPushMatrix();
    glTranslatef(16.0,9.0,0);
    circle(1.5,2.0);
    glPopMatrix();


     glColor3f(1.0,0.60,0.20); ///5
    glPushMatrix();
    glTranslatef(18.0,9.0,0);
    circle(1.5, 2.0);
    glPopMatrix();

    glColor3f(1.0,0.60,0.20); ///6
    glPushMatrix();
    glTranslatef(20.0,9.0,0);
    circle(1.5, 2.0);
    glPopMatrix();

    glColor3f(1.0,0.830,0.0); ///1
    glPushMatrix();
    glTranslatef(11.0,7.0,0);
    circle(1.5, 2.0);
    glPopMatrix();

    glColor3f(1.0,0.60,0.20); ///2
    glPushMatrix();
    glTranslatef(13.0,7.0,0);
    circle(1.5, 2.0);
    glPopMatrix();


  glColor3f(1.0,0.830,0.0);///3
    glPushMatrix();
    glTranslatef(15.0,7.0,0);
    circle(1.5, 2.0);
    glPopMatrix();

   glColor3f(1.0,0.60,0.20);///4
    glPushMatrix();
    glTranslatef(17.0,7.0,0);
    circle(1.5, 2.0);
    glPopMatrix();


    glColor3f(1.0,0.830,0.0); ///5
    glPushMatrix();
    glTranslatef(19.0,7.0,0);
    circle(1.5, 2.0);
    glPopMatrix();

    glColor3f(1.0,0.60,0.20); ///1
    glPushMatrix();
    glTranslatef(12.0,5.0,0);
    circle(1.5, 2.0);
    glPopMatrix();

   glColor3f(1.0,0.830,0.0);///2
    glPushMatrix();
    glTranslatef(14.0,5.0,0);
    circle(1.5, 2.0);
    glPopMatrix();

     glColor3f(1.0,0.60,0.20); ///3
    glPushMatrix();
     glTranslatef(16.0,5.0,0);
    circle(1.5, 2.0);
    glPopMatrix();

     glColor3f(1.0,0.60,0.20); ///4
    glPushMatrix();
     glTranslatef(18.0,5.0,0);
    circle(1.5, 2.0);
    glPopMatrix();

   glColor3f(1.0,0.60,0.20); ///1
    glPushMatrix();
     glTranslatef(13.0,3.0,0);
    circle(1.5, 2.0);
    glPopMatrix();

   glColor3f(1.0,0.60,0.20); ///2
    glPushMatrix();
     glTranslatef(15.0,3.0,0);
    circle(1.5, 2.0);
    glPopMatrix();

   glColor3f(1.0,0.830,0.0);///3
    glPushMatrix();
     glTranslatef(17.0,3.0,0);
    circle(1.5, 2.0);
    glPopMatrix();




}

void bird()
{
    ///tail circle
    glPushMatrix();
    glTranslatef(6.0,5.70,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(2.5,1.85);
    glPopMatrix();
    ///front circle
    glPushMatrix();
    glTranslatef(11.33,5.75,0);
    glColor3f(0.23, 0.18, 0.18);
    circle(1.75,1.55);
    glPopMatrix();

    ///middle circle
    glPushMatrix();
    glTranslatef(9.00,5.75,0);
   glColor3f(1.0, 0.75, 0.0);
    circle(1.75,1.75);
    glPopMatrix();

    /// eye left
     glPushMatrix();
    glTranslatef(11.50,6.50,0);
    glColor3f(0.33, 0.38, 0.44);
    circle(.5,.5);
    glPopMatrix();

    ///eye right
    glPushMatrix();
    glTranslatef(11.50,4.80,0);
    glColor3f(0.33, 0.38, 0.44);
    circle(.5,.5);
    glPopMatrix();


        ///head circle line up
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(12.50, 6.08);
    glVertex2f(13.42, 9.42);
    glEnd();


        ///head circle line down
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(12.50, 5.33);
    glVertex2f(13.87, 3.00);
    glEnd();



    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(10.42, 7.08);
    glVertex2f(11.00,8.45);
    glEnd();



    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(10.42, 4.58);
    glVertex2f(11.03,3.25);
    glEnd();


    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(8.42, 7.25);
    glVertex2f(7.00,9.58);
    glEnd();


     glLineWidth(8);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(8.42, 4.33);
    glVertex2f(7.00,1.50);
    glEnd();




}

void queen_bee()
{
    glPushMatrix(); //bee1
    glTranslatef(19.0,11.0,0);
    glRotatef(180, 0, 0, 1);
    bird();
    glPopMatrix();

     glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(7.0, 5.5);
    glVertex2f(5.0, 5.5);
    glEnd();

    glBegin(GL_POLYGON);

     glColor3f(1.0, 0.0, 0.0);
    glVertex2f(8.5, 7.0);
    glVertex2f(9.0, 8.0);
    glVertex2f(10.0, 5.0);
    glVertex2f(9.0, 2.0);
    glVertex2f(8.5, 3.0);


    glEnd();

}

float beer =0;
//float bee2r =0;

void bee()
{
    glPushMatrix();
    glTranslatef(bee_autox,bee_autoy,0);
    glRotatef(spin, 0, 0, 1);
       glPushMatrix();
       glTranslatef(bee_x1, bee_y1, 0);
            glPushMatrix(); //bee1
             glRotatef(beer, 0, 0, 1);
            glTranslatef(-2.0,-10.0,0);
            bird();
            glPopMatrix();
      glPopMatrix();

       glPushMatrix();
       glTranslatef(bee_x2, bee_y2, 0);

            glPushMatrix(); //bee2
            glRotatef(beer, 0, 0, 1);
            glTranslatef(-12.0,-15.0,0);
            bird();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();


}

void flower_root()
{
     ///flower root start

    glPushMatrix();
    glTranslatef(11.50,-5.00,0);
    glColor3f(0.89, 0.26, 0.20);  ///1
    circle(1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(12.0,-6.0,0);
    glColor3f(0.89, 0.26, 0.20);  ///2
    circle(1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(11.5, -7.0,0);
    glColor3f(0.89, 0.26, 0.20);  ///3
    circle(1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9.0, -7.0,0);
    glColor3f(0.89, 0.26, 0.20);  ///4
    circle(1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(8.5, -6.0,0);
    glColor3f(0.89, 0.26, 0.20);  ///5
    circle(1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9.25, -5.0,0);
    glColor3f(0.89, 0.26, 0.20);  ///5
    circle(1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10.33, -4.5,0);
    glColor3f(0.89, 0.26, 0.20);  ///5
    circle(1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10.00, -7.5,0);
    glColor3f(0.89, 0.26, 0.20);  ///5
    circle(1.0,1.0);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(10.25,-6.08,0);  ///6
    glColor3f(1.00, 0.70, 0.00);
    circle(1.0,1.0);
    glPopMatrix();


    ///flower root end
}



void beehouse()
{
    glColor3f(0.82, 0.41, 0.12);
    quads(-12.0, -13.50,  0.33, -13.5,   0.33, -20.58,   -12.0, -20.58 );
    glColor3f(1.0, 0.65, 0.0);
    quads(-12.0, -20.58, 0.33, -20.58, 2.0, -23.5, -12.0, -23.5 );
    quads(0.33, -13.5, 3.0, -15.3, 3.0, -23.5, 0.33, -23.5);
    glColor3f(0.0, 0.0, 0.0);
    quads(-10.0, -23.50,  -11.0, -23.5,   -11.0, -25.0,   -10.0, -25.0 );
    quads(-3.0, -23.50,  -2.0, -23.5,   -2.0, -25.0,   -3.0, -25.0 );

}

void flower_stick1()
{

    ///flower 1
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.31, 0.47, 0.26);
    glVertex2f(13.0,-12.0);
    glVertex2f(13.0,-25.0);
    glEnd();


    glPushMatrix();
    glTranslatef(19.58,-15.0,0);
    glColor3f(0.31, 0.47, 0.26);
    circle(1.5,1.5);
    glPopMatrix();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.31, 0.47, 0.26);
    glVertex2f(10.0,-6.00);
    glVertex2f(12.0,-13.50);
    glEnd();

     glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.31, 0.47, 0.26);
    glVertex2f(12.5,-13.50);
    glVertex2f(13.5,-12.50);
    glEnd();

     glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.31, 0.47, 0.26);
    glVertex2f(8.0,-13.50);
    glVertex2f(12.5,-18.0);
    glEnd();


    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.31, 0.47, 0.26);
    glVertex2f(19.5,-14.7);
    glVertex2f(13.00,-19.5);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.31, 0.47, 0.26);
    glVertex2f(21.0,-10.0);
    glVertex2f(13.00,-14.0);
    glEnd();

}

void flower_right()
{
    flower_root();

    glPushMatrix();
    glTranslatef(12.0,-3.0,0);
    flower_root();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(5.0,-4.50,0);
    flower_root();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-2.0,-6.0,0);
    flower_root();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(9.0,-8.0,0);
    flower_root();
    glPopMatrix();
}

void flower_left()
{
     glPushMatrix();
    glTranslatef(-22.0,-10.0,0);
    flower_root();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(-27.0,-5.0,0);
    flower_root();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(-25.0,-15.0,0);
    flower_root();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(-33.0,-2.0,0);
    flower_root();
    glPopMatrix();



}


void flower_stick2()
{

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.31, 0.47, 0.26);
    glVertex2f(-23.0,-8.00);
    glVertex2f(-25.0,-25.0);
    glEnd();

     glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.31, 0.47, 0.26);
    glVertex2f(-15.0,-11.0);
    glVertex2f(-25.00,-17.0);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.31, 0.47, 0.26);
    glVertex2f(-13.0,-15.50);
    glVertex2f(-25.0,-23.0);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.31, 0.47, 0.26);
    glVertex2f(-15.5,-21.0);
    glVertex2f(-25.0,-25.0);
    glEnd();





}


void ground_flower()
{
    glPushMatrix();
    glTranslatef(0.0,-17.0,0);
    flower_root();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(-10.0,-17.0,0);
    flower_root();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-15.0,-12.0,0);
    flower_root();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(10.0,-18.0,0);
    flower_root();
    glPopMatrix();

}





void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    sky();
    ground();
    tree1();
    tree2();
    queen_bee();
    honey_comb();


    flower_stick1();
    flower_stick2();

    flower_right();

    beehouse();

    flower_left();
    ground_flower();

     bee();

    glFlush();

}


void spinDisplay_left(void)
{
    spin = spin + 0.01; //to increase or decrease speed change the value added to spin
    if (spin > 360.0)
        spin = spin - 360.0;
    //the above if block is given only for clear understanding, otherwise 370 degrees is the same as 10 degrees

    glutPostRedisplay(); //calls the display function again
}

void spinDisplay_right(void)
{
    spin = spin - 0.02;
    if (spin < -360.0)
        spin = spin + 360.0;
    glutPostRedisplay();
}


void custom_keyboard(unsigned char key, int x, int y)
{

    switch (key)
    {

    case 'L':
       bee_x1 -=0.25; //to move the bee1 left when L key pressed. To make movement faster or slower, try changing values of u
        glutPostRedisplay();
        break;

    case 'R':
          bee_x1 +=0.25;
        glutPostRedisplay();
        break;

    case 'U':
       bee_y1 +=0.5; //too move bee1 up
        glutPostRedisplay();
        break;

    case 'D':
         bee_y1 -=0.5;      //to move bee1 down
        glutPostRedisplay();
        break;

     case 'l':
       bee_x2 -=0.25; //to move the bee1 left when L key pressed. To make movement faster or slower, try changing values of u
        glutPostRedisplay();
        break;

    case 'r':
          bee_x2 +=0.25;
        glutPostRedisplay();
        break;

    case 'u':
       bee_y2 +=0.5; //too move bee1 up
        glutPostRedisplay();
        break;

    case 'd':
         bee_y2 -=0.5;      //to move bee1 down
        glutPostRedisplay();
        break;

    case 's':
        glutIdleFunc(NULL);// make idle function inactive by passing NULL
        break;

    default:
        break;
    }
}


void custom_spe_key(int key, int x, int y)
{
    switch (key)
    {

    case GLUT_KEY_LEFT:
        glutIdleFunc(spinDisplay_left);
        break;

    case GLUT_KEY_RIGHT:
         glutIdleFunc(spinDisplay_right);
        break;
    case GLUT_KEY_DOWN:
        glutIdleFunc(NULL);// make idle function inactive by passing NULL
        break;


    default:
        break;
    }
}



void custom_mouse(int button, int action, int xPixel, int yPixel)
{

    if (button == 0 && action == GLUT_DOWN)
    {
        PlaySound("sound bee.wav",NULL,ASYNC_MODE_COMPATIBILITY);
    }
    if(button == 2 && action == GLUT_DOWN )
    {
        //Finding out the Grid point in the scenario
        if (yPixel<=(window_height/2))
        {
            if(xPixel<=(window_width/2))
            {
                tgt_x = (xPixel-(window_width/2))/((window_width/2)/plus_x);//-625;
                tgt_y = (yPixel-(window_height/2))/-((window_height/2)/plus_y);//325-
            }
            else
            {
                tgt_x = (xPixel-(window_width/2))/((window_width/2)/plus_x);//-625;
                tgt_y = (yPixel-(window_height/2))/-((window_height/2)/plus_y);//325-
            }

        }
        else
        {
            if(xPixel<=(window_width/2))
            {
                tgt_x = (xPixel-(window_width/2))/((window_width/2)/plus_x);//-625;
                tgt_y = (yPixel-(window_height/2))/-((window_height/2)/plus_y);//325-
            }
            else
            {
                tgt_x = (xPixel-(window_width/2))/((window_width/2)/plus_x);//-625;
                tgt_y = (yPixel-(window_height/2))/-((window_height/2)/plus_y);//325-
            }
        }

        printf("x= %.2f, y=%.2f \n",tgt_x,tgt_y);

    }

    glutPostRedisplay();
}

void timer(int)
{
    glutPostRedisplay();

    //if(u<=25) u=u+0.13;
    //else u=-25;
    glutTimerFunc(1000/60,timer,0);

    switch(state)
    {
    case 1:
        if (bee_autox<5 && bee_autoy <0 )
        {
             bee_autox+=0.3;
             bee_autoy+=0.3;
             beer = 45;
             //bee2r= 90;

        }
        else state = -1;
        break;
    case -1:
        if(bee_autox>-30 && bee_autoy >-20)
        {
            bee_autox-=0.3;
            bee_autoy-=0.3;
            beer = -135;
            //bee2r= -180;

        }
        else state = 1;
        break;
    }
}
int main()
{
    glutInitWindowPosition (0, 0);
    glutInitWindowSize (window_width, window_height);
    glutCreateWindow ("Demo_Project");
    init();
    //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutDisplayFunc(display);
    glutSpecialFunc(custom_spe_key);
   glutTimerFunc(1000,timer,0);
    glutKeyboardFunc(custom_keyboard);
    glutMouseFunc(custom_mouse);
    glutMainLoop();
    return 0;
}

