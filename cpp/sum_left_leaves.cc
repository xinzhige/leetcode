/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursive
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0; 
        }
        if (root->left != nullptr && root->left->left == nullptr &&
            root->left->right == nullptr) {
            return root->left->val + sumOfLeftLeaves(root->right); 
        }
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};


// Iterative
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr ||
            (root->left == nullptr && root->right == nullptr)) {
            return 0;     
        }
        queue<TreeNode *> q;
        q.emplace(root);
        int sum = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node->left != nullptr && node->left->left == nullptr &&
                node->left->right == nullptr) {
                sum += node->left->val;     
            }
            if (node->left != nullptr) {
                q.emplace(node->left); 
            }
            if (node->right != nullptr) {
                q.emplace(node->right); 
            }
        }
        return sum;
    }
};
