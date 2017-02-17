/* There are two links need to connected: 
 * 1. from left child to right child
 * 2. from right child to left child of right sibling
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) {
            return;
        }
        if (root->left != nullptr && root->right != nullptr) {
            root->left->next = root->right;
        }
        if (root->right != nullptr && root->next != nullptr) {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
    }
};
