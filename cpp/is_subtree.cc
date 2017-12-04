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
    bool isSametree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) {
            return true; 
        }
        if (s == nullptr || t == nullptr) {
            return false; 
        }
        if (s->val != t->val) {
            return false; 
        }
        return isSametree(s->left, t->left) &&
               isSametree(s->right, t->right);
    } 

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr) {
            return false;    
        } 
        if (isSametree(s, t)) {
            return true; 
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
