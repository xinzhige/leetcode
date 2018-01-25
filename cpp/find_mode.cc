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
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return result;
    }

private:
    vector<int> result;
    int curr_val = 0;
    int curr_count = 0;
    int max_count = 0;
    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return; 
        } 
        inorder(root->left);
        curr_count += 1;
        if (curr_val != root->val) {
            curr_val = root->val; 
            curr_max = 1;
        }
        if (curr_count > max_count) {
            max_count = curr_count; 
            result.clear();
            result.emplace_back(curr_val);
        } else if (curr_count == max_count) {
            result.emplace_back(curr_val); 
        }
        inorder(root->right);
    }
};
