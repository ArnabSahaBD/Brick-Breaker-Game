/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"
# include "math.h"
# include "stdlib.h"
#include "string.h"

/* 
	function iDraw() is called again and again by the system.
*/

struct brick{
int x1,y1;
}red[9],blue[9],yellow[3],silver[5];

struct menu{
int x2,y2;
}play,hs,ins;

struct high_score{
	char name[10];
	int highs;
}player,gamer[4];



int xpaddle=200; int gx=200;
int ypaddle= 0; int gy=10;
int xball=300; int dx=3;
int yball=20; int dy=5;
int timer1;
int direction =1;
int velocity=10;
int x,y,i,j,bx=40,by=30,cnt=0;
int gameState=0,gameOver=0,instruction=0,hscore=0;
int p=0,h=0,in=0;
int indexNumber=0;char str[10];
int s;
char g1[10];
char str1[10];
float theta=60,pi=3.1416;
FILE * fp;


void iDraw()
{
	//place your drawing codes here	
	iClear();
	if(gameState==0)
		{
			iShowBMP(0,0,"menu.bmp");
			iShowBMP(play.x2,play.y2,"play2.bmp");iShowBMP(hs.x2,hs.y2,"hs2.bmp");
			iShowBMP(ins.x2,ins.y2,"ins.bmp");
			if(instruction==1)
			{
					iShowBMP(0,0,"instruction.bmp");
					gameState=0;hscore=0;
		    }
			if(hscore==1)
			{
					iShowBMP(0,0,"high_score2.bmp");
					gameState=0;instruction=0;
					iSetColor(255,0,0);
					for (i = 0; i < 4; i++) 
					{
						 for (j = 0; j < (4 - i - 1); j++)
						 {
							if (gamer[j].highs < gamer[j+1].highs)
							{
								 s = gamer[j].highs;
								 gamer[j].highs = gamer[j+1].highs;
								 gamer[j+1].highs = s;
							}
						}
						 
					}
					fp = fopen ("highscore.txt", "r");
					if(fp!=NULL)
					{
						fscanf(fp,"%s%d",player.name,&player.highs);
						
					}

					if(player.highs>=gamer[0].highs)

						{	
							iText(200,350,player.name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(player.highs,g1,10);
							iText(300,350,g1,GLUT_BITMAP_TIMES_ROMAN_24);
							
							
							iText(200,300,gamer[0].name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(gamer[0].highs,g1,10);
							iText(300,300,g1,GLUT_BITMAP_TIMES_ROMAN_24);

							iText(200,250,gamer[1].name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(gamer[1].highs,g1,10);
							iText(300,250,g1,GLUT_BITMAP_TIMES_ROMAN_24);

							iText(200,200,gamer[2].name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(gamer[2].highs,g1,10);
							iText(300,200,g1,GLUT_BITMAP_TIMES_ROMAN_24);

							iText(200,150,gamer[3].name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(gamer[3].highs,g1,10);
							iText(300,150,g1,GLUT_BITMAP_TIMES_ROMAN_24);

					}
					else if(player.highs>=gamer[1].highs && player.highs<=gamer[0].highs)
					{
						    

						
						    iText(200,300,player.name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(player.highs,g1,10);
							iText(300,300,g1,GLUT_BITMAP_TIMES_ROMAN_24);  


						    iText(200,350,gamer[0].name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(gamer[0].highs,g1,10);
							iText(300,350,g1,GLUT_BITMAP_TIMES_ROMAN_24);

							iText(200,250,gamer[1].name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(gamer[1].highs,g1,10);
							iText(300,250,g1,GLUT_BITMAP_TIMES_ROMAN_24);

							iText(200,200,gamer[2].name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(gamer[2].highs,g1,10);
							iText(300,200,g1,GLUT_BITMAP_TIMES_ROMAN_24);

							iText(200,150,gamer[3].name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(gamer[3].highs,g1,10);
							iText(300,150,g1,GLUT_BITMAP_TIMES_ROMAN_24);

					}
					else if(player.highs>=gamer[2].highs && player.highs<=gamer[1].highs)
						{
						    

						
						    iText(200,250,player.name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(player.highs,g1,10);
							iText(300,250,g1,GLUT_BITMAP_TIMES_ROMAN_24);


						    iText(200,350,gamer[0].name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(gamer[0].highs,g1,10);
							iText(300,350,g1,GLUT_BITMAP_TIMES_ROMAN_24);

							iText(200,300,gamer[1].name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(gamer[1].highs,g1,10);
							iText(300,300,g1,GLUT_BITMAP_TIMES_ROMAN_24);

							iText(200,200,gamer[2].name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(gamer[2].highs,g1,10);
							iText(300,200,g1,GLUT_BITMAP_TIMES_ROMAN_24);

							iText(200,150,gamer[3].name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(gamer[3].highs,g1,10);
							iText(300,150,g1,GLUT_BITMAP_TIMES_ROMAN_24);

					}
						else if(player.highs>=gamer[3].highs && player.highs<=gamer[2].highs)
						{
						    

						
						    iText(200,200,player.name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(player.highs,g1,10);
							iText(300,200,g1,GLUT_BITMAP_TIMES_ROMAN_24);


						    iText(200,350,gamer[0].name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(gamer[0].highs,g1,10);
							iText(300,350,g1,GLUT_BITMAP_TIMES_ROMAN_24);

							iText(200,300,gamer[1].name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(gamer[1].highs,g1,10);
							iText(300,300,g1,GLUT_BITMAP_TIMES_ROMAN_24);

							iText(200,250,gamer[2].name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(gamer[2].highs,g1,10);
							iText(300,250,g1,GLUT_BITMAP_TIMES_ROMAN_24);

							iText(200,150,gamer[3].name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(gamer[3].highs,g1,10);
							iText(300,150,g1,GLUT_BITMAP_TIMES_ROMAN_24);

					}

						else if(player.highs<=gamer[3].highs)
						{
						    

						
						    iText(200,150,player.name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(player.highs,g1,10);
							iText(300,150,g1,GLUT_BITMAP_TIMES_ROMAN_24);


						    iText(200,350,gamer[0].name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(gamer[0].highs,g1,10);
							iText(300,350,g1,GLUT_BITMAP_TIMES_ROMAN_24);

							iText(200,300,gamer[1].name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(gamer[1].highs,g1,10);
							iText(300,300,g1,GLUT_BITMAP_TIMES_ROMAN_24);

							iText(200,250,gamer[2].name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(gamer[2].highs,g1,10);
							iText(300,250,g1,GLUT_BITMAP_TIMES_ROMAN_24);

							iText(200,200,gamer[3].name,GLUT_BITMAP_TIMES_ROMAN_24);
							_itoa(gamer[3].highs,g1,10);
							iText(300,200,g1,GLUT_BITMAP_TIMES_ROMAN_24);
					}
		    }
	
	
	  }
	if(p==1 && instruction==0 && hscore==0)
			iShowBMP(play.x2,play.y2,"play1.bmp");
	else if(in==1 && instruction==0 && hscore==0)
		iShowBMP(ins.x2,ins.y2,"ins1.bmp");
	else if(h==1 && instruction==0 && hscore==0)
			iShowBMP(hs.x2,hs.y2,"hs1.bmp");
	
	if(gameState==1)
	{
		//gameState=1;
	iShowBMP(0,0,"999.bmp");
	iSetColor(255,0,0);
	iFilledRectangle(xpaddle,ypaddle,gx,gy);
	iSetColor(0,165,0);
	iFilledCircle(xball,yball,10,100);
	
	
	
	for(i=0;i<5;i++)
	{
		iSetColor(192,192,192);
		iFilledRectangle(silver[i].x1,silver[i].y1,bx,by);
	}


	for(i=0;i<9;i++)
	{
		iSetColor(255,0,0);
		iFilledRectangle(red[i].x1,red[i].y1,bx,by);
	}


	for(i=0;i<9;i++)
	{
		iSetColor(0,0,255);
		iFilledRectangle(blue[i].x1,blue[i].y1,bx,by);
	}

	for(i=0;i<3;i++)
	{
		iSetColor(255,255,0);
		iFilledRectangle(yellow[i].x1,yellow[i].y1,bx,by);
	}
	char ch[100];
	iSetColor(83,255,255);
	_itoa(cnt,ch,10);
	iText(0,560,"SCORE: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255,89,89);
	iText(100,560,ch,GLUT_BITMAP_TIMES_ROMAN_24);
	
	}
	if(gameOver==1)
		{
			iShowBMP(0,0,"gameover.bmp");
			
	char ch[100];
	iSetColor(255,0,0);
	_itoa(cnt,ch,10);
	iText(0,560,"SCORE: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(100,560,ch,GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255,0,0);
	iRectangle(200,500,250,40);
	iText(230,560,"EnTeR YoUr nAmE",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255,165,255);
	iText(255,510,str,GLUT_BITMAP_TIMES_ROMAN_24);
	strcpy(player.name,str);
		player.highs=cnt;

		
		
		fp = fopen ("highscore.txt", "w+");
		if(fp!=NULL)
		fprintf(fp,"%s %d",player.name,player.highs);
		 fclose(fp);
      

	
	}
	
}




/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	
	
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
	if(mx>=play.x2 && mx<=play.x2+200 && my>=play.y2 && my<=play.y2+100 )
		gameState=1;

		if(mx>=ins.x2 && mx<=ins.x2+200 && my>=ins.y2 && my<=ins.y2+100)
		instruction=1;
		if(mx>=hs.x2 && mx<=hs.x2+200 && my>=hs.y2 && my<=hs.y2+100)
		hscore=1;
		//place your codes here	
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}
/*iPassiveMouseMove is called to detect and use 
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here
	int k,l;
	
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/
 p=0; h=0;in=0;
 if(mx>=play.x2 && mx<=play.x2+200 && my>=play.y2 && my<=play.y2+100)
 
 { p=1;h=0;in=0;}
 else if (mx>=hs.x2 && mx<=hs.x2+200 && my>=hs.y2 && my<=hs.y2+100)
	
 { p=0;h=1;in=0;}
 else if(mx>=ins.x2 && mx<=ins.x2+200 && my>=ins.y2 && my<=ins.y2+100)
	
 { p=0;h=0;in=1;}
 
 }


/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		exit(0);
		//do something with 'q'
	}
	if(key == 'b')
	{
		
		instruction=0;gameState=0;gameOver=0;hscore=0;
	}

	if(key == 'p')
	{
		iPauseTimer(timer1);
	
	}

	if(key == 'r'||key=='\r')
	{
		iResumeTimer(timer1);
	
	}
	if(key!='\b' && key!='\r')
	{
		str[indexNumber]=key;
		str[indexNumber+1]='\0';
		indexNumber++;
	}
	else if(key=='\b')
	{
		
		str[indexNumber]='\0';
		indexNumber--;
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	if(key == '\r' )
	{
		gameState=1;	
	}
	
	if(key ==  GLUT_KEY_RIGHT)
	{
		if(xpaddle<400)
			{
				xpaddle+=50;
		    }	
	}
	if(key ==  GLUT_KEY_LEFT)
	{
		if(xpaddle>0)
			{
				xpaddle-=50;
		    }	
	}
	//place your codes for other keys here
}
//
void setMenu()
{
	int p=200,q=350;
	play.x2=p-100;
	play.y2=q;
	hs.x2=p;
	hs.y2=q-150;
	ins.x2=p-100;
	ins.y2=q-300;
}

void setHighscore()
{
	char a[10]="shakib";char a1[10]="abir";char a2[10]="rakib";char a3[10]="asir";
	
		strcpy(gamer[0].name,a);
		strcpy(gamer[1].name,a1);
		strcpy(gamer[2].name,a2);
		strcpy(gamer[3].name,a3);
		gamer[0].highs=35;
		gamer[1].highs=65;
		gamer[2].highs=105;
		gamer[3].highs=40;
		
}

void setBrick()
{
	int x,y,i;	

    	for(i=0	,x=150,y=550;i<5;x=x+50)
	{
	
		silver[i].x1=x;
		silver[i].y1=y;
		i++;
	}
	for(i=0,x=50,y=500;i<9;x=x+50)
	{
		
		red[i].x1=x;
		red[i].y1=y;
		i++;
	}
	for(i=0,x=50,y=450;i<9;x=x+50)
	{
		
		blue[i].x1=x;
		blue[i].y1=y;
		i++;
	}
	for(i=0,x=200,y=400;i<3;x=x+50)
	{
		
		yellow[i].x1=x;
	    yellow[i].y1=y;
		i++;
	}
}





void CallSetTimer()
	{ 
		
		xball+=dx;
		yball+=dy;
		if(xball>=595||xball<=0)
		{
			dx*=-1;
		}
		if(yball>=595)
		{
			dy*=-1;
		}


		for(i=0;i<5;i++)
		{
			if(xball>=silver[i].x1 && xball-10<=silver[i].x1+bx)
			{
			
				if(yball>=silver[i].y1 && yball-10<silver[i].y1+by)
				{
					
					dy*=-1;
					silver[i].x1 = -100;
					silver[i].y1 = -100;
					cnt=cnt+5;

				}
			}
		
		}

		for(i=0;i<9;i++)
		{
			if(xball>=red[i].x1 && xball<=red[i].x1+bx)
			{
				if(yball>=red[i].y1 && yball<=red[i].y1+by)
				{
					
					dy*=-1;
					red[i].x1 = -100;
					red[i].y1 =-100;
					cnt=cnt+5;
				}
			}
			
		}

		for(i=0;i<9;i++)
		{
			if(xball>=blue[i].x1 && xball<=blue[i].x1+bx)
			{
				if(yball>=blue[i].y1 && yball<=blue[i].y1+by)
				{
					dy*=-1;
					blue[i].x1 = -100;
					blue[i].y1 =-100;
					cnt=cnt+5;

				}
			}
		
		}

		for(i=0;i<3;i++)
		{
			if(xball>=yellow[i].x1 && xball<=yellow[i].x1+bx)
			{
				if(yball>=yellow[i].y1 && yball<=yellow[i].y1+by)
				{
					
					dy*=-1;
					yellow[i].x1 = -100;
				    yellow[i].y1 = -100;
					cnt=cnt+5;
				}
			}
		
		}




		if(xball>=xpaddle && xball<=xpaddle+gx && yball>=ypaddle && yball<=ypaddle+gy)
		{
		
			dy*=-1;

			/*theta=(xpaddle+gx-xball)-10;
		    dx=velocity*cos(theta*pi/180);
			dy=velocity*sin(theta*pi/180);*/
		}
		else if(yball<gy || cnt==130)
		{
			
			gameOver=1;
		}

}



int main()
{
	//place your own initialization codes here. 
	setHighscore();
	setMenu();
	setBrick();  
	indexNumber=strlen(str);
	timer1=iSetTimer(10,CallSetTimer);
	iPauseTimer(timer1);
	iInitialize(600, 600, "BRICK BREAKER");

	return 0;
}	


