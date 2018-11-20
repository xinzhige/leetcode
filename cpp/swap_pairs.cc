/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
// Recursive
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


// Iterative
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode *dummy = new ListNode(0);
    ListNode *node = dummy;
    dummy->next = head;
    while (head != nullptr && head->next != nullptr) {
      ListNode *post = head->next;
      head->next = post->next;
      post->next = head;
      node->next = post;
      node = head;
      head = node->next;
    }
    return dummy->next;
  }
};
