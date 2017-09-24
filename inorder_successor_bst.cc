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
    while (root) {
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
