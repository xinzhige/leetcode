// needs 4 pointers, one is current, one is previous and the other two are their copies. Note: Change the nodes need to be swapped by starting from the rear (easy to remember and not to be wrong)
class Solution {  
public:  
  ListNode *insertionSortList(ListNode *head) {  
    if( head == NULL || head->next == NULL) {
      return head;  
    }
    ListNode dummy(0);  
    dummy.next = head;  
    ListNode *curr = dummy.next->next;  
    while(curr != NULL) {
      ListNode *prev = &dummy;  
      while(prev->next->val <= curr->val && prev->next != curr) { // skip all the elements less than current
	prev = prev->next;  
      }
      if(prev->next == curr) { // previous list is sorted
	curr = curr->next;  
      } else {  
	ListNode *temp_prev = prev->next;  
	ListNode *temp_curr = curr->next;  
	curr->next = temp_prev;  
	while(temp_prev->next != curr) { // if there are some elements between curr and temp_prev, skip them
	  temp_prev = temp_prev->next;  
	}
	temp_prev->next = temp_curr;  
	prev->next = curr;  
	curr = temp_curr;  
      }  
    }  
    return dummy.next;  
  }  
};
