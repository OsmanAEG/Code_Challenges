// Linked List Definition
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    auto slow = head;
    auto fast = head;

    while(fast != nullptr && fast->next != nullptr){
      slow = slow->next;
      fast = fast->next->next;

      if(fast == slow) return true;
    }

    return false;
  }
};

int main(){
  return 0;
}