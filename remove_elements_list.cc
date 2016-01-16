class Solution {
public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode *curr = head;
    while (curr && curr->val == val) {
      ListNode *tmp = curr;
      curr = curr->next;
      delete tmp;
    } 
    head = curr;
    if (curr == nullptr) {
      return nullptr;
    }
    while (curr->next != nullptr) {
      if (curr->next->val == val) {
        ListNode *tmp = curr->next;
        curr->next = tmp->next;
        delete tmp;
      } else {
        curr = curr->next;
      }
    }
    return head;
  }
};
