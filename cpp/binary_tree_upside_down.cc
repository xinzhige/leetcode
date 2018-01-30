// Recursive
class Solution {
public:
  TreeNode* upsideDownBinaryTree(TreeNode* root) {
    if (root == nullptr || root->left == nullptr) {
      return root;
    }
    TreeNode *newRoot = upsideDownBinaryTree(root->left);
    root->left->left = root->right;
    root->left->right = root;
    root->left = nullptr;
    root->right = nullptr;
    return newRoot;
  }
};

// Iterative
class Solution {
public:
  TreeNode *upsideDownBinaryTree(TreeNode *root) {
    TreeNode* node = root;
    TreeNode* parent = nullptr;
    TreeNode* rightNode = nullptr;
    while (node != nullptr) {
      TreeNode* leftNode = node->left;
      node->left = rightNode;
      rightNode = node->right;
      node->right = parent;
      parent = node;
      node = leftNode;
    }
    return parent;
  }
};
