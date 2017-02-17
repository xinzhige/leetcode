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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy_smaller(0);
        ListNode dummy_larger(0);
        ListNode *p1 = &dummy_smaller;
        ListNode *p2 = &dummy_larger;
        for (ListNode *curr = head; curr; curr = curr->next) {
            if (curr->val < x) {
                p1->next = curr;
                p1 = p1->next;
            } else {
                p2->next = curr;
                p2 = p2->next;
            }
        }
        p1->next = dummy_larger.next;
        p2->next = nullptr;
        return dummy_smaller.next;
    }
};
