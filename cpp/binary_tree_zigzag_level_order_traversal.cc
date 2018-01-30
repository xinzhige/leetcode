// Iterative by one queue
class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> result;
    queue<TreeNode *> q;
    if (root != nullptr) {
      q.push(root);
    }
    auto leftToRight = true;
    while (!q.empty()) {
      auto n = q.size();
      vector<int> level(n);
      for (auto i = 0; i < n; ++i) {
        auto node = q.front();
        q.pop();
        auto index = (leftToRight) ? i : (n - 1 - i);
        level[index] = node->val;
        if (node->left != nullptr) {
          q.push(node->left);
        }
        if (node->right != nullptr) {
          q.push(node->right);
        }
      }
      leftToRight = !leftToRight;
      result.push_back(level);
    }
    return result;
  }
};


// Recursive
class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> result;
    traverse(root, result, 0);
    return result;
  }

  void traverse(TreeNode *root, vector<vector<int>> &result, int level) {
    if (root == nullptr) {
      return;
    }
    if (result.size() == level) {
      result.push_back({});
    }
    if (level % 2 == 0) {
      result[level].push_back(root->val);
    } else {
      result[level].insert(result[level].begin(), root->val);
    }
    traverse(root->left, result, level + 1);
    traverse(root->right, result, level + 1);
  }
};
