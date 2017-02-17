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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr) {
            return head;
        }
        ListNode *p = head; 
        int n = 1;
        for (; p ->next; p = p->next) {
            ++n; 
        }
        p->next = head;
        k = n - k % n;
        for (int i = 0; i < k; ++i) {
            p = p->next; 
        }
        head = p->next;
        p->next = nullptr;
        return head;
    }
};
