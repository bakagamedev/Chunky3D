#include <Arduboy2.h>
#include "System.h"
#include "Game.h"
#include "Portal.h"
#include "Types.h"
#include "ProgmemArray.h"

System sys = System();
Game game = Game(sys);

void setup()
{
	sys.begin();
	sys.setFrameRate(60);
	game.Load();
}

void loop()
{	
	game.Draw();
}