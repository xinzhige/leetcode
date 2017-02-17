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
        int carry = 0;
        int sum = 0;
        ListNode dummy(0);
        while (p1 != nullptr || p2 != nullptr || carry != 0) {
            int curr1 = (p1 == nullptr) ? 0 : p1->val;
            int curr2 = (p2 == nullptr) ? 0 : p2->val;
            int curr = curr1 + curr2 + carry; 
            sum = curr % 10; 
            carry = curr / 10; 
            ListNode* node = new ListNode(sum);
            node->next = dummy.next;
            dummy.next = node;
            if (p1 != nullptr) {
                p1 = p1->next; 
            }
            if (p2 != nullptr) {
                p2 = p2->next; 
            }
        }
        return dummy.next; 
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
