class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head != nullptr) {
            ListNode* odd = head;
            ListNode* even = head->next;
            ListNode* even_head = even;
            while (odd->next != nullptr && even->next != nullptr) {
                odd->next = even->next;
                odd = odd->next;
                even->next = odd->next;
                even = even->next;
            }
            odd->next = even_head;
        }
        return head;
    }
};
