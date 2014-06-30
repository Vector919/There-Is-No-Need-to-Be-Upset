#include "DarkGDK.h"
#include "music.h"
#include "player.h"
#include "world.h"
#include "game.h"
#include "menu.h"


void DarkGDK ( void )
{


	gInit();
	dbSyncOn   ( );
	dbSyncRate ( 60 );
	dbRandomize(dbTimer());
	hndMusic();
	fillWorld();
	
	gorillaMunch gmn("sprites/trev2.png");
	Enemy lg1("sprites/rustle.png");
	prize trevor("sprites/munch.png");
	dbLoadImage("sprites/play.png",15);
	dbLoadImage("sprites/howtoplay.png",14);
	dbLoadImage("sprites/cursor.png",16);

	

	while ( LoopGDK ( ) )
	{
		if(menu == false)
		{
			MainMenu();
		}
			if(menu ==true){
	
			gmn.move();
			lg1.move(gmn.gx,gmn.gy);
			drawJimmies(jimmies,25);
			lg1.loseGame();
			trevor.hndPrize();
			hndJimmies();
			}
		
	
		
		// update the screen
		dbSync ( );
		
	}

	// return back to windows
	return;
}