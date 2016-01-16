#include "linked_list.h"

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode dummy(0);
    dummy.next = head;
    for(ListNode *prev = &dummy, *curr = prev->next, *post = curr->next;
	post;
	prev = curr, curr = curr->next, post = curr ? curr->next : nullptr) {
      prev->next = post;
      curr->next = post->next;
      post->next = curr;
    }
    return dummy.next;
  }
};
