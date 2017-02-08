class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr) {
            return head;
        }
        ListNode *prev = head;
        ListNode *curr = head;
        for (int i = 0; i < k; i++) {
            curr = curr->next;
            if (curr == nullptr) {
	            curr = head;
            }
        }
        while (curr->next != nullptr) {
            prev = prev->next;
            curr = curr->next;
        }
        curr->next = head;
        head = prev->next;
        prev->next = nullptr;
        return head;
    }
};
