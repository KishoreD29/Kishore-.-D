#include <iostream>

using namespace std;

class details_check {
public:
  bool display(int arr[][3]) {
    int accno, psw;
    cout << "Enter account number: ";
    cin >> accno;
    cout << "Enter account password: ";
    cin >> psw;
    for (int i = 0; i < 5; i++) {
      if (arr[i][0] == accno && arr[i][1] == psw) {
        return true;
      }
    }
    return false;
  }
};

class withdrawal {
public:
  void performWithdrawal(int arr[][3]) {
    int accno, amount;
    cout << "Enter account number: ";
    cin >> accno;
    cout << "Enter withdrawal amount: ";
    cin >> amount;
    for (int i = 0; i < 5; i++) {
      if (arr[i][0] == accno) {
        if (arr[i][2] >= amount) {
          arr[i][2] -= amount;
          cout << "Withdrawal successful. Updated balance: " << arr[i][2] << endl;
        } else {
          cout << "Insufficient balance for withdrawal." << endl;
        }
        return;
      }
    }
    cout << "Account not found." << endl;
  }
};

class deposit {
public:
  void performDeposit(int arr[][3]) {
    int accno, amount;
    
    cout << "Enter account number: ";
    cin >> accno;
    cout << "Enter deposit amount: ";
    cin >> amount;
    for (int i = 0; i < 5; i++) {
      if (arr[i][0] == accno) {
        arr[i][2] += amount;
        cout << "Deposit successful. Updated balance: " << arr[i][2] << endl;
        
        return;
      }
    }
    cout << "Account not found." << endl;
  }
};

int main() {
  int l;
  cout << "Enter the number of details to be initialized first: ";
  cin >> l;

  int a[l][3];
  for (int i = 0; i < l; i++) {
    cout << "Enter the account number for registering: ";
    cin >> a[i][0];
    cout << "Enter the account password: ";
    cin >> a[i][1];
    cout << "Enter the account balance: ";
    cin >> a[i][2];
  }

  for (int i = 0; i < l; i++) {
    cout << "Account " << a[i][0] << " Balance: " << a[i][2] << endl;
  }

  details_check obj;
  if (obj.display(a)) {
    cout << "Options:\n1) Withdraw\n2) Deposit\nEnter option: ";

    int choice;
    cin >> choice;

    withdrawal withdrawObj;
    deposit depositObj;

    switch (choice) {
    case 1:
      withdrawObj.performWithdrawal(a);
      break;
    case 2:
      depositObj.performDeposit(a);
      break;
    default:
      cout << "Invalid option." << endl;
    }
  } else {
    cout << "Invalid account credentials." << endl;
  }

  return 0;
}
