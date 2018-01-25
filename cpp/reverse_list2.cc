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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        for (int i = 0; i < m - 1; ++i) {
            prev = prev->next;
        }
        ListNode *head2 = prev;
        prev = head2->next;
        ListNode *curr = prev->next;
        for (int i = m; i < n; ++i) {
            prev->next = curr->next; 
            curr->next = head2->next; 
            head2->next = curr;
            curr = prev->next;
        }
        return dummy.next;
    }
};
