#include <iostream>

using namespace std;

int main () {
  int price1, price2, price3, sumPrice1, sumPrice2, sumPrice3, num, check, minPrice;

  sumPrice1 = 0;
  sumPrice2 = 0;
  sumPrice3 = 0;

  minPrice = 0;

  cin >> price1 >> price2 >> price3;
  cin >> num;

  for (int i = 0; i < num; i++) {
    cin >> check;

    switch (check) {
      case 1:
        sumPrice1 += price1;
        break;
      case 2:
        sumPrice2 += price2;
        break;
      case 3:
        sumPrice3 += price3;
        break;
      default:
        break;
    }
  }

  minPrice = min(min(sumPrice1, sumPrice2), sumPrice3);

  cout << minPrice << endl;

  return 0;
}
