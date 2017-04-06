#include <map>
#include <cstdio>

using namespace std;

map<int, int> product;

int main() {
  int n, command, prodType, prodNum;
  const int maxProd = 2000000000;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d %d", &command, &prodType);

    if (command == 1) {

      scanf("%d", &prodNum);

      if (product[prodType] + prodNum <= maxProd){
        product[prodType] += prodNum;
      } else {
        product[prodType] = maxProd;
      }

    } else if (command == 2) {

      printf("%d\n", product[prodType]);

    } else if (command == 3) {

      scanf("%d", &prodNum);

      if (prodNum <= product[prodType]) {
        product[prodType] -= prodNum;
        printf("%d\n", prodNum);
      } else {
        printf("%d\n", product[prodType]);
        product[prodType] = 0;
      }

    }
  }


  return 0;
}
