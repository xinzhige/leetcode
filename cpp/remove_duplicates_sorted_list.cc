class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode *cur = head;
    while (cur != nullptr && cur->next != nullptr) {
      if (cur->val == cur->next->val) {
        cur->next = cur->next->next;
      } else {
        cur = cur->next;
      }
    }
    return head;
  }
};


// Algorithm that can be easily modified to solve II
class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *pre = dummy;
    ListNode *cur = head;
    while (cur != nullptr) {
      while (cur->next != nullptr && cur->val == cur->next->val) {
        cur = cur->next;
      }
      if (pre->next = cur) {
        pre = pre->next;
      } else {
        pre->next = cur;
      }
      cur = cur->next;
    }
    return dummy->next;
  }
};
