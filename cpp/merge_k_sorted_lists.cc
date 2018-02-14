class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0) {
      return nullptr;
    }
    int n = lists.size();
    while (n > 1) {
      int k = (n + 1) / 2;
      for (int i = 0; i < n / 2; ++i) {
        lists[i] = mergeTwoLists(lists[i], lists[i+k]);
      }
      n = k;
    }
    return lists[0];
  }

  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode dummy(0);
    ListNode *head = &dummy;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        head->next = l1;
        l1 = l1->next;
      } else {
        head->next = l2;
        l2 = l2->next;
      }
      head = head->next;
    }
    if (l1 == nullptr) {
      head->next = l2;
    } else {
      head->next = l1;
    }
    return dummy.next;
  }
};
