// space: O(1)
class Solution {
public:
  void connect(TreeLinkNode* n) {
    while (n != nullptr) {
      TreeLinkNode* first_next_level = nullptr; // the first node of next level
      TreeLinkNode* prev_node = nullptr; // previous node on the same level
      for (; n != nullptr; n = n->next) {
	if (first_next_level == nullptr) {
	  first_next_level = (n->left != nullptr ? n->left : n->right);
	}
	if (n->left != nullptr) {
	  if (prev_node != nullptr) {
	    prev_node->next = n->left;
	  }
	  prev_node = n->left;
	}
	if (n->right != nullptr) {
	  if (prev_node != nullptr) {
	    prev_node->next = n->right;
	  }
	  prev_node = n->right;
	}
      }
      n = first_next_level; // turn to next level
    }
  }
};
