#include "DarkGDK.h"
void hndMusic()
{
	if (dbFileExist("music/munch.mp3"))
	{
		dbLoadMusic("music/munch.mp3",1);
		//dbPrint("Music Loading");
		if(dbMusicExist(1))
			//dbPrint("Music Loaded");

		dbLoopMusic(1);
	}
	
	
}