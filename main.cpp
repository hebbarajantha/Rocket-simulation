#include <windows.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<stdarg.h>
#include<stdio.h>
#include <GL/glut.h>
static double x=0.0,x1=0.0,y1=0.1,z1=0.0,a1=0,y2=0,z2=0,a=0,b=0;
static double move=-60;
static bool seperate=false;
int showmenu=0;
int iter=0;
void drawText(int x,int y,char *string)
{
 int i, len;
 glMatrixMode(GL_PROJECTION);
 glPushMatrix();
 glLoadIdentity();
 int w = glutGet( GLUT_WINDOW_WIDTH );
 int h = glutGet( GLUT_WINDOW_HEIGHT );
 glOrtho( 0, w, 0, h, -1, 1 );
 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glLoadIdentity();
 glDisable(GL_DEPTH_TEST);
 glDisable(GL_LIGHTING);
 glColor3f(0.5f, 1.0f, 0.5f);
 glRasterPos2f(x,y);
 for (i=0,len=strlen(string);i<len;i++)
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)string[i]);
 glEnable( GL_LIGHTING );
 glEnable (GL_DEPTH_TEST);
 glMatrixMode(GL_MODELVIEW);
 glPopMatrix();
 glMatrixMode(GL_PROJECTION);
 glPopMatrix();
 //glEnable(GL_LIGHTING);
 //glEnable(GL_DEPTH_TEST);
}
void menu1()
{
 for(iter=0;iter<4000;iter++)
 {
 char str1[]="PROJECT NAME : ROCKET SIMULATION";
 glClearColor(0,0,0,0);
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1,0,0);
 char str0[]="BANGALORE UNIVERSITY";
 char str2[]="UNIVERSITY VISVESVARAYA COLLEGE OF ENGINEERING";
 char str3[]="5th SEM ISE";
 char str4[]="BY- 18GAEE8056 - VEDAVYAS S JOSHI";
 char str8[]=" 18GAEE8003 - AJANTHA K S";
 char str5[]="UNDER THE GUIDANCE OF - DR. VIMALA H S";
 char str6[]="DR. LAVANYA";
 char str7[]="THANK YOU";
 drawText(330,550,str0);
 drawText(180,490,str2);
 drawText(240,400,str1);
 drawText(50,320,str4);
 drawText(80,280,str8);
 drawText(50,200,str5);
 drawText(390,150,str6);
 //drawText(725,210,str7);
 drawText(650,310,str3);
 glFlush();
 glutSwapBuffers();
 ++showmenu;
 glutPostRedisplay();
 }
}
void
stroke_output(GLfloat x, GLfloat y, char *format,...)
{
 va_list args;
 char buffer[200], *p;
 va_start(args, format);
 vsprintf(buffer, format, args);
 va_end(args);
 glPushMatrix();
 glTranslatef(-2.5, y, 0);
 glScaled(0.003, 0.005, 0.005);
 glColor3f(1.0,1.0,1.0);
 for (p = buffer; *p; p++)
 glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
 glPopMatrix();
}
void satellite(){
 glPushMatrix();
 //Core
 glPushMatrix();
 glColor3f(1,1,0);
 glTranslatef(0,2,0);
 glScaled(0.3,1,0.3);
 glRotatef(90,1,0,0);
 if(x<=6)
 glutSolidTorus(0.5,1,30,30);
 else
 glutSolidCube(1);
 glPopMatrix();
 // Solar Panel
 glPushMatrix();
 glColor3f(0.2,0.2,0.2);
 glTranslatef(1,2,0);
 if(x>=6){
 glScaled(4,1.5,0.1);
 }
 else
 glScaled(0,0,0);
 glRotatef(-20,1,0,0);
 glutSolidCube(0.5);
 glPopMatrix();
 glPushMatrix();
 glColor3f(0.2,0.2,0.2);
 glTranslatef(-1,2,0);
 if(x>=6){
 glScaled(4,1.5,0.1);
 }
 else
 glScaled(0,0,0);
 glRotatef(-20,1,0,0);
 glutSolidCube(0.5);
 glPopMatrix();
 glPopMatrix();
}
void rocket(){
 // Main top cone
 glPushMatrix();
 if(x>=5.5){
 glTranslatef(z2,-z2,z2);
 glRotatef(a1,0,1,1);
 }
 glPushMatrix();
 glTranslatef(0,2.5,0);
 glColor3f(0,0,1);
 glScaled(2.2 ,1.5,2.2);
 glRotatef(270,1,0,0);
 glutSolidCone(0.2,1,30,30);
 glPopMatrix();
 glPopMatrix();
 // Satelitte container
 glPushMatrix();
 if(x>=6.8){
 glTranslatef(2,0,0);
 glRotatef(x*40,0,1,0);
 }
 satellite();
 glPopMatrix();
 glPushMatrix();
 if(x>=5){
 glTranslatef(0,y2,y2);
 glRotatef(a1,0,1,1);
 }
 glPushMatrix();
 glColor3f(1,1,1);
 glTranslatef(0,0.0,0);
 glScaled(0.3,4.3,0.3);
 glRotatef(90,1,0,0);
 glutSolidTorus(0.5,1,30,30);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(0,-2.2,0);
 glColor3f(0.9,0,0);
 glScaled(3,1.5,3);
 glRotatef(270,1,0,0);
 glutSolidCone(0.2,1,30,30);
 glPopMatrix();
 glPopMatrix();
 // RightSide rocket
 glPushMatrix();
 glTranslatef(x1,-y1,z1);
 glRotatef(a1,0,1,1);
 glPushMatrix();
 glTranslatef(0.7,1,0);
 glColor3f(0,0,1);
 glScaled(1.5 ,1,1.5);
 glRotatef(270,1,0,0);
 glutSolidCone(0.2,1,30,30);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(0.7,-0.2,0);
 glColor3f(1,1,1);
 glScaled(0.2,6.5,0.2);
 glRotatef(90,1,0,0);
 glutSolidTorus(0.2,1,30,30);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(0.7,-2.0,0);
 glColor3f(0.9,0,0);
 glScaled(1.5,1,1.5);
 glRotatef(270,1,0,0);
 glutSolidCone(0.2,1,30,30);
 glPopMatrix();
 glPopMatrix();
 // LeftSide rocket
 glPushMatrix();
 glTranslatef(-x1,-y1,-z1);
 glRotatef(-a1,0,1,1);
 glPushMatrix();
 glTranslatef(-0.7,1,0);
 glColor3f(0,0,1);
 glScaled(1.5 ,1,1.5);
 glRotatef(270,1,0,0);
 glutSolidCone(0.2,1,30,30);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(-0.7,-0.2,0);
 glColor3f(1,1,1);
 glScaled(0.2,6.5,0.2);
 glRotatef(90,1,0,0);
 glutSolidTorus(0.2,1,30,30);
 glPopMatrix();
 glPushMatrix();
 glTranslatef(-0.7,-2.0,0);
 glColor3f(0.9,0,0);
 glScaled(1.5,1,1.5);
 glRotatef(270,1,0,0);
 glutSolidCone(0.2,1,30,30);
 glPopMatrix();
 //booster
/*
 glPushMatrix();
 glTranslatef(2,0,0);
 glColor3f(1,1,0);
 glBegin(GL_POLYGON);
 glVertex3f(0,0,0);
 glVertex3f(1,0,0);
 glVertex3f(0.8,-1,0);
 glVertex3f(0,0,0);
 glEnd();
 glPopMatrix();
*/
 glPopMatrix();
}
void stars(){
 for(float s1=5;s1<=100; s1+=0.4){
 for(float s2=-6;s2<=6;s2+=0.5){
 glPushMatrix();
 glBegin(GL_POINTS);
 glVertex3f(s2,s1,0);
 glEnd();
 glPopMatrix();
 }
 }
 for(float s3=5.2;s3<=100; s3+=0.3){
 for(float s4=-6.2;s4<=6;s4+=0.3){
 glPushMatrix();
 glBegin(GL_POINTS);
 glVertex3f(s4,s3,0);
 glEnd();
 glPopMatrix();
 }
 }
}
// Draw rocket
void rocket(double ang)
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glLoadIdentity();
 glTranslatef(0.0f,0.0f,-13.0f);
 //glRotatef(ang,0.0f,1.0f,0.0f);
 glPushMatrix();
 if(ang<=2){
 glRotatef(ang*30,1,0,0);
 glTranslatef(0,-2+ang,0);
 }
 else{
 glRotatef(60,1,0,0);
 glTranslatef(0,0,0);
 }
 glScaled(0.5,0.5,0.5);
 rocket();
 glPopMatrix();
 //Earth
 glPushMatrix();
 glColor3f(0,0,1);
 if(x>=6.5){
 glTranslatef(0,-18,-95);
 glRotatef(10*x,0,1,0);
 }else{
 glTranslatef(0,-10-x,-10-15*x);
 }
 glutSolidSphere(10,100,100);
 glPopMatrix();
 // Create Stars
 glPushMatrix();
 glColor3f(1,1,1);
 glTranslatef(0,-ang,0);
 stars();
 glPopMatrix();
 glFlush();
 glutSwapBuffers();
}
void p()
{
 x+=0.01;
 if(x>=3){
 x1+=0.1;
 y1+=0.1;
 z1+=0.01;
 a1+=3;
 }
 if(x>5){
 y2-=0.1;
 }
 if(x>5.5){
 z2+=0.1;
 }
rocket(x);
 }
