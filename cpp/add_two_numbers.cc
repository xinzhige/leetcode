/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode *l2) {
    ListNode *dummy = new ListNode(0);
    ListNode* head = dummy;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
      int num1 = (l1 == nullptr ? 0 : l1->val);
      int num2 = (l2 == nullptr ? 0 : l2->val);
      int sum = num1 + num2 + carry;
      carry = sum / 10;
      sum %= 10;
      ListNode* node = new ListNode(sum);
      head->next = node;
      head = node;
      l1 = (l1 == nullptr ? nullptr : l1->next);
      l2 = (l2 == nullptr ? nullptr : l2->next);
    }
    return dummy.next;
  }
};
