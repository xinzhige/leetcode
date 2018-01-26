// Recursive
class Solution {
public:
  bool findTarget(TreeNode* root, int k) {
    unordered_set<int> nums;
    return find(root, k, nums);
  }
  bool find(TreeNode *root, int k, unordered_set<int> &nums) {
    if (root == nullptr) {
      return false;
    }
    if (nums.count(k - root->val) > 0) {
      return true;
    }
    nums.insert(root->val);
    return find(root->left, k, nums) || find(root->right, k, nums);
  }
};

// Iterative
class Solution {
public:
  bool findTarget(TreeNode* root, int k) {
    unordered_set<int> nums;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
      auto curr = q.front();
      q.pop();
      if (nums.count(k - curr->val) > 0) {
        return true;
      }
      nums.insert(curr->val);
      if (curr->left != nullptr) {
        q.push(curr->left);
      }
      if (curr->right != nullptr) {
        q.push(curr->right);
      }
    }
    return false;
  }
};
