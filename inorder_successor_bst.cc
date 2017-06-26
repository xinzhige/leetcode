/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == nullptr) {
            return nullptr; 
        }
        if (root->val <= p->val) {
            return inorderSuccessor(root->right, p);
        } else {
            auto curr_left = inorderSuccessor(root->left, p);
            return curr_left == nullptr ? root : curr_left;
        }
    }
};
