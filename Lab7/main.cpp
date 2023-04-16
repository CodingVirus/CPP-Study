#include <iostream>
using namespace std;

struct product{
  string  name;
  int     num;
  int     price;
};

class VM{
  private:
    string arr[3] = {"coke", "juice", "water"};
    struct product coke;
    struct product juice;
    struct product water;
    struct product* cokeInfo = &coke;
    struct product* juiceInfo = &juice;
    struct product* waterInfo = &water;
    int mChoice;
    int mMoney;
    
    void showState(){
      /* 현재 자판기 객체가 가지고 있는 각각의 음료의 가격과 남은 재고를 출력해 주는 함수 */
      cout << "Currently I have.." << endl;
      cout << cokeInfo -> name << " - " << "[price : "<< cokeInfo -> price << "] " << "[num : " << cokeInfo -> num << "]" << endl;
      cout << juiceInfo -> name << " - " << "[price : "<< juiceInfo -> price << "] " << "[num : " << juiceInfo -> num << "]" << endl;
      cout << waterInfo -> name << " - " << "[price : "<< waterInfo -> price << "] " << "[num : " << waterInfo -> num << "]" << endl;
    }

    bool getUserChoice(){
      /* 사용자의 선택(음료)을 입력 받는 함수.  */
      cout << "Input your choice: 1) coke 2) juice 3) water : ";
      cin >> mChoice;

      if (mChoice == 1) {
        getUserMoney();
        process();
      }
      else if (mChoice == 2) {
        getUserMoney();
        process();
      }
      else if (mChoice == 3) {
        getUserMoney();
        process();
      }
      else {
        cout << "--- You choice invalid option, try again ---" << endl;
        return false;
      }

      return true;
    }

    bool getUserMoney(){
      /* 사용자의 돈을 입력 받는 함수 */
      cout << "Input money for your choice : ";
      cin >> mMoney;
      
      
      if (mMoney < 0) {
        cout << "--- Put in more money ---" << endl;
        return false;
      }

      else {
        return true;
      }
    }
    void process(){
      /* 사용자 입력을 처리하여, 재고량을 업데이트해서 화면에 출력하고 
      사용자에게 음료 및 잔돈을 돌려주며 이 내용들을 출력하는 함수. */
      if (mChoice == 1) {
        int change;
        cout << "Here is your beverage, " << cokeInfo -> name << endl;
        change = mMoney - cokeInfo -> price;
        if (change < 0) {
          cout << "--- Put in more money ---" << endl;
          getUserChoice();
        }
        cout << "Here is your change, " << change << endl;
        cokeInfo -> num = cokeInfo -> num - 1;
        showState();
      }
      else if (mChoice == 2) {
        int change;
        cout << "Here is your beverage, " << juiceInfo -> name << endl;
        change = mMoney - juiceInfo -> price;
        if (change < 0) {
          cout << "--- Put in more money ---" << endl;
          getUserChoice();
        }
        cout << "Here is your change, " << change << endl;
        juiceInfo -> num = juiceInfo -> num - 1;
        showState();
      }
      else if (mChoice == 3) {
        int change;
        cout << "Here is your beverage, " << waterInfo -> name << endl;
        change = mMoney - waterInfo -> price;
        if (change < 0) {
          cout << "--- Put in more money ---" << endl;
          getUserChoice();
        }
        cout << "Here is your change, " << change << endl;
        waterInfo -> num = waterInfo -> num - 1;
        showState();
      }
    }

  public:
    VM(){
      /* 자판기 객체가 처음으로 만들어질 때, 각 물품의 이름, 가격, 재고를 인자로 받아서 설정*/
        cokeInfo -> name = arr[0];
        cout << "Input # of " << arr[0] << " : ";
        cin >> cokeInfo -> num;
        cout << "Input the price of " << arr[0] << " : ";
        cin >> cokeInfo -> price;

        juiceInfo -> name = arr[1];
        cout << "Input # of " << arr[1] << " : ";
        cin >> juiceInfo -> num;
        cout << "Input the price of " << arr[1] << " : ";
        cin >> juiceInfo -> price;

        waterInfo -> name = arr[2];
        cout << "Input # of " << arr[2] << " : ";
        cin >> waterInfo -> num;
        cout << "Input the price of " << arr[2] << " : ";
        cin >> waterInfo -> price;

        cout << "Vending machine is ready" << endl;
    }

    void operate(){
      /* 자판기 객체를 동작시키는 함수. */
      showState();

      while(1) {
        getUserChoice();
      }
    }

    ~VM(){
      /* 자판기 객체의 Dynamic memory allocation 해제 */
      delete juiceInfo;
      delete cokeInfo;
      delete waterInfo;
    }
};

int main() {
  VM vm;
  vm.operate();
}