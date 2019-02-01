// Recursive
class Solution {
public:
  bool isSymmetricHelper(TreeNode* l, TreeNode* r) {
    if (l == nullptr && r == nullptr) {
      return true;
    }
    if (l == nullptr || r == nullptr) {
      return false;
    }
    return l->val == r->val && isSymmetricHelper(l->left, r->right) &&
      isSymmetricHelper(l->right, r->left);
  }
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    return isSymmetricHelper(root->left, root->right);
  }
};

// Iterative, queue
class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    queue<TreeNode *> q;
    q.push(root->left);
    q.push(root->right);
    while (!q.empty()) {
      auto l = q.front();
      q.pop();
      auto r = q.front();
      q.pop();
      if (l == nullptr && r == nullptr) {
        continue;
      } else if (l == nullptr || r == nullptr ||
          (l->val != r->val)) {
        return false;
      }
      q.push(l->left);
      q.push(r->right);
      q.push(l->right);
      q.push(r->left);
    }
    return true;
  }
};
