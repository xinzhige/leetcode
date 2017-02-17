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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; 
        }
        auto slow = head;
        auto fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow;
        slow = fast->next;
        fast->next = nullptr;
        return mergeLists(sortList(head), sortList(slow));
    }
private:
    ListNode* mergeLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        auto curr = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            } 
            curr = curr->next;
        }
        curr->next = (l1 != nullptr) ? l1 : l2;
        return dummy.next;
    }
};
