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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> mystack;
        while (root != nullptr || !mystack.empty()) {
            if (root != nullptr) {
                mystack.emplace(root);
                result.emplace_back(root->val);
                root = root->left;
            } else {
                root = mystack.top();
                mystack.pop();
                root = root->right;
            }
        }
        return result;
    }
};
