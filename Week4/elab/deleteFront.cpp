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

class LinkedList
{
private:
  ListNode* header;
  ListNode* tail;
  void free_list();

public:
  LinkedList();
  ~LinkedList();
  void print_list();
  void insert_front(valueType x);
  void append(valueType x);

  valueType get_front();
  void delete_front();

  bool is_empty();
};

LinkedList::LinkedList()
{
  header = new ListNode(0);
  tail = header;
}

LinkedList::~LinkedList()
{
  free_list();
}

void LinkedList::print_list()
{
  ListNode* node = header->next;
  while(node != 0) {
    cout << node->val << endl;
    node = node->next;
  }
}

void LinkedList::insert_front(valueType x)
{
  ListNode* front = new ListNode(x);

  if (header->next == 0) {
    header->next = front;
    tail = tail->next;
  } else {
    front->next = header->next;
    header->next = front;
  }
}

void LinkedList::append(valueType x)
{
  ListNode* newNode = new ListNode(x);

  tail->next = newNode;
  tail = newNode;
}

void LinkedList::free_list()
{
  while (header->next != 0) {
    ListNode* del;
    del = header;
    header = header->next;
    delete del;
  }
}

bool LinkedList::is_empty()
{
  if (header->next == 0) {
    tail = header;
    return true;
  }
  return false;
}

valueType LinkedList::get_front()
{
  return header->next->val;
}

void LinkedList::delete_front()
{
  if(is_empty()) {
    throw "Error: list is empty.";
  }
  ListNode* front = header->next;

  if (front->next != 0) {
    header->next = front->next;
    front->next = 0;
  } else {
    header->next = 0;
    tail = header;
  }

  delete front;
}

main()
{
  LinkedList l1;

  l1.append(10);
  cout << l1.get_front() << endl;
  l1.insert_front(20);
  cout << l1.get_front() << endl;
  l1.delete_front();
  cout << l1.get_front() << endl;
  cout << (l1.is_empty() ? "yes" : "no") << endl;
  l1.delete_front();
  cout << (l1.is_empty() ? "yes" : "no") << endl;
  l1.append(100);
  cout << l1.get_front() << endl;
  l1.insert_front(200);
  cout << l1.get_front() << endl;
  l1.append(1000);
  l1.print_list();
  l1.delete_front();
  l1.delete_front();
  l1.print_list();
  l1.delete_front();
  cout << (l1.is_empty() ? "yes" : "no") << endl;
}
