#include "DarkGDK.h"
	int sx = 0;
	int sy = 0;
	int size_taken = 0;
void fillWorld()
{
	dbLoadImage("sprites/grass.png",2);
	int size_taken = 0;
	int spr_num = 4;

	//first tile
	dbSprite(3,0,0,2);

	sx = dbSpriteWidth(3);
	int csx = dbSpriteWidth(3);
	int csy = dbSpriteHeight(3);
	//dbDeleteSprite(3);
	//dbPasteImage(2,0,0);

	while (sy <= dbScreenHeight())
	{
		
		while(sx < dbScreenWidth())
		{
			//Paste the next tile where the last one ended
			dbSprite(spr_num,sx,sy,2);
			spr_num++;
			sx = sx+csx;
		}
		sx = 0;
		sy=sy+csy;	
		//size_taken+=sy;
		


	
		
	}

}