class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;	    
        }
        TreeNode *left_side = lowestCommonAncestor(root->left, p, q);
        TreeNode *right_side = lowestCommonAncestor(root->right, p, q);
        if (left_side != nullptr && right_side != nullptr) {
            return root;	    
        }
        return left_side != nullptr ? left_side : right_side;
    }
};