void menu(int id)
{
 switch(id)
 {
 case 1:glutIdleFunc(p);
 break;
 case 5:exit(0);
 break;
 }
 glFlush();
 glutSwapBuffers();
 glutPostRedisplay();
}
void doInit()
{
 /* Background and foreground color*/
 glClearColor(0.0,0.0,0.0,0);
 glViewport(0,0,640,480);
 /* Select the projection matrix and reset it then
 setup our view perspective */
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluPerspective(30.0f,(GLfloat)640/(GLfloat)480,0.1f,200.0f);
 /* Select the modelview matrix, which we alter with rotatef() */
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 glClearDepth(2.0f);
 glEnable(GL_DEPTH_TEST);
 glDepthFunc(GL_LEQUAL);
}
void display()
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glLoadIdentity();
 glTranslatef(0.0f,0.0f,-13.0f);
 stroke_output(-2.0, 2.0, "Welcome to Rocket Simulation");
 stroke_output(-2.0, 1.0, "p/P-->Launch the Rocket");
 stroke_output(-2.0, 0.0, "q/Q-->Q to Quit");
 GLfloat mat_ambient[]={0.0f,1.0f,2.0f,1.0f};
 GLfloat mat_diffuse[]={0.0f,1.5f,.5f,1.0f};
 GLfloat mat_specular[]={5.0f,1.0f,1.0f,1.0f};
 GLfloat mat_shininess[]={50.0f};
 glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
 glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
 glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
 glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
 GLfloat lightIntensity[]={1.7f,1.7f,1.7f,1.0f};
 GLfloat light_position3[]={0.0f,5.0f,0.0f,0.0f};
 glLightfv(GL_LIGHT0,GL_POSITION,light_position3);
 glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
 glEnable(GL_COLOR_MATERIAL);
 glFlush();
 glutSwapBuffers();
}
void disp()
{
 if(showmenu<3000)
 {
 menu1();
 }
 else
 return;
}
void mykey(unsigned char key,int x,int y)
{
 if(key=='p'||key=='P')
 {
 glutIdleFunc(p);
 }
 if(key=='q'||key=='Q')
 {
 exit(0);
 }
}
int main(int argc, char *argv[])
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
 glutInitWindowSize(1000,800);
 glutInitWindowPosition(0,0);
 glutCreateWindow("rocket");
 disp();
 glutDisplayFunc(display);
 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);
 glShadeModel(GL_SMOOTH);
 glEnable(GL_DEPTH_TEST);
 glEnable(GL_NORMALIZE);
 glutKeyboardFunc(mykey);
 glutCreateMenu(menu);
 glutAddMenuEntry("Launch 'p'",1);
 glutAddMenuEntry("Quit 'q'",5);
 glutAttachMenu(GLUT_RIGHT_BUTTON);
 doInit();
 glutMainLoop();
 return 0;
}
