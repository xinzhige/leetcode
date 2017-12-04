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
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        while (curr != nullptr && curr->next != nullptr) {
           prev->next = post;
           curr->next = post->next;
           post->next = curr;
           prev = curr;
           curr = curr->next;
           post = (curr == nullptr) ? nullptr : curr->next;
        }   
        return dummy.next;
    }
};
