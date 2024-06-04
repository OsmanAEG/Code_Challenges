#include <iostream>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  void reorderList(ListNode* head) {
    auto start = head;
    auto end = head;

    while(end->next != nullptr) end = end->next;

    while()
  }
};

int main() {
  return 0;
}