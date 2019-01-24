class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) {
      return head;
    }
    ListNode *prev = head;
    for (ListNode *curr = head->next; curr != nullptr; curr = curr->next) {
      if (curr->val == prev->val) {
        prev->next = curr->next;
        delete curr;
      } else {
        prev = curr;
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
