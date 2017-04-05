#include <iostream>

using namespace std;
typedef int valueType;

struct ListNode {
  valueType val;
  ListNode* next;

  ListNode(valueType val, ListNode* next = 0)
    : val(val), next(next) {}
};

class LinkedList {
private:
  ListNode* header;
  void free_list();

public:
  LinkedList();
  ~LinkedList();
  void print_list();
  void insert_front(valueType x);
  void delete_index(int k);
  void append(valueType x);
};

LinkedList::LinkedList() {
  header = new ListNode(0);
}

LinkedList::~LinkedList() {
  free_list();
}

void LinkedList::print_list() {
  ListNode* node = header->next;
  while (node != '\0') {
    cout << node->val << endl;
    node = node->next;
  }
}

void LinkedList::insert_front(valueType x) {
  ListNode* front = new ListNode(x);

  if (header->next == 0) {
    front->next = 0;
    header->next = front;
  } else {
    front->next = header->next;
    header->next = front;
  }
}

void LinkedList::free_list() {
  while (header->next != 0) {
    ListNode* del;
    del = header;
    header = header->next;
    delete del;
  }
}

void LinkedList::delete_index(int k) {
  int index = 0;
  ListNode* trav = header;

  while (trav->next != 0) {
    if (index == k - 1) {
      ListNode* del = trav->next;
      trav->next = del->next;
      del->next = 0;

      delete del;

      break;
    }

    trav = trav->next;
    index++;
  }
}

void LinkedList::append(valueType x) {
  ListNode* trav = header;
  ListNode* newNode = new ListNode(x);

  while (trav->next != 0) {
    trav = trav->next;
  }
  trav->next = newNode;
}

int main() {
  LinkedList list;
  int n, nbOfList;

  nbOfList = 0;
  cin >> n;

  for (int i = 0; i < n; i++) {
    char op;
    int x;

    cin >> op >> x;

    if (op == 'I') {
      list.insert_front(x);
      nbOfList++;
    } else if (op == 'A') {
      list.append(x);
      nbOfList++;
    } else if (op == 'D') {
      if (x <= nbOfList) {
        list.delete_index(x);
        nbOfList--;
      }
    }
  }

  list.print_list();

  return 0;
}
