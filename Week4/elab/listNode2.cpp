#include <iostream>

using namespace std;

typedef int valueType;

struct ListNode
{
  valueType val;
  ListNode* next;

  ListNode(valueType val, ListNode* next=0)
    : val(val), next(next) {}
};

void print_list(ListNode* node)
{
  while(node != 0) {
    cout << node->val << endl;
    node = node->next;
  }
}

void insert_front(ListNode* header, valueType x)
{
  ListNode* front = new ListNode(x);

  if (header->next != 0) {
    front->next = header->next;
    header->next = front;
  } else {
    header->next = front;
  }
}

main()
{
  ListNode* header = new ListNode(0);

  while(true) {
    int x;
    cin >> x;

    if(x == 0) {
      break;
    }
    insert_front(header,x);
  }

  print_list(header->next);
}
