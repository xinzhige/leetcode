// DFS
class Solution {
public:
  int widthOfBinaryTree(TreeNode* root) {
    vector<int> lefts;
    int result = 0;
    dfs(root, 1, 0, lefts, result);
    return result;
  }
  void dfs(TreeNode* node, int id, int depth, vector<int>& lefts,
           int& result) {
    if (node != nullptr) {
      if (depth >= lefts.size()) {
        lefts.push_back(id);
      }
      result = max(result, id + 1 - lefts[depth]);
      dfs(node->left, id * 2, depth + 1, lefts, result);
      dfs(node->right, id * 2 + 1, depth + 1, lefts, result);
    }
  }
};


// BFS
class Solution {
public:
  int widthOfBinaryTree(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    queue<pair<TreeNode *, int>> level;
    level.push({root, 1});
    int result = 0;
    while (!level.empty()) {
      int l = level.front().second;
      int r = l;
      int n = level.size();
      for (int i = 0; i < n; ++i) {
        TreeNode *node = level.front().first;
        r = level.front().second;
        level.pop();
        if (node->left != nullptr) {
          level.push({node->left, r * 2});
        }
        if (node->right != nullptr) {
          level.push({node->right, r * 2 + 1});
        }
      }
      result = max(result, r - l + 1);
    }
    return result;
  }
};
