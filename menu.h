#include "DarkGDK.h"

bool menu = false;
bool ins = false;

void MainMenu()
{
	
	dbText(100,50,"THERE IS NO NEED TO BE UPSET");
	dbText(100,100,"(a game by kirt gittens & rotterdam)");
	dbSprite(30,50,300,15);
	dbSprite(31,250,300,14);

	dbSprite(32,dbMouseX(),dbMouseY(),16);
	dbHideSprite(16);

	if(dbSpriteCollision(32,30) &&dbMouseClick())
	{
		dbHideSprite(31);
		dbHideSprite(30);
		menu = true;
		
	}

	if(dbSpriteCollision(32,31)&&dbMouseClick())
	{
		ins = true;
			
	}
	if(ins ==true)
	{
		dbText(100,200,"use arrow keys to juke");	
		
	}

}
void destroyMenu()
{
	
}