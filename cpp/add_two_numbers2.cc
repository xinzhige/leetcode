class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;
    while (l1 != nullptr) {
      s1.push(l1->val);
      l1 = l1->next;
    }
    while (l2 != nullptr) {
      s2.push(l2->val);
      l2 = l2->next;
    }
    ListNode *head = nullptr;
    int cur_sum = 0;
    while (!s1.empty() || !s2.empty() || cur_sum != 0) {
      if (!s1.empty()) {
        cur_sum += s1.top();
        s1.pop();
      }
      if (!s2.empty()) {
        cur_sum += s2.top();
        s2.pop();
      }
      ListNode *node = new ListNode(cur_sum % 10);
      cur_sum /= 10;
      node->next = head;
      head = node;
    }
    return head;
  }
};
