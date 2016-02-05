class Solution {
public:
  vector<TreeNode *> generate(int begin, int end) {
    vector<TreeNode *> v;
    if (begin > end) {
      v.push_back(nullptr);
      return v;
    }
    for (int k = begin; k <= end; k++) {
      vector<TreeNode *> left_subtree= generate(begin, k - 1);
      vector<TreeNode *> right_subtree = generate(k + 1, end);
      for (auto i : left_subtree) {
        for (auto j : right_subtree) {
          TreeNode *curr = new TreeNode(k);
          curr->left = i;
          curr->right =j;
          v.push_back(curr);
        }
      }
    }
    return v;
  }
  vector<TreeNode *> generateTrees(int n) {
    vector<TreeNode *> result;
    if (n > 0) {
      result = generate(1, n);
    }
    return result;
  }
};
