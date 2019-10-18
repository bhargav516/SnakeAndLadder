
#include"snlv0.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<time.h>
#include<math.h>
//#include "ObjLoader.h"
using namespace std;
int check(int fg);
//ObjLoader obj_snake, obj_ladder, obj_pawn;
int p=1;
int m=1;
int ik=1,ch=0;
int q=0,lol=0;
int flg=1;
int vehicleX = x0+30, vehicleY = y2+30;
int vehicleX1 = x0+30, vehicleY1 = y2+30;
int vehicleY100,vehicleX100;
int vehicleY101,vehicleX101;
int getpos(int ji);

int divx = 250, divy = 4, movd;
int f=0;
void pawn();
void pawn2();
int drawsnakeandladder();
int draw_ladder(GLfloat vehicleX1001,GLfloat vehicleX1002,GLfloat vehicleY1001,GLfloat vehicleY1002 ,int m);
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
void display3()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,0.8,1.0);
	glColor3f(1.0,0.0,0.0);
    glRasterPos3f(400,700,10);
    glutBitmapString("PLAYER 2 HAS WON THE GAME");
	glFlush();
    glutSwapBuffers();
}
void display4()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,0.8,1.0);
	glColor3f(1.0,0.0,0.0);
    glRasterPos3f(400,700,10);
    glutBitmapString("PALYER 1 HAS WON THE GAME");
	glFlush();
    glutSwapBuffers();
}
/*--------------code for the starting page------------------*/
void display1()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0,1.0,0.8,1.0);
    int i;
    glColor3f(1.0,0.0,0.0);
    glRasterPos3f(400,700,10);
    glutBitmapString("PESIT BANGALORE SOUTH CAMPUS");
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
	drawsnakeandladder();
	if(lol==0)
	{
		
		pawn();
		
		pawn2();
		
		lol=1;
	}
	if(lol==1)
	{
		pawn();
		
		pawn2();
		
		lol=0;
		
	}
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
void pawn(){
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	//drawRoad();
	//rawDivider();
   glPointSize(10.0);
    

    glBegin(GL_QUADS);
        glColor3f(1,0,0);//middle body
        glVertex3f(vehicleX100 - 20, vehicleY100 + 20,30);
        glVertex3f(vehicleX100 - 20, vehicleY100 - 20,30);
        glVertex3f(vehicleX100 + 20, vehicleY100 - 20,30);
        glVertex3f(vehicleX100 + 20, vehicleY100 + 20,30);
    glEnd();
    
    
		
		//vehicleX1=x0+30;
		///vehicleY1=y2+30;
   
	

  

    
   // glFlush();
	
}
void pawn2(){
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	//drawRoad();
	//rawDivider();
   glPointSize(10.0);
    

    glBegin(GL_QUADS);
        glColor3f(1,1,0);//middle body
        glVertex3f(vehicleX101 - 20, vehicleY101 + 20,30);
        glVertex3f(vehicleX101 - 20, vehicleY101 - 20,30);
        glVertex3f(vehicleX101 + 20, vehicleY101 - 20,30);
        glVertex3f(vehicleX101 + 20, vehicleY101 + 20,30);
    glEnd();
    //vehicleX=x0+30;
		//vehicleY=y2+30;
    
     
	
  

    
   // glFlush();
	
}
int switchcase(int ane)
{
	switch(ane)
	{
		//case 0:ane=1;break;
		case 1:ane=0;break;
		case 2:ane=1;break;
		case 3:ane=2;break;
		case 4:ane=3;break;
		case 5:ane=4;break;
		case 6:ane=5;break;
		case 7:ane=6;break;
		case 8:ane=7;break;
		case 9:ane=8;break;
		case 10:ane=9;break;
		case 11:ane=19;break;
		case 12:ane=18;break;
		case 13:ane=17;break;
		case 14:ane=16;break;
		case 15:ane=15;break;
		case 16:ane=14;break;
		case 17:ane=13;break;
		case 18:ane=12;break;
		case 19:ane=11;break;
		case 20:ane=10;break;
		case 21:ane=20;break;
		case 22:ane=21;break;
		case 23:ane=22;break;
		case 24:ane=23;break;
		case 25:ane=24;break;
		case 26:ane=25;break;
		case 27:ane=26;break;
		case 28:ane=27;break;
		case 29:ane=28;break;
		case 30:ane=29;break;
		case 31:ane=39;break;
		case 32:ane=38;break;
		case 33:ane=37;break;
		case 34:ane=36;break;
		case 35:ane=35;break;
		case 36:ane=34;break;
		case 37:ane=33;break;
		case 38:ane=32;break;
		case 39:ane=31;break;
		case 40:ane=30;break;
		case 41:ane=40;break;
		case 42:ane=41;break;
		case 43:ane=42;break;
		case 44:ane=43;break;
		case 45:ane=44;break;
		case 46:ane=45;break;
		case 47:ane=46;break;
		case 48:ane=47;break;
		case 49:ane=48;break;
		case 50:ane=49;break;
		case 51:ane=59;break;
		case 52:ane=58;break;
		case 53:ane=57;break;
		case 54:ane=56;break;
		case 55:ane=55;break;
		case 56:ane=54;break;
		case 57:ane=53;break;
		case 58:ane=52;break;
		case 59:ane=51;break;
		case 60:ane=50;break;
		case 61:ane=60;break;
		case 62:ane=61;break;
		case 63:ane=62;break;
		case 64:ane=63;break;
		case 65:ane=64;break;
		case 66:ane=65;break;
		case 67:ane=66;break;
		case 68:ane=67;break;
		case 69:ane=68;break;
		case 70:ane=69;break;
		case 71:ane=79;break;
		case 72:ane=78;break;
		case 73:ane=77;break;
		case 74:ane=76;break;
		case 75:ane=75;break;
		case 76:ane=74;break;
		case 77:ane=73;break;
		case 78:ane=72;break;
		case 79:ane=71;break;
		case 80:ane=70;break;
		case 81:ane=80;break;
		case 82:ane=81;break;
		case 83:ane=82;break;
		case 84:ane=83;break;
		case 85:ane=84;break;
		case 86:ane=85;break;
		case 87:ane=86;break;
		case 88:ane=87;break;
		case 89:ane=88;break;
		case 90:ane=89;break;
		case   91:ane=99;break;
		case 92:ane=98;break;
		case 93:ane=97;break;
		case 94:ane=96;break;
		case 95:ane=95;break;
		case 96:ane=94;break;
		case 97:ane=93;break;
		case 98:ane=92;break;
		case 99:ane=91;break;
		case 100:ane=90;break;
		


	}
	return ane;
	
	
}
int drawsnakeandladder()
{	int vehicleY1001,vehicleX1001,vehicleX1002,vehicleY1002;
	int arry[]={98,95,92,83,73,69,64,59,55,55,48,46,44,8,21,43,50,54,62,66,80};
	int arry2[]={28,24,51,19,1,33,36,17,7,11,9,5,22,26,82,77,91,93,96,87,100};
	for(int i=0;i<21;i++)
	{
		if(arry[i]<arry2[i])
		{//draw ladder 
			int kim,jhon;
			int ko,jo,po;
			jo=switchcase(arry[i]);
			ko=(jo/10);
	
			vehicleY1001=vehicleY+(ko*70);
			po=(jo%10);
			vehicleX1001=vehicleX+(po*70);
			jo=switchcase(arry2[i]);
			ko=(jo/10);
	
			vehicleY1002=vehicleY+(ko*70);
			po=(jo%10);
			vehicleX1002=vehicleX+(po*70);
			glColor3f(1.0,0.0,0.0);
			glBegin(GL_LINES);
			glVertex3f(vehicleX1001-5,vehicleY1001,20.0);
        	glVertex3f(vehicleX1002-5,vehicleY1002,20.0);
    	glEnd();
        glBegin(GL_LINES);
            glVertex3f(vehicleX1001+5,vehicleY1001,20.0);
            glVertex3f(vehicleX1002+5,vehicleY1002,20.0);
        glEnd();
        /*GLfloat loki=(vehicleX1001-5+vehicleX1002-5)/2;
        GLfloat poki=(vehicleY1001+vehicleY1002)/2;
        GLfloat soki=(vehicleX1001+5+vehicleX1002+5)/2;
        GLfloat joki=(vehicleY1001+vehicleY1002)/2;
        int count =4;
            for (int i = 0; i < count; i++)
            {
                

                glBegin(GL_LINES);
                glVertex3f(loki,poki,20.0);
                glVertex3f(soki,joki,20.0);
                 glEnd();
                 glBegin(GL_LINES);
                 glVertex3f((loki+vehicleY1001)/2,poki+vehicleY1002);
                 glVertex3f();
                 glEnd();
                
            }*/
                 draw_ladder(vehicleX1001,vehicleX1002,vehicleY1001,vehicleY1002,3);
			
			
			
			
		}else
		{
            //draw snakes
			int kim,jhon;
			int ko,jo,po;
			jo=switchcase(arry[i]);
			ko=(jo/10);
	
			vehicleY1001=vehicleY+(ko*70);
			po=(jo%10);
			vehicleX1001=vehicleX+(po*70);
			jo=switchcase(arry2[i]);
			ko=(jo/10);
	
			vehicleY1002=vehicleY+(ko*70);
			po=(jo%10);
			vehicleX1002=vehicleX+(po*70);
			glColor3f(0.0,1.0,0.0);
			/*glBegin(GL_LINES);
			glVertex3f(vehicleX1001,vehicleY1001,20.0);
        	glVertex3f(vehicleX1002,vehicleY1002,20.0);
			glEnd();*/
            draw_ladder(vehicleX1001,vehicleX1002,vehicleY1001,vehicleY1002,10);
			
		}
	}
}
int draw_ladder(GLfloat vehicleX1001,GLfloat vehicleX1002,GLfloat vehicleY1001,GLfloat vehicleY1002 ,int m)
{
    int count =0;
    if(m>0){

        GLfloat loki=(vehicleX1001-5+vehicleX1002-5)/2;
        GLfloat poki=(vehicleY1001+vehicleY1002)/2;
        GLfloat soki=(vehicleX1001+5+vehicleX1002+5)/2;
        GLfloat joki=(vehicleY1001+vehicleY1002)/2;
        glBegin(GL_LINES);
        glVertex3f(loki,poki,20.0);
        glVertex3f(soki,joki,20.0);
        glEnd();
        draw_ladder(loki , vehicleX1001,poki,vehicleY1001,m-1);
        draw_ladder(soki , vehicleX1002,joki,vehicleY1002,m-1);
    }else{
        count++;
    }

}
int getpos(int ji)
{
	int kim,jhon;
	int ko,jo,po;
	jo=switchcase(ji);
	ko=(jo/10);
	
	vehicleY100=vehicleY+(ko*70);
	po=(jo%10);
	vehicleX100=vehicleX+(po*70);
	//           vehicleX=vehicleX+70;

	
}
int getpos2(int ji)
{
	int ko,jo,po;
	jo=switchcase(ji);
	ko=(jo/10);
	vehicleY101=vehicleY1+(ko*70);
	po=(jo%10);
	vehicleX101=vehicleX1+(po*70);
	//           vehicleX=vehicleX+70;

	
}
int check(int fg)
{
    if(p==100)
    {
        cout<<"\n player 1 has won";
        cout<<"\ngame over";
			glutDisplayFunc(display4);
            glutPostRedisplay();
        //exit(0);

    }
    if(m==100)
    {   cout<<"\nplayer 2 has won";
        cout<<"\ngame over";
        glutDisplayFunc(display3);
        glutPostRedisplay();
        //exit(0);

    }
    if(q==0)
    {q=1;
        int np=p;
        p=p+fg;
        int temp123=p;
        switch(p)
        {
            case 98 :p=28;break;
            case 95 :p=24;break;
            case 92 :p=51;break;
            case 83 :p=19;break;
            case 73 :p=1;break;
            case 69 :p=33;break;
            case 64 :p=36;break;
            case 59 :p=17;break;
            case 55 :p=7;break;
            case 52 :p=11;break;
            case 48 :p=9;break;
            case 46 :p=5;break;
            case 44 :p=22;break;
            case 8 :p=26;break;
            case 21 :p=82;break;
            case 43 :p=77;break;
            case 50 :p=91;break;
            case 54 :p=93;break;
            case 62 :p=96;break;
            case 66 :p=87;break;
            case 80 :p=100;
        }
        if(temp123>p)
        {
            system("audacious climb.mp3");
        }
        if (temp123<p)
        {
            
            system("audacious snakehit.mp3");
        }
        if(p>100)
        {
            p=np;
        }
        cout<<"\n you have moved to player 1\t"<<p;
        getpos(p);
        return 0;
    }
    else
    {
        q=0;
        int nm=m;
        m=m+fg;
        int temp123=m;
        switch(m)
        {
            case 98 :m=28;break;
            case 95 :m=24;break;
            case 92 :m=51;break;
            case 83 :m=19;break;
            case 73 :m=1;break;
            case 69 :m=33;break;
            case 64 :m=36;break;
            case 59 :m=17;break;
            case 55 :m=7;break;
            case 52 :m=11;break;
            case 48 :m=9;break;
            case 46 :m=5;break;
            case 44 :m=22;break;
            case 8 :m=26;break;
            case 21 :m=82;break;
            case 43 :m=77;break;
            case 50 :m=91;break;
            case 54 :m=93;break;
            case 62 :m=96;break;
            case 66 :m=87;break;
            case 80 :m=100;
        }
        if(temp123>m)
        {
            system("audacious climb.mp3");
        }
        if (temp123<m)
        {
            
            system("audacious snakehit.mp3");
        }
        if (m>100)
        {
            m=nm;
        }
        cout<<"\n you have moved to player 2\t"<<m;
        getpos2(m);
        return 0;
    }

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
           //vehicleX=vehicleX+70;
           //getpos(20);
           
           //for(ik=1;ik<100;ik++)
           //{
           //getpos(70);
			//}
			int s=(rand()%6)+1;
			if(ch==0)
			{
				check(s);
				ch==1;
				
			}
			if(ch==1)
			{
				check(s);
				ch==0;
			}
            
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
                		//getpos(20);
                		system("audacious rename.mp3 ");
                		
                		
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
	
	//glDepthFunc(GL_NEVER); 
	glutDisplayFunc(display1);
	glutMouseFunc(mouse);
	glutReshapeFunc(myReshape);
	glutMainLoop();
}
