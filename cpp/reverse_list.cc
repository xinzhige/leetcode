// Recursive
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode* post = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return post;
  }
};

// Iterative
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* post = nullptr;
    while (curr) {
      post = curr->next;
      curr->next = prev;
      prev = curr;
      curr = post;
    }
    return prev;
  }
};
