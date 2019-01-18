// Idea: 1. if p has right child, the successor is left-most leaf of the
// right subtree.
// 2. if p has no right child, the successor is its parent.
// 3. Otherwise, null.
class Solution {
public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if (root == nullptr) {
      return nullptr;
    }
    if (root->val <= p->val) {
      return inorderSuccessor(root->right, p);
    } else {
      auto curr = inorderSuccessor(root->left, p);
      return curr == nullptr ? root : curr;
    }
  }
};


// iterative
class Solution {
public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode *result = nullptr;
    while (root != nullptr) {
      if (root->val <= p->val) {
        root = root->right;
      } else {
        result = root;
        root = root->left;
      }
    }
    return result;
  }
};
