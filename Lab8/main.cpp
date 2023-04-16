#include <iostream>
#include <stdlib.h>
using namespace std;

int getPlayerNum() {
  int playerN;
  cout << "How many player? : ";
  cin >> playerN;

  if (playerN > 0 && playerN < INT32_MAX) {
    return playerN;
  }
  else {
    cout << "Please enter the correct number." << endl;
    return getPlayerNum();
  }
}


class Player {
  private:
    //static int order;
    //int waiting;
  public:
    Player(){}
    Player(int playerN);
    int totalN;
    int id=0;
    int random;
    bool done;
    bool play();
    bool isOver();
    void print();
};

class TimingGame {
  private:
    static int curTime;
    int totalN;
    Player** players;

  public:
    void PlayerId(int playerN);
    void setTime();
    TimingGame(int playerN);
    void simulateGame();
    ~TimingGame() {
      delete[] players;
    }
};


TimingGame::TimingGame(int playerN) {
  players = new Player* [playerN];
  totalN = playerN;
  for (int i = 0; i < playerN; i++) {
    players[i] = new Player;
  }
}

void TimingGame::PlayerId(int playerN) {
  totalN = playerN;
  for (int i = 0; i < playerN; i++) {
    players[i] -> id = i+1;
    players[i] -> done = false;
  }
}

void TimingGame::setTime() {
  for (int i = 0; i < totalN; i++) {
    int x = rand() % totalN;
    players[i] -> random = x;
  }
}

void TimingGame::simulateGame() {
  PlayerId(totalN);
  setTime();
  int count = 0;
  for (int i = 0; i < totalN; i++) {
    cout << players[i]->id << " says I pick up " << players[i]->random << endl;
  }

  for (int j = 0; j < totalN; j++) {
    if (count > 1) {
      break;
    }
    count = 0;
    cout << j << "-th turn" << endl;
    for (int k = 0; k < totalN; k++) {
      if (j == players[k]->random) {
        count++;
        cout << players[k] -> id <<" says I am here" << endl;
        if (count > 1) {
          cout << "game is over with conflict at " << j << "-th turn" << endl;
          cout << players[k] -> id << " lost the game." << endl;
          break;
        }
      }
    }
  }
}

void Player::print() {
  
}

int main() {
  int playerN = getPlayerNum();
  TimingGame game1 = TimingGame(playerN);
  game1.simulateGame();
}