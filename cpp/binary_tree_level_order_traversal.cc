// Iterative
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int> > result;
    queue<TreeNode *> q;
    if (root != nullptr) {
      q.push(root);
    }
    while (!q.empty()) {
      vector<int> level;
      int n = q.size();
      for (int i = 0; i < n; ++i) {
        auto node = q.front();
        q.pop();
        level.push_back(node->val);
        if (node->left != nullptr) {
          q.push(node->left);
        }
        if (node->right != nullptr) {
          q.push(node->right);
        }
      }
      result.push_back(level);
    }
    return result;
  }
};


// Recursive
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    levelOrderHelper(root, 0, result);
    return result;
  }
  void levelOrderHelper(TreeNode* root, int level, vector<vector<int>> &result) {
    if (root == nullptr) {
      return;
    }
    if (result.size() == level) {
      result.push_back({});
    }
    result[level].push_back(root->val);
    if (root->left != nullptr) {
      levelOrderHelper(root->left, level + 1, result);
    }
    if (root->right != nullptr) {
      levelOrderHelper(root->right, level + 1, result);
    }
  }
};
