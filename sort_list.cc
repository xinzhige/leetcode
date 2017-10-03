/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *mid = midNode(head);
    return mergeTwoLists(sortList(head), sortList(mid));
  }

private:
  ListNode* midNode(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }
    auto slow = head;
    auto fast = head;
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    fast = slow;
    ListNode* mid = slow->next;
    fast->next = nullptr;
    return mid;
  }

  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode dummy{0};
    auto curr = &dummy;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        curr->next = l1;
        l1 = l1->next;
      } else {
        curr->next = l2;
        l2 = l2->next;
      }
      curr = curr->next;
    }
    curr->next = l1 ? l1 : l2;
    return dummy.next;
  }
};
