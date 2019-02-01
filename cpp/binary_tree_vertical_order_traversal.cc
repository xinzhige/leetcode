// Idea: assign each node with a column index, left child is current index i-1
// and right child is i+1.
class Solution {
public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    if (root == nullptr) {
      return {};
    }
    map<int, vector<int>> cols;
    queue<pair<int, TreeNode *>> q;
    vector<vector<int>> result;
    q.emplace(0, root);
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      cols[t.first].push_back(t.second->val);
      if (t.second->left != nullptr) {
        q.emplace(t.first - 1, t.second->left);
      }
      if (t.second->right != nullptr) {
        q.emplace(t.first + 1, t.second->right);
      }
    }
    for (const auto &t : cols) {
      result.push_back(t.second);
    }
    return result;
  }
};
