#include <iostream>

struct ListNode{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* reverseList(ListNode* head){
    if(head == nullptr) return head;
    if(head->next == nullptr) return head;

    auto prev_head = head;
    head = head->next;
    prev_head->next = nullptr;

    while(head->next != nullptr){
      auto next_head = head->next;
      head->next = prev_head;

      prev_head = head;
      head = next_head;
    }

    head->next = prev_head;

    return head;
  }
};

int main(){
  ListNode* n1 = new ListNode(1);
  ListNode* n2 = new ListNode(2);
  ListNode* n3 = new ListNode(3);
  ListNode* n4 = new ListNode(4);
  ListNode* n5 = new ListNode(5);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;

  auto head = Solution().reverseList(n1);

  while(head->next != nullptr){
    std::cout << head->val << std::endl;
    head = head->next;
  }

  std::cout << head->val << std::endl;
}