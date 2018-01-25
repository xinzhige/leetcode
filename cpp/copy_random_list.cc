/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        for (auto *curr = head; curr; curr = curr->next->next) {
            auto *node = new RandomListNode(curr->label); 
            node->next = curr->next;
            curr->next = node;
        }                   
        for (auto *curr = head; curr; curr = curr->next->next) {
            if (curr->random) {
                curr->next->random = curr->random->next; 
            } 
        }
        RandomListNode dummy(0);  
        auto *copy_curr = &dummy;
        for (auto *curr = head; curr; curr = curr->next) {
            copy_curr->next = curr->next;
            curr->next = curr->next->next;
            copy_curr = copy_curr->next;
        }
        return dummy.next;
    }
};
