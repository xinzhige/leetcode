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
    int pathSum(TreeNode* root, int sum) {
<<<<<<< HEAD
        if(root == nullptr) {
            return 0;
        }
        return sumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

private:
    // sumUp is all paths that sum to the given value from current root node. 
    int sumUp(TreeNode* root, int pre, int sum) {
        if(root == nullptr) {
            return 0;
        }
        int curr_val = pre + root->val;
        int equal = (curr_val == sum ? 1 : 0);
        return equal + sumUp(root->left, curr_val, sum) + sumUp(root->right, curr_val, sum);
=======
        if (root == nullptr) {
            return 0; 
        }
        return sumUp(root, 0, sum) + pathSum(root->left, sum) +
            pathSum(root->right, sum);
    }

private:
    int sumUp(TreeNode* root, int pre, int sum) {
        if (root == nullptr) {
            return 0; 
        } 
        int curr_val = pre + root->val;
        int equal = (curr_val == sum ? 1 : 0);
        return equal + sumUp(root->left, curr_val, sum) +
            sumUp(root->right, curr_val, sum);
>>>>>>> 3572ce68675413c4469adb1616d7121c1d5357f4
    }
};
