#include "DarkGDK.h"
void drawJimmies(int jimmies,int size) //draws the jimmy spectrum on screen
{
	dbBox(0,0,jimmies,size);

}
//This is the player class
class gorillaMunch
{
public:
	int gx;
	int gy;
	
	gorillaMunch(char *image)
	{
		gx = dbScreenWidth()/2;
		gy = dbScreenHeight()/2;
		dbLoadImage(image,1);
		dbSprite(1,gx,gy,1);
		dbScaleSprite(1,20);
	}
	void move()
	{
		if(dbUpKey())
		{
			gy--;
		}
		if(dbDownKey())
		{
			gy++;
		}
		if(dbLeftKey())
		{
			gx--;
		}
		if(dbRightKey())
		{
			gx++;
		}
		//make sure we don't go off of the screen
		if(gx >= dbScreenWidth()-50)
		{
			gx = gx-1;
		}
		if(gx <= 0)
		{
			gx = gx+1;
		}
		if(gy <=0)
		{
			gy = gy+1; 
		}
		if(gy >= dbScreenHeight()-70)
		{
			gy = gy-1;
		}

		
		dbSprite(1,gx,gy,1);
		
	


	}


};
