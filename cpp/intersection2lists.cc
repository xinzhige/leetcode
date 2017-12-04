class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) return nullptr; 
	ListNode *pA = headA;
	ListNode *pB = headB;
	ListNode *tailA = nullptr;
	ListNode *tailB = nullptr;
	while (1) {
      if (pA == nullptr) pA = headB;
	  if (pB == nullptr) pB = headA;
	  if (pA->next == nullptr) tailA = pA;
	  if (pB->next == nullptr) tailB = pB;
	  if (tailA != nullptr && tailB != nullptr && 
		  tailA != tailB) {
	    return nullptr;
	  } 	
	  if (pA == pB) return pA;	
	  pA = pA->next;
	  pB = pB->next;	
	}					        
  }
};
