class Solution {
public:
  bool validate(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if(root == nullptr) {
      return true;
    }
    if((minNode != nullptr && root->val <= minNode->val) ||
      (maxNode != nullptr && root->val >= maxNode->val)) {
      return false;
    }
    return validate(root->left, minNode, root) &&
      validate(root->right, root, maxNode);
  }

  bool isValidBST(TreeNode* root) {
    return validate(root, nullptr, nullptr);
  }
};
