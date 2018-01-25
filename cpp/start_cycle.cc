class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    do {
      if (fast == NULL) {
	return NULL;
      }
      slow = slow->next;
      fast = fast->next;
      if(fast != NULL) {
	fast = fast->next;
      } else {
	return NULL;
      }
    } while(slow != fast);
    slow = head;
    while (slow != fast){
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
};
