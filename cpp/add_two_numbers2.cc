class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* p1 = reverseList(l1);
    ListNode* p2 = reverseList(l2);
    int carry = 0;
    ListNode *dummy = new ListNode(0);
    while (p1 != nullptr || p2 != nullptr || carry != 0) {
      int x = (p1 == nullptr) ? 0 : p1->val;
      int y = (p2 == nullptr) ? 0 : p2->val;
      int sum = x + y + carry;
      carry = sum / 10;
      ListNode* node = new ListNode(sum % 10);
      node->next = dummy->next;
      dummy->next = node;
      if (p1 != nullptr) {
        p1 = p1->next;
      }
      if (p2 != nullptr) {
        p2 = p2->next;
      }
    }
    return dummy->next;
  }
private:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;
    while (curr != nullptr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};
