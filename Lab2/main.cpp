#include <iostream>
using namespace std;

int main() {
  for (int i = 1; i < 10; ++i) {
    for (int j = 2; j < 10; ++ j) {
      cout << j << " x " << i << " = " << i * j << "\t";
      if ( j == 9) {
        cout << endl;
      }
    }
  }
}