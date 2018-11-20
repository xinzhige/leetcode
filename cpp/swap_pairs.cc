/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode* post= head->next;
    head->next = swapPairs(post->next);
    post->next = head;
    return post;
  }
};
