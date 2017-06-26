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
    int getMinimumDifference(TreeNode* root) {
        if (root->left != nullptr) {
            getMinimumDifference(root->left);
        }
        if (val >= 0) {
            min_diff = min(min_diff, root->val - val);
        }
        val = root->val;
        if (root->right != nullptr) {
            getMinimumDifference(root->right);
        }
        return min_diff;
    }
    
private:
    int min_diff = INT_MAX;
    int val = -1;
};t 
