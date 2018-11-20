/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    for (auto curr = head; curr != nullptr; curr = curr->next->next) {
      auto node = new RandomListNode(curr->label);
      node->next = curr->next;
      curr->next = node;
    }
    for (auto curr = head; curr != nullptr; curr = curr->next->next) {
      if (curr->random != nullptr) {
        curr->next->random = curr->random->next;
      }
    }
    auto dummy = new RandomListNode(0);
    auto copy_node = dummy;
    for (auto curr = head; curr != nullptr; curr = curr->next) {
      copy_node->next = curr->next;
      curr->next = curr->next->next;
      copy_node = copy_node->next;
    }
    return dummy->next;
  }
};
