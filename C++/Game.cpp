#include "Game.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

using namespace std;

Game::Game() : currentPlayerIndex(0), playerPlace({}), playerPurse({}){
	for (int i = 0; i < 50; i++)
	{

		ostringstream oss (ostringstream::out);
		oss << "Pop Question " << i;

		popQuestions.push_back(oss.str());

		char str[255];
		sprintf(str, "Science Question %d", i);
		scienceQuestions.push_back(str);

		char str1[255];
		sprintf(str1, "Sports Question %d", i);
		sportsQuestions.push_back(str1);

		rockQuestions.push_back(createRockQuestion(i));
	}
}

string Game::createRockQuestion(int index)
{
	char indexStr[127];
	sprintf(indexStr, "Rock Question %d", index);
	return indexStr;
}

bool Game::isPlayable()
{
	return (playerCount() >= 2);
}

bool Game::addPlayer(string playerName){
	players.push_back(playerName);
	playerPlace[playerCount()] = 0;
	playerPurse[playerCount()] = 0;
	playerInPenaltyBox[playerCount()] = false;

	cout << playerName << " was added" << endl;
	cout << "They are player number " << players.size() << endl;
	return true;
}

int Game::playerCount()
{
	return players.size();
}

void Game::processRoll(int roll)
{
	cout << players[currentPlayerIndex] << " is the current player" << endl;
	cout << "They have rolled a " << roll << endl;

	if (playerInPenaltyBox[currentPlayerIndex])
	{
		if (roll % 2 != 0)
		{
			isGettingOutOfPenaltyBox = true;

			cout << players[currentPlayerIndex] << " is getting out of the penalty box" << endl;
			playerPlace[currentPlayerIndex] = playerPlace[currentPlayerIndex] + roll;
			if (playerPlace[currentPlayerIndex] > 11) playerPlace[currentPlayerIndex] = playerPlace[currentPlayerIndex] - 12;

			cout << players[currentPlayerIndex] << "'s new location is " << playerPlace[currentPlayerIndex] << endl;
			cout << "The category is " << currentCategory() << endl;
			askQuestion();
		}
		else
		{
			cout << players[currentPlayerIndex] << " is not getting out of the penalty box" << endl;
			isGettingOutOfPenaltyBox = false;
		}

	}
	else
	{

		playerPlace[currentPlayerIndex] = playerPlace[currentPlayerIndex] + roll;
		if (playerPlace[currentPlayerIndex] > 11) playerPlace[currentPlayerIndex] = playerPlace[currentPlayerIndex] - 12;

		cout << players[currentPlayerIndex] << "'s new location is " << playerPlace[currentPlayerIndex] << endl;
		cout << "The category is " << currentCategory() << endl;
		askQuestion();
	}

}

void Game::askQuestion()
{
	if (currentCategory() == "Pop")
	{
		cout << popQuestions.front() << endl;
		popQuestions.pop_front();
	}
	if (currentCategory() == "Science")
	{
		cout << scienceQuestions.front() << endl;
		scienceQuestions.pop_front();
	}
	if (currentCategory() == "Sports")
	{
		cout << sportsQuestions.front() << endl;
		sportsQuestions.pop_front();
	}
	if (currentCategory() == "Rock")
	{
		cout << rockQuestions.front() << endl;
		rockQuestions.pop_front();
	}
}


string Game::currentCategory()
{
	if (playerPlace[currentPlayerIndex] == 0) return "Pop";
	if (playerPlace[currentPlayerIndex] == 4) return "Pop";
	if (playerPlace[currentPlayerIndex] == 8) return "Pop";
	if (playerPlace[currentPlayerIndex] == 1) return "Science";
	if (playerPlace[currentPlayerIndex] == 5) return "Science";
	if (playerPlace[currentPlayerIndex] == 9) return "Science";
	if (playerPlace[currentPlayerIndex] == 2) return "Sports";
	if (playerPlace[currentPlayerIndex] == 6) return "Sports";
	if (playerPlace[currentPlayerIndex] == 10) return "Sports";
	return "Rock";
}

bool Game::wasCorrectlyAnswered()
{
	if (playerInPenaltyBox[currentPlayerIndex])
	{
		if (isGettingOutOfPenaltyBox)
		{
			cout << "Answer was correct!!!!" << endl;
			playerPurse[currentPlayerIndex]++;
			cout << players[currentPlayerIndex]
			     << " now has "
			     << playerPurse[currentPlayerIndex]
				<<  " Gold Coins." << endl;

			bool noWinnerYet = didPlayerNotWin();
			currentPlayerIndex++;
			if (currentPlayerIndex == players.size()) currentPlayerIndex = 0;

			return noWinnerYet;
		}
		else
		{
			currentPlayerIndex++;
			if (currentPlayerIndex == players.size()) currentPlayerIndex = 0;
			return true;
		}



	}
	else
	{

		cout << "Answer was corrent!!!!" << endl;
		playerPurse[currentPlayerIndex]++;
		cout << players[currentPlayerIndex]
				<< " now has "
				<< playerPurse[currentPlayerIndex]
			<< " Gold Coins." << endl;

		bool noWinnerYet = didPlayerNotWin();
		currentPlayerIndex++;
		if (currentPlayerIndex == players.size()) currentPlayerIndex = 0;

		return noWinnerYet;
	}
}

bool Game::wrongAnswer()
{
	cout << "Question was incorrectly answered" << endl;
	cout << players[currentPlayerIndex] + " was sent to the penalty box" << endl;
	playerInPenaltyBox[currentPlayerIndex] = true;

	currentPlayerIndex++;
	if (currentPlayerIndex == players.size()) currentPlayerIndex = 0;
	return true;
}


bool Game::didPlayerNotWin()
{
	return !(playerPurse[currentPlayerIndex] == 6);
}
