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
    if (root == nullptr) {
      return 0;
    } else {
      root->val = 1;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode *curr = q.front();
      q.pop();
      if (q.empty() && curr->left == nullptr && curr->right == nullptr) {
        return curr->val;
      }
      if (curr->left != nullptr) {
        curr->left->val = curr->val + 1;
        q.push(curr->left);
      }
      if (curr->right != nullptr) {
        curr->right->val = curr->val + 1;
        q.push(curr->right);
      }
    }
  }
};
