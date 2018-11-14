class Solution {
public:
  int rangeSumBST(TreeNode* root, int L, int R) {
    int result = 0;
    rangeSumBST(root, L, R, result);
    return result;
  }
  void rangeSumBST(TreeNode* root, int L, int R, int &sum) {
    if (root != nullptr) {
      if (root->val >= L && root->val <= R) {
        sum += root->val;
      }
      if (root->val > L) {
        rangeSumBST(root->left, L, R, sum);
      }
      if (root->val < R) {
        rangeSumBST(root->right, L, R, sum);
      }
    }
  }
};


// Iterative
class Solution {
public:
  int rangeSumBST(TreeNode* root, int L, int R) {
    int result = 0;
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty()) {
      auto node = s.top();
      s.pop();
      if (node != nullptr) {
        if (L <= node->val && node->val <= R) {
          result += node->val;
        }
        if (L < node->val) {
          s.push(node->left);
        }
        if (node->val < R) {
          s.push(node->right);
        }
      }
    }
    return result;
  }
};
