
#include"snlv0.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<time.h>
#include<math.h>
using namespace std;
int flg=1;
int f=0;
int cnt;
//Code to display  character string on the display
char mess[4];

void glutBitmapString(const char *str)
{
	int i=0;
	while(str[i]!='\0')
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i++]);
}
int width,height;
/*---------------code for dice---------------*/

GLfloat vertices [][3] = {{1150.0,550.0,-50.0}, {1250.0,550.0,-50.0}, {1250.0,650.0,-50.0}, {1150.0,650.0,-50.0}, {1150.0,550.0,50.0}, {1250.0,550.0,50.0}, {1250.0,650.0,50.0}, {1150.0,650.0,50.0}};
GLfloat colors [][3] = {{0.0,0.0,0.0}, {1.0,-1.0,-1.0}, {1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0}, {1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}};
void polygon(int a,int b,int c,int d,int e)
{
	glBegin(GL_POLYGON);
	 	glColor3f(1.0,0.0,0.0);
        	glVertex3fv(vertices[a]);
        	glVertex3fv(vertices[b]);
        	glVertex3fv(vertices[c]);
		glVertex3fv(vertices[d]);
 	glEnd();
 	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
		glColor3f(0.9,0.0,0.0);
        	glVertex3fv(vertices[a]);
        	glVertex3fv(vertices[b]);
        	glVertex3fv(vertices[c]);
		glVertex3fv(vertices[d]);
 	glEnd();
 	glLineWidth(2.0);
	glColor3f(1.0,1.0,1.0);
   	glPointSize(3.0);
    	glBegin(GL_POINTS);
        switch(e)
        {
            case 1 :
                        glVertex3f(1200.0,600.0,-50.0);
                        break;
            case 2 :
                        glVertex3f(1175.0,651.0,25.0);
                        glVertex3f(1225.0,651.0,-25.0);
                        break;
            case 3 :    glVertex3f(1149.0,575.0,25.0);
                        glVertex3f(1149.0,600.0,0.0);
                        glVertex3f(1149.0,625.0,-25.0);
                        break;
            case 4 :    glVertex3f(1251.0,575.0,25.0);
                        glVertex3f(1251.0,575.0,-25.0);
                        glVertex3f(1251.0,625.0,25.0);
                        glVertex3f(1251.0,625.0,-25.0);
                        break;
            case 5 :    glVertex3f(1175.0,549.0,25.0);
                        glVertex3f(1175.0,549.0,-25.0);
                        glVertex3f(1200.0,549.0,0.0);
                        glVertex3f(1225.0,549.0,25.0);
                        glVertex3f(1225.0,549.0,-25.0);
                        break;
            case 6 :    glVertex3f(1175.0,575.0,51.0);
                        glVertex3f(1175.0,600.0,51.0);
                        glVertex3f(1175.0,625.0,51.0);
                        glVertex3f(1225.0,575.0,51.0);
                        glVertex3f(1225.0,600.0,51.0);
                        glVertex3f(1225.0,625.0,51.0);
                        break;
        }
	 glEnd();
}
void colorcube(void)
{
    polygon(0,3,2,1,1);
    polygon(2,3,7,6,2);
    polygon(0,4,7,3,3);
    polygon(1,2,6,5,4);
    polygon(4,5,6,7,5);
    polygon(0,1,5,4,6);
}
static GLfloat theta[]={0.0,0.0,0.0};
/*--------------code for the board---------*/

