// inorder solution, recursive version
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        TreeNode* prev = nullptr;
        return  validate(root, prev);
    } 

private:
    bool validate(TreeNode* root, TreeNode* &prev) {
        if (root == nullptr) {
            return true;
        }
        if (!validate(root->left, prev)) {
            return false;
        }
        if (prev != nullptr && root->val <= prev->val) {
            return false;
        }
        prev = root;
        return validate(root->right, prev);
    }
};
