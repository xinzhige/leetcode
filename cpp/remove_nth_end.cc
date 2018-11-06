class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    auto dummy = new ListNode(0);
    dummy->next = head;
    auto prev = dummy;
    auto curr = head;
    for (int i = 0; i < n; ++i) {
      if (curr != nullptr) {
        curr = curr->next;
      }
    }
    for (; curr != nullptr; curr = curr->next) {
      prev = prev->next;
    }
    prev->next = prev->next->next;
    return dummy->next;
  }
};
