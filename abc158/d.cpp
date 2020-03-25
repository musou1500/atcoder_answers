#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
  char data;
  Node *next;
  Node *prev;
  Node(char data) : data(data), next(nullptr), prev(nullptr) {}
};

struct LinkedList {
  Node *top;
  Node *last;

  LinkedList() : top(nullptr), last(nullptr) {}

  void reset(char ch) {
    Node *node = new Node(ch);
    top = last = node;
  }

  void append(char ch) {
    if (top == nullptr) {
      reset(ch);
      return;
    }

    Node *node = new Node(ch);
    Node *old_last = last;
    last = node;
    old_last->next = node;
    last->prev = old_last;
  }

  void prepend(char ch) {
    if (top == nullptr) {
      reset(ch);
      return;
    }
    
    Node *node = new Node(ch);
    Node *old_top = top;
    top = node;
    top->next = old_top;
    old_top->prev = node;
  }
};

int main(int argc, const char *argv[])
{
  string s;
  int q;
  cin >> s >> q;

  Node* top, *last;
  LinkedList list;
  for (int i = 0; i < s.size(); i++) {
    list.prepend(s[i]);
  }
  
  bool reversed = false;
  for (int i = 0; i < q; i++) {
    int ti;
    cin >> ti;
    if (ti == 1) {
      reversed = !reversed;
    } else {
      int fi;
      char ci;
      cin >> fi >> ci;
      
      if ((fi == 1 && !reversed) || (fi != 1 && reversed)) {
        list.append(ci);
      } else {
        list.prepend(ci);
      }
    }
  }

  Node *cur = reversed ? list.top : list.last;
  while(cur != nullptr) {
    cout << cur->data;
    if (!reversed) {
      cur = cur->prev;
    } else {
      cur = cur->next;
    }
  }

  cout << "\n";

  return 0;
}
