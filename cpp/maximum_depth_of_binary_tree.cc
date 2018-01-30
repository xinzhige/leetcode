// Recursive
class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};

// Iterative
class Solution {
public:
  int maxDepth(TreeNode *root) {
    int result = 0;
    queue<TreeNode *> q;
    if (root != nullptr) {
      q.push(root);
    }
    while (!q.empty()) {
      result += 1;
      int n = q.size();
      for (int i = 0; i < n; ++i) {
        auto curr = q.front();
        q.pop();
        if (curr->left != nullptr) {
          q.push(curr->left);
        }
        if (curr->right != nullptr) {
          q.push(curr->right);
        }
      }
    }
    return result;
  }
};
