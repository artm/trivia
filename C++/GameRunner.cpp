#include <stdlib.h>
#include "Game.h"

static bool notAWinner;

int main()
{
  srand(42);

	Game aGame;

	aGame.addPlayer("Chet");
	aGame.addPlayer("Pat");
	aGame.addPlayer("Sue");

	do
	{

		aGame.processRoll(rand() % 5 + 1);

		if (rand() % 9 == 7)
		{
			 aGame.handleWrongAnswer();
		}
		else
		{
			 aGame.handleCorrectAnswer();
		}
	} while (!aGame.isFinished());

}
