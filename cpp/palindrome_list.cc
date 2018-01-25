class Solution {
public:
    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *post = nullptr;
        while (curr != nullptr) {
            post = curr->next;
            curr->next = prev;
            prev = curr;
            curr = post;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head1 = nullptr;
	if (fast == nullptr) {    // even number of nodes
            head1 = reverse(slow);
        } else {                  // odd number of nodes
            head1 = reverse(slow->next);
        }
        while (head != nullptr && head1 != nullptr) {
            if (head->val != head1->val) {
                return false;
            }
            head = head->next;
            head1 = head1->next;
        }
        return true;
    }
};
