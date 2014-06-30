#include "DarkGDK.h"
#include <stdlib.h> 
#include <ctime>

int jimmies = 100;
bool rustled = false;
int sc_w = dbScreenWidth()-50;
int sc_h = dbScreenHeight()-70;
#define TEXTSIZE 35

void resetJimmies()
{
	jimmies = 100;
}
void hndJimmies()
{
	if(jimmies <=0)
	{
	dbText(50,50,"MAXIMUM UNRUSTLEMENT (you win!)");
	}

}
class Enemy
{
public:
	float ex;
	float ey;
	float speed;
	int time;
	
	Enemy(char *image)
	{
	dbLoadImage(image,5);
	dbSprite(25,dbRND(dbScreenWidth()),dbRND(dbScreenHeight()),5);
	ex = dbSpriteX(25);
	ey = dbSpriteY(25);
	dbScaleSprite(25,50);
	speed = .4;
	time = 100;
	}
	void move(int px, int py)
	{
		if(dbSpriteX(25) < px)
		{
			ex = ex+speed;
		}
		if(dbSpriteX(25) > px)
		{
			ex = ex-speed;
		}
		if(dbSpriteY(25) < py)
		{
			ey = ey+speed;
		}
		if(dbSpriteY(25) > py)
		{
			ey = ey-speed;
		}
		if(rustled == false)
		{
			dbSprite(25,ex,ey,5);
		}


	}
	void loseGame()
	{
		
		if(dbSpriteCollision(1,25))
		{
			ex = dbRND(sc_w);
			ey = dbRND(sc_h);
			rustled = true;
			time = 100;
			
			
		}
		if (rustled == true)
		{
			dbText(50,50,"THERE IS NO NEED TO BE UPSET (you lost)");
			resetJimmies();
			time--;

		}
		if (time == 0&& rustled == true)
		{
					
			rustled = false;
		}
	}
};
class prize
{
public:

	prize(char *image)
	{
		
		dbLoadImage(image,7);
		dbSprite(26,rand()%sc_w,rand()%sc_h,7);
		dbScaleSprite(26,10);
		srand(time(NULL));
	
	}
	void hndPrize()
	{
		if(dbSpriteCollision(26,1))
		{
			jimmies = jimmies-10;
			dbDeleteSprite(26);
			dbSprite(26,rand()%dbScreenWidth(),rand()%dbScreenHeight(),7);
			dbScaleSprite(26,10);

		}

	}
};



void gInit()
{		
		dbDrawSpritesFirst();
		//THIS ALLOWS US TO DRAW OVER THE SPRITES
		dbSetTextFont("Comic Sans MS");
		dbSetTextSize(TEXTSIZE);
		//FONT
}