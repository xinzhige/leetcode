class Solution {
public:
  Node* insert(Node* head, int insertVal) {
    auto newNode = new Node(insertVal, nullptr);
    if (head == nullptr) {
      newNode->next = newNode;
      return newNode;
    }
    auto prev = head;
    auto curr = head->next;
    for (; curr != head; curr = curr->next, prev = prev->next) {
      if ((prev->val <= insertVal && insertVal <= curr->val) ||
          (prev->val > curr->val && (prev->val < insertVal ||
                                     insertVal < curr->val))) {
        break;
      }
    }
    prev->next = newNode;
    newNode->next = curr;
    return head;
  }
};
