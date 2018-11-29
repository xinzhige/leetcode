// Recursive
class Solution {
public:
  int kthSmallestHelper(TreeNode* root, int& k) {
    int result = 0;
    inorder(root, k, result);
    return result;
  }
  void inorder(TreeNode* root, int &k, int &result) {
    if (root != nullptr) {
      inorder(root->left, k, result);
      --k;
      if (k == 0) {
        result = root->val;
        return;
      }
      inorder(root->right, k, result);
    }
  }
};


// Non-recursive
class Solution {
public:
  int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> mystack;
    while (!mystack.empty() || root != nullptr) {
      while (root != nullptr) {
        mystack.push(root);
        root = root->left;
      } else {
        TreeNode* curr = mystack.top();
        mystack.pop();
        k -= 1;
        if (k == 0) {
          return curr->val;
        }
        root = curr->right;
      }
    }
    return INT_MIN;
  }
};
