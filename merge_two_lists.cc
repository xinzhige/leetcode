// recursive way
/*
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (l1==nullptr) {
      return l2;
    }
    if (l2==nullptr) {
      return l1;
    }
    ListNode *ret;
    if (l1->val < l2->val) {
      ret = l1;
      ret->next = mergeTwoLists(l1->next,l2);
    } else {
      ret = l2;
      ret->next = mergeTwoLists(l1,l2->next);
    }
    return ret;
  }
};
*/

// non-recursive 
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
      	curr->next = l1;
      	l1 = l1->next;
      } else {
      	curr->next = l2;
      	l2 = l2->next;
      }
      curr = curr->next;
    }
    head->next = (l1 != nullptr) ? l1 : l2;
    return dummy.next;
  }
};
