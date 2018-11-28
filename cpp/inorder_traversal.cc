// Iterative, space: O(n)
class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode*> my_stack;
    while (root != nullptr || !my_stack.empty()) {
      if (root != nullptr) {
        my_stack.emplace(root);
        root = root>left;
      } else {
        root = my_stack.top();
        my_stack.pop();
        result.emplace_back(root->val);
        root = root->right;
      }
    }
    return result;
  }
};



// Morris traversal, space: O(1)
class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    TreeNode *curr = root;
    TreeNode *prev = nullptr;
    while (curr != nullptr) {
      if (curr->left == nullptr) {
        result.push_back(curr->val);
        curr = curr->right;
      } else {
        prev = curr->left;
        while (prev->right != nullptr && prev->right != curr) {
          prev = prev->right;
        }
        if (prev->right == nullptr) {
          prev->right = curr;
          curr = curr->left;
        } else {
          prev->right = nullptr;
          result.push_back(curr->val);
          curr = curr->right;
        }
      }
    }
    return result;
  }
};
