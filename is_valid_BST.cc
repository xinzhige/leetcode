// min-max solution
class Solution {
public:
  bool isValidBST(TreeNode *root, int min, int max) {
    if (root == nullptr) {
      return true;
    }
    if (root->val <= min || root->val >= max) {
      return false;
    }
    if (!isValidBST(root->left, min, root->val) ||
	!isValidBST(root->right, root->val, max)) {
      return false;
    }
    return true;
  }
  bool isValidBST(TreeNode *root) {
    return isValidBST(root, INT_MIN, INT_MAX);
  }
};

// inorder solution, recursive version
class Solution {
public:
  // Add wrapper function to be tested on leetcode
  int last_val;
  bool isValidBST(TreeNode *root) {
    last_val = INT_MIN;
    return  isValidBST_inner(root);
  } 
  bool isValidBST_inner(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    if (!isValidBST_inner(root->left)) {
      return false;
    }
    if (root->value <= last_val) {
      return false;
    }
    last_val = root->value;
    if (!isValidBST_inner(root->right)) {
      return false;
    }
    return true;
  }
};
