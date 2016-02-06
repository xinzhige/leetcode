// Recursive
class Solution {
public:
  TreeNode *upsideDownBinaryTree(TreeNode *root) { 
    if (root == nullptr) {
      return nullptr;	    
    }	 
    TreeNode* parent = root;
    TreeNode* left_node = root->left;
    TreeNode* right_node = root->right;
    if (left_node != nullptr) {
      TreeNode* node = upsideDownBinaryTree(left_node);
      left_node->left = right_node;
      left_node->right = parent;
      return node;
    }
    return root;
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
