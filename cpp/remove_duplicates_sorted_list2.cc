class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    auto prev = dummy;
    auto curr = head;
    while (curr != nullptr) {
      while (curr->next != nullptr && curr->val == curr->next->val) {
        curr = curr->next;
      }
      if (prev->next == curr) {
        prev = prev->next;
      } else {
        prev->next = curr->next;
      }
      curr = curr->next;
    }
    return dummy->next;
  }
};
