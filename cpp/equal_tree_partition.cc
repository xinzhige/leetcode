// Idea: calculate all the sum of subtrees and if any of them is equal to
// the half of the sum of root, then it is true.
class Solution {
public:
  bool checkEqualTree(TreeNode* root) {
    int total = sumTree(root);
    seen.pop_back();
    if (total % 2 == 0) {
      for (const int &s: seen) {
        if (s == total / 2) {
          return true;
        }
      }
    }
    return false;
  }
  int sumTree(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    seen.emplace_back(root->val + sumTree(root->left) + sumTree(root->right));
    return seen.back();
  }
private:
  vector<int> seen;
};
