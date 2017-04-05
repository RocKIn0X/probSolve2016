#include <iostream>
#include <stdio.h>

using namespace std;
typedef int valueType;
const int MAX_STATION = 100010;

struct ListNode {
  ListNode* next;
  valueType num;

  ListNode(valueType num, ListNode* next = 0)
    : num(num), next(next) {}
};

class LinkedList {
private:
  void free_list();

public:
  LinkedList();
  ~LinkedList();
  ListNode* header;
  ListNode* tail;
  void print_list();
  void insert_train(valueType num);
  void swap_station();
  bool is_empty();
};

LinkedList::LinkedList() {
  header = new ListNode(0);
  tail = header;
}

LinkedList::~LinkedList() {
  free_list();
}

void LinkedList::print_list() {
  ListNode* node = header->next;
  while (node != '\0') {
    printf("%d\n", node->num);
    node = node->next;
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

void LinkedList::insert_train(valueType num) {
  ListNode* node = new ListNode(num);

  if (header->next == '\0') {
    header->next = node;
    tail = node;
  } else {
    tail->next = node;
    tail = node;
  }

}

void LinkedList::swap_station() {

}

bool LinkedList::is_empty() {
  if (header->next == 0) {
    return true;
  }

  return false;
}

int main() {
  LinkedList** stationList = new LinkedList*[MAX_STATION];
  int n;

  scanf("%d", &n);

  for (int i = 0; i < MAX_STATION; i++) {
    stationList[i] = new LinkedList();
  }

  for (int i = 0; i < n; i++) {
    char op;
    int x, y;

    scanf("%*c");
    scanf("%c %d %d", &op, &x, &y);

    if (op == 'N') {

      stationList[y]->insert_train(x);
      //cout << "hello" << endl;
    } else if (op == 'M') {

      if (stationList[x]->header->next != 0) {
        stationList[y]->tail->next = stationList[x]->header->next;
        stationList[y]->tail = stationList[x]->tail;

        stationList[x]->header->next = 0;
        stationList[x]->tail = stationList[x]->header;
      }
    }
  }

  for (int i = 0; i < MAX_STATION; i++) {
    if (stationList[i]->header->next != 0) {
      stationList[i]->print_list();
    }
  }

  return 0;
}
