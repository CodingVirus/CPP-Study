#include <iostream>
using namespace std;

int main() {
  for (int i = 1; i < 10; ++i) {
    for (int j = 2; j < 10; ++ j) {
      int num1 = (i * j) / 10;
      int num2 = (i * j) % 10;
      if (num1 == 3 || num2 == 3 || num1 == 6 || num2 == 6 || num1 == 9 || num2 == 9 ) {
        cout << "\t\t\t";
        if ( j == 9) {
          cout << endl;
        }
        continue;
      }

      cout << j << " x " << i << " = " << i * j << "\t";

      if ( j == 9) {
        cout << endl;
      }
    }
  }
}