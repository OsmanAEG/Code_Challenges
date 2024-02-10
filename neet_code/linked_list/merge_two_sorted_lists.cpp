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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    if(list1 == nullptr) return list2;
    if(list2 == nullptr) return list1;

    auto sorted_head = (list1->val <= list2->val) ? list1 : list2;
    if(list1->val <= list2 ->val) list1 = list1->next;
    else list2 = list2->next;

    auto sorted_tail = sorted_head;

    while(list1 != nullptr && list2 != nullptr){
      if(list1->val <= list2 ->val){
        sorted_tail->next = list1;
        list1 = list1->next;
      }else{
        sorted_tail->next = list2;
        list2 = list2->next;
      }

      sorted_tail = sorted_tail->next;
    }

    if(list1 != nullptr) sorted_tail->next = list1;
    else sorted_tail->next = list2;

    return sorted_head;
  }
};

int main(){
  ListNode* list1_n1 = new ListNode(-9);
  ListNode* list1_n2 = new ListNode(3);
  // ListNode* list1_n3 = new ListNode(4);

  list1_n1->next = list1_n2;
  // list1_n2->next = list1_n3;

  ListNode* list2_n1 = new ListNode(5);
  ListNode* list2_n2 = new ListNode(7);
  // ListNode* list2_n3 = new ListNode(4);

  list2_n1->next = list2_n2;
  // list2_n2->next = list2_n3;

  auto head = Solution().mergeTwoLists(list1_n1, list2_n1);

  while(head != nullptr){
    std::cout << head->val << std::endl;
    head = head->next;
  }
}