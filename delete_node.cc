class Solution {
public:
  void deleteNode(ListNode* node) {
    ListNode *tmp = node->next;   		            
    node->val = tmp->val;
    node->next = tmp->next;
    delete tmp;
  }
};
