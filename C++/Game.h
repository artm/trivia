#include <iostream>
#include <list>
#include <vector>
using namespace std;

#ifndef GAME_H_
#define GAME_H_

class Game{

 private:
  vector<string> players;

  int playerPlace[6];
  int playerPurse[6];
  bool playerInPenaltyBox[6];

  list<string> popQuestions;
  list<string> scienceQuestions;
  list<string> sportsQuestions;
  list<string> rockQuestions;

  int currentPlayerIndex;
  bool isGettingOutOfPenaltyBox;

 public:
  Game();
  string createRockQuestion(int index);
  bool isPlayable();
  bool addPlayer(string playerName);

  int playerCount();
  void processRoll(int roll);

 private:
  void askQuestion();
  string currentCategory();

 public:
  bool wasCorrectlyAnswered();
  bool wrongAnswer();

 private:
  bool didPlayerNotWin();
};

#endif /* GAME_H_ */
