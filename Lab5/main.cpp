#include <iostream>
#include <string>
using namespace std;

//  스트링의 마지막의 온점이 존재하는지 검사하는 함수
bool checkingEnd(string s){
  if (s[s.size()-1] == '.') {
    return true;
  }
  else {
    return false;
  }
}

// 조건을 만족할때 까지 사용쟈로부터 입력을 받는 함수.
string getUserInput(){
  while(1) {
    string input;
    cout << "Input your sentence (with puctuation): ";
    getline(cin, input);
  
    if (checkingEnd(input) == true) {
      return input;
      break;
    }
  }
}

// 스트링의 첫 글자가 모음인지 검사하는 함수
bool isVowel(string word){
  if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u') {
    return true;
  }
  else {
    return false;
  }
}

// 스트링이 올바른 스트링인지 검사하는 함수
//(올바른 스트링은 전체가 다 알파벳으로 구성 되어 있어야 함)

bool checkingWord(string word) {

  bool count = true;
  int input;
  
  input = atoi(word.c_str());

  if(input == 0 ) {
    return true;
  } 
  else {
    return false;
  }
}

// 입력 받은 스트링을 분류하는 함수
void vocaClassifier(string str){
  bool start = false;
  int vowel = 0;
  int consonant = 0;
  int others = 0;
  string word, count;
  
  str.insert(str.size() - 1, " ");
  for (int i = 0; i < str.size(); i++) {
    count = str[i];
    word.append(count);
    if (str[i] == ' ') {
        if (isVowel(word) == true) {
          cout << word << endl;
          vowel ++;
          word.clear();
        }
        else if(checkingWord(word) == true){
          cout << word << endl;
          consonant ++;
          word.clear();
        }
        else {
          cout << word << endl;
          others ++;
          word.clear();
        }
    }
  }

  cout << "# of vowel: " << vowel << endl;
  cout << "# of consonant : " << consonant << endl;
  cout << "# of others : " << others << endl;
}

//main 함수
int main() {
  string str;
  
  str = getUserInput();
  vocaClassifier(str);

  return 0;  
}