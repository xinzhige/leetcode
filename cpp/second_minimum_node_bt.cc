class Solution {
public:
  int findSecondMinimumValue(TreeNode* root) {
    int first = root->val;
    int second = INT_MAX;
    inorder(root, first, second);
    return (second == first || second == INT_MAX) ? -1 : second;
  }

private:
  void inorder(TreeNode* root, int &first, int &second) {
    if (root == nullptr) {
      return;
    }
    if (root->val != first && root->val < second) {
        second = root->val;
    }
    inorder(root->left, first, second);
    inorder(root->right, first, second);
  }
};

// Iterative
class Solution {
public:
  int findSecondMinimumValue(TreeNode* root) {
    int first = root->val;
    int second = INT_MAX;
    queue<TreeNode*> q{{root}};
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      if (t->val != first && t->val < second) {
        second = t->val;
      }
      if (t->left) {
        q.push(t->left);
      }
      if (t->right) {
        q.push(t->right);
      }
    }
    return (second == first || second == INT_MAX) ? -1 : second;
  }
};
