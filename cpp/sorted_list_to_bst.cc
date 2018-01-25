class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        return build(head, nullptr); 
    }

    TreeNode *build(ListNode *begin, ListNode *end) {
        if (begin == end) {
            return nullptr; 
        }
        ListNode *slow = begin;
        ListNode *fast = begin;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *curr = new TreeNode(slow->val);
        curr->left = build(begin, slow);
        curr->right = build(slow->next, end);
        return curr;
    }
};
