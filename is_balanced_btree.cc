class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        int left_height = treeHeight(root->left);
        int right_height = treeHeight(root->right);
        if (abs(left_height-right_height) > 1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
  }

private:
    int treeHeight(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + max(treeHeight(root->left), treeHeight(root->right));
    }
};
