#pragma once
#include "Player.h"
class Game
{
public:
	
	Game(Player* player1, Player* player2) : player1(player1), player2(player2) {};
	void run(Field* field)
	{
		while (!field->isFull() && !field->hasLost() && !field->hasWon())
		{
			player1->doTurn(field);

			Player* player = player1;
			player1 = player2;
			player2 = player;

			field->switchPerspective();
		}

		if (field->hasWon())
		{
			player1->onWin();
			player2->onLose();
		}
		else if (field->hasLost())
		{
			player1->onLose();
			player2->onWin();
		}
		else
		{
			player1->onTie();
			player2->onTie();
		}

	}


private:
	Player* player1;
	Player* player2;
};