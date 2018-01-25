class Solution {
public:
  vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> result;
    while (root != nullptr) {
      vector<int> leaves;
      root = remove(root, leaves);
      result.push_back(leaves);
    }
    return result;
  }
  TreeNode* remove(TreeNode *node, vector<int> &leaves) {
    if (node == nullptr) {
      return nullptr;
    }
    if (node->left == nullptr && node->right == nullptr) {
      leaves.push_back(node->val);
      return nullptr;
    }
    node->left = remove(node->left, leaves);
    node->right = remove(node->right, leaves);
    return node;
  }
};
