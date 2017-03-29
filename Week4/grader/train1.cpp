#include <iostream>
#include <stdio.h>

using namespace std;
typedef int valueType;
const int MAX_STATION = 100010;

struct ListNode {
  ListNode* next;
  ListNode* prev;
  valueType num;
  valueType station;

  ListNode(valueType num, valueType station, ListNode* next = 0, ListNode* prev = 0)
    : num(num), station(station), next(next) {}
};

class LinkedList {
private:
  ListNode* header;
  ListNode* head[MAX_STATION];
  ListNode* tail[MAX_STATION];
  void free_list();

public:
  LinkedList();
  ~LinkedList();
  void print_list();
  void insert_train(valueType num, valueType station);
  void swap_station(valueType oldStation, valueType newStation);
  bool is_empty();
};

LinkedList::LinkedList() {
  header = new ListNode(0, 0);

  for (int i = 0; i < MAX_STATION; i++) {
    head[MAX_STATION] = tail[MAX_STATION] = '\0';
  }
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

void LinkedList::insert_train(valueType num, valueType station) {
  ListNode* trav = header;
  ListNode* newNode = new ListNode(num, station);

  if (is_empty()) {
    trav->next = newNode;
    newNode->prev = trav;
    head[station] = newNode;
    tail[station] = newNode;
  } else {
    while (trav->next != 0 && trav->next->station <= station) {
      trav = trav->next;
      //printf("hello\n");
    }

    newNode->next = trav->next;
    if (trav->next != 0) {
      trav->next->prev = newNode;
    }
    trav->next = newNode;
    newNode->prev = trav;

    if (head[station] == '\0') {
      head[station] = newNode;
      tail[station] = newNode;
    } else {
      tail[station] = newNode;
    }
  }
}

void LinkedList::swap_station(valueType oldStation, valueType newStation) {
  ListNode* trav = head[oldStation]->prev;

  while (trav->next != 0 && trav->next->station == oldStation) {
    trav = trav->next;
    trav->station = newStation;
    //printf("hello\n");
  }
  //printf("hello\n");
  if (head[newStation] != '\0') {
    head[oldStation]->prev->next = tail[oldStation]->next;

    if (tail[oldStation]->next != 0) {
      tail[oldStation]->next->prev = head[oldStation]->prev;
    }

    tail[oldStation]->next = tail[newStation]->next;
    tail[newStation]->next = head[oldStation];
    head[oldStation]->prev = tail[newStation];

    tail[newStation] = tail[oldStation];
    head[oldStation] = '\0';
    tail[oldStation] = '\0';
  }
}

bool LinkedList::is_empty() {
  if (header->next == 0) {
    return true;
  }

  return false;
}

int main() {
  LinkedList trainList;
  int n;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    char op;
    int x, y;

    scanf("%*c");
    scanf("%c %d %d", &op, &x, &y);

    if (op == 'N') {
      trainList.insert_train(x, y);
      //trainList.print_list();
    } else if (op == 'M') {
      trainList.swap_station(x, y);
      //trainList.print_list();
    }
  }

  trainList.print_list();

  return 0;
}
