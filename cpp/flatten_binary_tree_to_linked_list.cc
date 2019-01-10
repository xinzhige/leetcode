// recursive
class Solution {
public:
  void flatten(TreeNode *root) {
    if (root == nullptr) {
      flatten(root->left);
      flatten(root->right);
      TreeNode *tmp = root->right;
      root->right = root->left;
      root->left = nullptr;
      while (root->right != nullptr) {
        root = root->right;
      }
      root->right = tmp;
    }
  }
};

// iterative
class Solution {
public:
  void flatten(TreeNode *root) {
    TreeNode *node = root;
    while (node != nullptr) {
      if (node->left != nullptr) {
        TreeNode *p = node->left;
        while (p->right != nullptr) {
          p = p->right;
        }
        p->right = node->right;
        node->right = node->left;
        node->left = nullptr;
      }
      node = node->right;
    }
  }
};
