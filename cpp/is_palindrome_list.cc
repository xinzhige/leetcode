
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *p;
        if (fast == nullptr) {
            p = reverseList(slow);
        } else {
            p = reverseList(slow->next);
        }
        while (p && head) {
            if (p->val != head->val) {
                return false;
            }
            p = p->next;
            head = head->next;
        }
        return true;
    }
private:
    ListNode *reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *post = nullptr;
        while (curr) {
            post = curr->next;
            curr->next = prev;
            prev = curr;
            curr = post;
        }
        return prev;
    }
};