void rect()
{
	int i,j;
	x[-1]=x0;
	y[-1]=y2;
	for( i=0;i<=maxx;i++)
		x[i]=x0+i*dx;
	for( j=0;j<=maxy;j++)
		y[j]=y2+j*dy;
	glColor3f(0.88,0.88,0.88);
	glBegin(GL_QUADS);
        	glVertex3f(x0,y2,10);
        	glVertex3f(x[maxx],y2,10);
        	glVertex3f(x[maxx],y[maxy],10);
        	glVertex3f(x0,y[maxy],10);
	glEnd();
	int count=1;
	int temp=1;
	i=0;
	for(j=0;j<maxy;j++)
	{
		while(1)
		{
			if(temp<0)
			{
				if(i<0)
					break;
			}
			else
			{
				if(i>maxx-1)
					break;
			}
			glColor3f(0.4,0.2,0.0);
			glBegin(GL_LINE_LOOP);
                		glVertex3f(x[i],y[j],11);
                		glVertex3f(x[i],y[j+1],11);
                		glVertex3f(x[i+temp],y[j+1],11);
                		glVertex3f(x[i+temp],y[j],11);
			glEnd();
			glColor3f(0.50/(i+j/2.0),1.0/(i+j),1.0/(i-j));
			glRasterPos3f(x[i]+10,y[j]+10,20);
			int k=0;
			sprintf(mess,"%d",count);
			if(count==100)
				strcpy(mess,"END");
			glutBitmapString(mess);
			count++;
			i+=temp;
		}
		if(temp>0)
		{
			temp=-1;
		}
		else
		{
			temp=1;
		}
		i+=temp;
	}
}
/*--------------code for the starting page------------------*/
void display1()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0,1.0,0.8,1.0);
    int i;
    glColor3f(1.0,0.0,0.0);
    glRasterPos3f(400,700,10);
    glutBitmapString("PES COLLEGE OF ENGINEERING");
    glRasterPos3f(370,650,10);
    glutBitmapString("DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
    glRasterPos3f(600,600,10);
    glutBitmapString("SNAKE 'N' LADDER");
    glRasterPos3f(200,400,10);
    glutBitmapString("USN : 1PE14CS031");
    glRasterPos3f(200,350,10);
    glutBitmapString("USN : 1PE14CS001");
    glRasterPos3f(850,400,10);
    glutBitmapString("NAME : BHARGAV N");
    glRasterPos3f(850,350,10);
    glutBitmapString("NAME : A BHARATH REDDY");
    glRasterPos3f(200,200,10);
    glutBitmapString("UNDER THE GUIDANCE OF : Mr.SRIKANTH AND MS.BIDISHA");
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(615.0,100.0,10.0);
        glVertex3f(615.0,140.0,10.0);
        glVertex3f(710.0,140.0,10.0);
        glVertex3f(710.0,100.0,10.0);
    glEnd();
    glColor3f(0.82,0.82,0.82);
    glBegin(GL_QUADS);
        glVertex3f(615.0,100.0,9.0);
        glVertex3f(615.0,140.0,9.0);
        glVertex3f(710.0,140.0,9.0);
        glVertex3f(710.0,100.0,9.0);
    glEnd();
    glColor3f(1.0,0.0,0.0);
    glRasterPos3f(630,110,10.0);
    glutBitmapString("NEXT");
    glFlush();
    glutSwapBuffers();
}
/*--------------Code for the gaming page-------------------*/
void display2()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,0.8,1.0);
	glPushMatrix();
	 	glTranslatef(1200.0,600.0,0.0);
		glRotatef(theta[0],1.0,1.0,0.0);
        	glRotatef(theta[1],0.0,1.0,0.0);
   		glRotatef(theta[2],0.0,0.0,1.0);
        	glTranslatef(-1200.0,-600.0,0.0);
		colorcube();
   	glPopMatrix();
	glFlush();
	rect();
	glColor3f(1.0,(128.0/255.0),0.0);
	int i;
    	glRasterPos3f(50.0,600.0,20.0);
    	glutBitmapString("PLAYER 1 : ");
    	glRasterPos3f(50.0,550.0,20.0);
    	glutBitmapString("PLAYER 2 : ");
    	glColor3f(1.0,1.0,0.0);
    	glBegin(GL_QUADS);
		glVertex3f(200.0,600.0,20.0);
        	glVertex3f(210.0,610.0,20.0);
        	glVertex3f(200.0,620.0,20.0);
        	glVertex3f(190.0,610.0,20.0);
    	glEnd();
    	glColor3f(0.5,1.0,0.0);
    	glBegin(GL_QUADS);
        	glVertex3f(200.0,550.0,20.0);
        	glVertex3f(210.0,560.0,20.0);
        	glVertex3f(200.0,570.0,20.0);
        	glVertex3f(190.0,560.0,20.0);
    	glEnd();
    	glPushMatrix();
    		glTranslatef(1200.0,300.0,0.0);
    		//glColor3f((51.0/255.0),(51.0/255.0),1.0);
    		glColor3f(1,1,0);
    		glBegin(GL_POLYGON);
        		for(i=0;i<360;i++)
        	{
            		float rad = i*(180/3.14);
            		glVertex3f(cos(rad)*60,sin(rad)*40,18.0);
        	}
    		glEnd();
    	glPopMatrix();
    	glColor3f(1.0,1.0,(201.0/255.0));
	glRasterPos3f(1163,306,20);
	glutBitmapString("CLICK");
	glRasterPos3f(1163,276,20);
	glutBitmapString(" HERE");
	glColor3f(0.4,0.2,0.0);
	glBegin(GL_QUADS);
        glVertex3f(x0+20,y[maxy]+20,0);
        glVertex3f(x0,y[maxy],10);
        glVertex3f(x[maxx],y[maxy],10);
        glVertex3f(x[maxx]+20,y[maxy]+20,0);
	glEnd();
	glBegin(GL_QUADS);
        glVertex3f(x[maxx],y[maxy],10);
        glVertex3f(x[maxx]+20,y[maxy]+20,0);
        glVertex3f(x[maxx]+20,y2+20,0);
        glVertex3f(x[maxx],y2,10);
	glEnd();
	glutSwapBuffers();
	//glutPostRedisplay();
}

