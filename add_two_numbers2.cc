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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = reverseList(l1);
        ListNode* p2 = reverseList(l2);
        int offset = 0;
        int sum = 0;
        ListNode* dummy = new ListNode(0);
        while (p1 || p2) {
            int curr1 = (p1 == nullptr) ? 0 : p1->val;
            int curr2 = (p2 == nullptr) ? 0 : p2->val;
            int curr = curr1 + curr2 + offset; 
            sum = curr % 10; 
            ListNode* node = new ListNode(sum);
            node->next = dummy->next;
            dummy->next = node;
            offset = curr / 10; 
            if (p1) {
                p1 = p1->next; 
            }
            if (p2) {
                p2 = p2->next; 
            }
        }
        return dummy->next; 
    }
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
