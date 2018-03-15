class Solution {
public:
  void deleteNode(ListNode* node) {
    if (node == nullptr) {
      return; 
    } else {
      auto next = node->next;
      *node = *next;
      delete next;
    }
  }
};
