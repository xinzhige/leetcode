class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(0);
        auto prev = &dummy;	
        auto curr = head;
        while (curr) {
	        if (curr->next && curr->next->val == curr->val) {
                auto val = curr->val; 
                for (; curr && curr->val == val; curr = curr->next); 
                prev->next = curr;
            } else {
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            } 
        }
        return dummy.next; 
    }
};
