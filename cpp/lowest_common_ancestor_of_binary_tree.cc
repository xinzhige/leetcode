class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
      return root;
    }
    TreeNode *leftNode = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightNode = lowestCommonAncestor(root->right, p, q);
    if (leftNode != nullptr && rightNode != nullptr) {
      return root;
    }
    return leftNode != nullptr ? leftNode : rightNode;
  }
};
