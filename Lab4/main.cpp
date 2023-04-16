#include <iostream>
using namespace std;

int generateNumber(){
  srand(time(0));
  int firstDigit, secondDigit, thirdDigit;
  firstDigit = rand()%10 + 1; // 1~9사이의 난수를 생성
  
  do{
    secondDigit = rand()%10;
  }while(secondDigit == firstDigit);

  do{
    thirdDigit = rand()%10;
  }while(thirdDigit == firstDigit || thirdDigit == secondDigit);

  return firstDigit*100 + secondDigit*10 + thirdDigit;
}

bool testAnswer(int guess, int ans){
    bool res = false;
    int strike = 0;
    int ball = 0;
    int guessnum1 = guess / 100;
    int guessnum2 = (guess % 100) / 10;
    int guessnum3 = guess % 10;
    int ansnum1 = ans / 100;
    int ansnum2 = (ans % 100) / 10;
    int ansnum3 = ans % 10;

    if ((guessnum1 == ansnum1) || (guessnum2 == ansnum1) || (guessnum3 == ansnum1)) {
      if (guessnum1 == ansnum1) {
        strike++;
      }
      else {
        ball++;
      }
    }
    if ((guessnum1 == ansnum2) || (guessnum2 == ansnum2) || (guessnum3 == ansnum2)) {
      if (guessnum2 == ansnum2) {
        strike++;
      }
      else {
        ball++;
      }
    }
    if ((guessnum1 == ansnum3) || (guessnum2 == ansnum3) || (guessnum3 == ansnum3)) {
      if (guessnum3 == ansnum3) {
        strike++;
      }
      else {
        ball++;
      }
    }
    if (strike == 3) {
      cout << strike << " strikes, " << ball << " balls" << endl;
      res = true;
    }
    else {
      cout << strike << " strikes, " << ball << " balls" << endl;
    }
    return res;
}

int main(){
   int ans = generateNumber();
  
  while(1){
    int guess;
    cout << "\nInput your guess: ";
    cin >> guess;
    if(testAnswer(guess, ans)){
      cout << "You succeed!" << endl;
      break;
    } 
  }
   return 0;
}