/*------------Code for spinning the cube----------------*/
int spincube()
{
	theta[0]+=12;
    if(theta[0]>360.0)
	{
		cnt++;
        theta[0]-=360;
	}
    display2();
	if(cnt<2)
        spincube();
    else
    {
        if(flg)
		{
		
            srand(time(NULL));
            int s=(rand()%6)+1;
            switch(s)
            {
                case 1 :    theta[1]+=90;
                            theta[2]-=45;
                            break;
                case 2 :    theta[2]+=45;
                            break;
                case 3 :    theta[2]-=45;
                            break;
                case 4 :    theta[2]+=135;
                            break;
                case 5 :    theta[2]+=225;
                            break;
                case 6 :    theta[1]-=90;
                            theta[2]-=45;
                            break;
			}
			flg=0;
			spincube();
		}
	}
	return 0;
}
/*-------------- code for mouse call back --------------------*/
void mouse(int btn,int state,int x,int y)
{
	if(!f)
    	{
		if(x>=((610*width)/1367) && x<=((710*width)/1367) && y<=(((767-100)*height)/767) && y>=(((767-140)*height)/767))
        	{
            		if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
            		{
                		glutDisplayFunc(display2);
                		glutPostRedisplay();
                		f=1;
            		}
        	}
    	}
    	else
    	{
	    	if(x>=((1140*width)/1367) && x<=((1260*width)/1367) && y<=(((767-260)*height)/767) && y>=(((767-340)*height)/767))
		{
            		if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
        		{
                		cnt=0;flg=1;theta[1]=90;theta[2]=45;
                		spincube();
        		}
		}
    	}
}

void myReshape(int w,int h)
{
        width=w;height=h;
    	glViewport(0,0,w,h);
    	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();
        glOrtho(0.0,1367.0,0.0,767.0, -180.0,180.0);
        glMatrixMode(GL_MODELVIEW);
        glClearColor(1.0,1.0,0.8,1.0);
}
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB| GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1366,768);
	glutCreateWindow("Demo");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display1);
	glutMouseFunc(mouse);
	glutReshapeFunc(myReshape);
	glutMainLoop();
}
