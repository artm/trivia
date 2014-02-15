#include <iostream>
#include <list>
#include <vector>
using namespace std;

#ifndef GAME_H_
#define GAME_H_

class Game {

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
  bool finished;

 public:
  const int WINNING_SCORE = 6;

  Game();
  string createQuestion(const string& category, int index);
  bool isPlayable();
  bool addPlayer(string playerName);

  int playerCount();
  void processRoll(int roll);

  bool isFinished();

 private:
  void askQuestion();
  string currentCategory();
  void movePlayer(int distance);
  void goToNextPlayer();

 public:
  void handleCorrectAnswer();
  void handleWrongAnswer();

};

#endif /* GAME_H_ */
