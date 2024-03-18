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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto node = head;

    int len = 1;
    while(node->next != nullptr) {
      node = node->next;
      len += 1;
    }

    node = head;

    if(len <= 1) return nullptr;
    if(len - n - 1 < 0) return head->next;

    for(int i = 0; i < len - n - 1; ++i){
      node = node->next;
    }

    ListNode* node_before = new ListNode();
    ListNode* node_after = new ListNode();

    node_before = node;

    if(node_before->next != nullptr) node = node_before->next;
    else node = nullptr;

    if(node->next != nullptr) node_after = node->next;
    else node_after = nullptr;

    node_before->next = node_after;

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

  auto head = Solution().removeNthFromEnd(n1, 2);

  while(head->next != nullptr){
    std::cout << head->val << std::endl;
    head = head->next;
  }

  std::cout << head->val << std::endl;

  return 0;
}