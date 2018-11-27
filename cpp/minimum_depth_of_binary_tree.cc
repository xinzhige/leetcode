// If one node has not left child, then its minDepth must be the minDepth of its right child and so does its right child.
class Solution {
public:
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int left_depth = minDepth(root->left);
    int right_depth = minDepth(root->right);
    if (root->left == nullptr) {
      return 1 + right_depth;
    }
    if (root->right == nullptr) {
      return 1 + left_depth;
    }
    return 1 + min(left_depth, right_depth);
  }
};


// By level traversal
class Solution {
public:
  int minDepth(TreeNode *root) {
    queue<TreeNode *> q;
    if (root != nullptr) {
      q.emplace(root);
    }
    int result = 0;
    while (!q.empty()) {
      result += 1;
      int n = q.size();
      for (int i = 0; i < n; ++i) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left != nullptr) {
          q.emplace(node->left);
        }
        if (node->right != nullptr) {
          q.emplace(node->right);
        }
        if (node->left == nullptr && node->right == nullptr) {
          return result;
        }
      }
    }
    return 0;
  }
};
