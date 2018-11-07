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
  ListNode* removeElements(ListNode* head, int val) {
    auto dummy = new ListNode(0);
    dummy->next = head;
    auto prev = dummy;
    for (auto curr = head; curr != nullptr; curr = curr->next) {
      if (curr->val == val) {
        prev->next = curr->next;
      } else {
        prev = curr;
      }
    }
    return dummy->next;
  }
};
