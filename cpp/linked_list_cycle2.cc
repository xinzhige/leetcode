class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        break;
      }
    }
    if (fast == nullptr || fast->next == nullptr) {
      return nullptr;
    }
    while (head != fast){
      head = head->next;
      fast = fast->next;
    }
    return head;
  }
};
