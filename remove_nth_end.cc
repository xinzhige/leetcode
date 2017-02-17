class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *curr = head;
        for (int i = 0; i < n; ++i) {
            if (curr != nullptr) {
                curr = curr->next;
            }
        }
        while (curr != nullptr) {
            prev = prev->next;
            curr = curr->next;
        }
        ListNode *tmp = prev->next;
        prev->next = prev->next->next;
        delete tmp;
        return dummy.next;
    }
};
