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
  TreeNode* upsideDownBinaryTree(TreeNode* root) {
    if (root == nullptr || root->left == nullptr) {
      return root; 
    }                           
    TreeNode *new_root = upsideDownBinaryTree(root->left);
    root->left->left = root->right;
    root->left->right = root;
    root->left = nullptr;
    root->right = nullptr;
    return new_root;
  }
};

// Iterative
class Solution {
public:
  TreeNode *upsideDownBinaryTree(TreeNode *root) {
    TreeNode* node = root;
    TreeNode* parent = nullptr;
    TreeNode* right_node = nullptr;
    while (node != nullptr) {
      TreeNode* left_node = node->left;
      node->left = right_node;
      right_node = node->right;
      node->right = parent;
      parent = node;
      node = left_node;
    }
    return parent;
  }
};
