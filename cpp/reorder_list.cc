class Solution {
private:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *post = nullptr;
    while (curr != nullptr) {
      post = curr->next;
      curr->next = prev;
      prev = curr;
      curr = post;
    }
    return prev;
  }

  ListNode *find_middle(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    auto slow = head;
    auto fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }

  void merge(ListNode *head1, ListNode *head2) {
    int index = 0;
    auto dummy = new ListNode(0);
    auto head = dummy;
    while (head1 != nullptr && head2 != nullptr) {
      if (index % 2 == 0) {
        head->next = head1;
        head1 = head1->next;
      } else {
        head->next = head2;
        head2 = head2->next;
      }
      head = head->next;
      index += 1;
    }
    if (head1 != nullptr) {
      head->next = head1;
    } else {
      head->next = head2;
    }
  }

public:
  void reorderList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return;
    }
    auto middle = find_middle(head);
    auto tail = reverseList(middle->next);
    middle->next = nullptr;
    merge(head, tail);
  }
};
