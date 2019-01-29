// Recursive
class Solution {
public:
  bool findTarget(TreeNode* root, int k) {
    unordered_set<int> nums;
    return find(root, k, nums);
  }
  bool find(TreeNode* root, int k, unordered_set<int> &nums) {
    if (root == nullptr) {
      return false;
    }
    if (nums.count(k - root->val)) {
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
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      auto node = q.front();
      q.pop();
      if (nums.count(k - node->val) > 0) {
        return true;
      }
      nums.insert(node->val);
      if (node->left != nullptr) {
        q.push(node->left);
      }
      if (node->right != nullptr) {
        q.push(node->right);
      }
    }
    return false;
  }
};
