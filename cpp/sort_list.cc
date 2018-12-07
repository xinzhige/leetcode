// Note: store the previous pointer of middle node and let its next be nullptr.
class Solution {
public:
  ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *mid = midNode(head);
    return mergeTwoLists(sortList(head), sortList(mid));
  }

private:
  ListNode* midNode(ListNode* head) {
    ListNode *prev = nullptr;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = nullptr;
    return slow;
  }

  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(0);
    ListNode *l = dummy;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        l->next = l1;
        l1 = l1->next;
      } else {
        l->next = l2;
        l2 = l2->next;
      }
      l = l->next;
    }
    l->next = (l1 != nullptr ? l1 : l2);
    return dummy->next;
  }
};
