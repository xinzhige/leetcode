// Idea: calculate all the sum of subtrees and if any of them is equal to
// the half of the sum of root, then it is true.
class Solution {
public:
  bool checkEqualTree(TreeNode* root) {
    int total = sumTree(root);
    seen.pop();
    if (total % 2 == 0) {
      while (!seen.empty()) {
        auto t = seen.top();
        seen.pop();
        if (t == total / 2) {
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
    seen.emplace(root->val + sumTree(root->left) + sumTree(root->right));
    return seen.top();
  }
private:
  stack<int> seen;
};
