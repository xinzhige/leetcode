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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *prev = head;
        for (ListNode *curr = head->next; curr != nullptr; curr = curr->next) {
            if (curr->val == prev->val) {
                prev->next = curr->next;
                delete curr;
            } else {
                prev = curr;
            }
        }
        return head;
    }
};
