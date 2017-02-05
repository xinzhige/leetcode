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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        for (ListNode *curr = head; curr != nullptr; curr = prev->next) {
            if (curr->val == val) {
                ListNode *tmp = curr;
                prev->next = curr->next;
                delete curr;
            } else {
                prev = curr;
            }
        }
        return dummy->next;
    }
};
