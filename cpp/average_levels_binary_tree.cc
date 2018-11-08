// BFS
class Solution {
public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> result;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      double sum = 0.0;
      for (int i = 0; i < n; ++i) {
        auto t = q.front();
        q.pop();
        sum += t->val;
        if (t->left != nullptr) {
          q.push(t->left);
        }
        if (t->right != nullptr) {
          q.push(t->right);
        }
      }
      result.push_back(sum / n);
    }
    return result;
  }
};


// DFS
class Solution {
public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> result;
    vector<int> count;
    dfs(root, 0, count, result);
    for (int i = 0; i < result.size(); ++i) {
      result[i] /= count[i];
    }
    return result;
  }
  void dfs(TreeNode *root, int level, vector<double> &result,
           vector<int> &count) {
    if (root == nullptr) {
      return;
    }
    if (result.size() <= level) {
      result.push_back(0);
      count.push_back(0);
    }
    result[level] += root->val;
    count[level] += 1;
    dfs(root->left, level + 1, count, result);
    dfs(root->right, level + 1, count, result);
  }
};
