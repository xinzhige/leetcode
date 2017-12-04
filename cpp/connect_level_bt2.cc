class Solution {
public:
    void connect(TreeLinkNode* root) {
        while (root != nullptr) {
            TreeLinkNode* next_first = nullptr;  // the first node of next level
            TreeLinkNode* prev_node = nullptr;  // previous node on the next level
            for (; root != nullptr; root = root->next) {
	            if (next_first == nullptr) {
	                next_first = (root->left != nullptr ? root->left : root->right);
	            }
	            if (root->left != nullptr) {
	                if (prev_node != nullptr) {
	                    prev_node->next = root->left;
	                }
	                prev_node = root->left;
	            }
	            if (root->right != nullptr) {
	                if (prev_node != nullptr) {
	                    prev_node->next = root->right;
	                }
	                prev_node = root->right;
	            }
            }
            root = next_first;  // turn to next level
        }
    }
};
