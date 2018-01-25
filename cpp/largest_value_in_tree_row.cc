// Recursive
class Solution {
public:
  vector<int> largestValues(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) {
      return result;
    }
    helper(root, 1, result);
    return result;
  }
  void helper(TreeNode* root, int depth, vector<int>& result) {
    if (depth > result.size()) {
      result.emplace_back(root->val);
    } else {
      result[depth - 1] = max(result[depth - 1], root->val);
    }
    if (root->left != nullptr) {
      helper(root->left, depth + 1, result);
    }
    if (root->right != nullptr) {
      helper(root->right, depth + 1, result);
    }
  }
};

// Iterative
class Solution {
public:
  vector<int> largestValues(TreeNode* root) {
    queue<TreeNode *> q;
    vector<int> result;
    if (root != nullptr) {
      q.push(root);
    }
    while (!q.empty()) {
      int n = q.size();
      int max_so_far = INT_MIN;
      for (int i = 0; i < n; ++i) {
        auto curr = q.front();
        q.pop();
        max_so_far = max(max_so_far, curr->val);
        if (curr->left != nullptr) {
          q.push(curr->left);
        }
        if (curr->right != nullptr) {
          q.push(curr->right);
        }
      }
      result.emplace_back(max_so_far);
    }
    return result;
  }
};
