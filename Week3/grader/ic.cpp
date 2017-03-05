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
  void append(valueType x);
  void left_rotate();
  void right_rotate();
  bool is_empty();
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

void LinkedList::append(valueType x) {
  ListNode* trav = header;
  ListNode* newNode = new ListNode(x);

  while (trav->next != 0) {
    trav = trav->next;
  }
  trav->next = newNode;
}

void LinkedList::left_rotate() {
  ListNode* node = header->next;
  ListNode* trav = header;

  header->next = node->next;
  node->next = 0;

  while (trav->next != 0) {
    trav = trav->next;
  }

  trav->next = node;
}

void LinkedList::right_rotate() {
  ListNode* prevTrav;
  ListNode* trav = header;

  while (trav->next->next != 0) {
    trav = trav->next;
  }
  prevTrav = trav;
  trav = trav->next;
  prevTrav->next = 0;
  trav->next = header->next;
  header->next = trav;
}

bool LinkedList::is_empty() {
  if (header->next == 0) {
    return true;
  }

  return false;
}

int main() {
  LinkedList list;
  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    char op[2];
    int x;

    cin >> op;

    if (op[0] == 'r' and op[1] == 'i') {
      cin >> x;
      list.append(x);
    } else if (op[0] == 'l' and op[1] == 'i') {
      cin >> x;
      list.insert_front(x);
    } else if (op[0] == 'l' and op[1] == 'r') {
      if (!list.is_empty()) {
        list.left_rotate();
      }
    } else if (op[0] == 'r' and op[1] == 'r') {
      if (!list.is_empty()) {
        list.right_rotate();
      }
    }
  }

  list.print_list();

  return 0;
}
