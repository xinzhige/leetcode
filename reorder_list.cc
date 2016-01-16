class Solution {
private:
  ListNode *reverse(ListNode *head) {
    ListNode *new_head = nullptr;
    ListNode *post;
    while (head != nullptr) {
      post = head->next;
      head->next = new_head;
      new_head = head;
      head = post;
    }
    return new_head;
  }

  ListNode *find_middle(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }

  void merge(ListNode *head1, ListNode *head2) {
    int index = 0;
    ListNode dummy(0);
    ListNode *head = &dummy;
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
    ListNode *middle = find_middle(head);
    ListNode *tail = reverse(middle->next);
    middle->next = nullptr;
    merge(head, tail);
  }
};
