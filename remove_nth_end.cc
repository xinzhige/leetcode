class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (head == NULL) {
      return head;
    }
    ListNode *first= new ListNode(0);
    first->next=head;
    head = first;
    ListNode *second = first;
    for (int i = 0; i < n; i++) {
      if (second == NULL) {
	return head;
      } 
      second = second->next;
    }
    while (second->next != NULL) {
      first = first->next;
      second = second->next;
    }
    // ListNode* temp = first->next;
    first->next = first->next->next;
    // temp->next = NULL;
    // delete temp;
    return head->next;
  }
};
