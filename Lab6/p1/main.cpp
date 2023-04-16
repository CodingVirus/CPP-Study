#include <iostream>
using namespace std;

void printArray(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << i + 1 << " 번: " << *(arr + i)  << endl;
  }
}

void initializeArray(int *arr, int size) {
  srand((unsigned int)time(0));
  for (int i = 0; i < size; i++) {
    *(arr + i) = rand() % 100;
  }
}

void sortArray(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size-1-i; j++) {
      if (*(arr + j) > *(arr + j +1)) {
        int count = *(arr + j);
        *(arr + j) = *(arr + j +1);
        *(arr + j +1) = count;
      }
    }
  }
  printArray(arr,size);
}

int main() {
  int arr[20];
  int size = sizeof(arr)/sizeof(int);
  initializeArray(arr,size);
  sortArray(arr, size);
}