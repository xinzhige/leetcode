#include <iostream>
#include "list_node.h"

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

// avoid using the double pointer
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(0);
    ListNode* head = &dummy;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
      	head->next = l1;
      	l1 = l1->next;
      } else {
      	head->next = l2;
      	l2 = l2->next;
      }
      head = head->next;
    }
    if (l1 != nullptr) {
      head->next = l1;
    } else {
      head->next = l2;
    }
    head = dummy->next;
    delete dummy;
    return head;
  }
};
