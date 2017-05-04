
#include <iostream>

using namespace std;

void sendPtrToBack (char num[], char*& ptr) {
  while (*ptr != '\0') {
    ptr++;
  }
  ptr--;
}

void sum(char*& ptr1, char*& ptr2, char* first1, char* first2) {
  int c = 0;
  int sum = 0;

  while (ptr1 != first1 - 1  and ptr2 != first2 - 1) {
    if (ptr1 == first1 - 1) {
      cout << ((int)(*ptr2)) + c;
      c = 0;
      ptr2--;
      continue;
    } else if (ptr2 == first2 - 1) {
      cout << ((int)(*ptr1)) + c;
      c = 0;
      ptr1--;
      continue;
    }
    sum = (int)(*ptr1) + (int)(*ptr2);
    c = sum / 10;
    sum = sum % 10;

    cout << sum;

    ptr1--;
    ptr2--;
  }

  cout << endl;
}

main () {
  char num1[302];
  char num2[302];
  char* num1Ptr;
  char* num2Ptr;
  char* first1;
  char* first2;

  num1Ptr = first1 = num1;
  num2Ptr = first2 = num2;

  cin >> num1 >> num2;

  sendPtrToBack(num1, num1Ptr);
  sendPtrToBack(num2, num2Ptr);

  sum(num1Ptr, num2Ptr, first1, first2);
}
