// Recursive: invert left tree and store it then invert right tree and assign it to left child lastly assign the temp to right child
class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
      return nullptr;	    
    } 
    TreeNode *node = invertTree(root->left);
    root->left = invertTree(root->right);
    root->right = node;
    return node;
  }
};

// Non-recursive
class Solution {
public:
  void swapTree(TreeNode *&x, TreeNode *&y) {
    TreeNode *tmp = x;
    x = y;
    y = tmp;
  }
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
      return root;
    }
    stack<TreeNode *> mystack;
    mystack.push(root);
    while (!mystack.empty()) {
      TreeNode* curr = mystack.top();
      mystack.pop();
      swapTree(curr->left, curr->right);
      if (curr->left != nullptr) {
        mystack.push(curr->left);
      }
      if (curr->right != nullptr) {
        mystack.push(curr->right);
      }
    }
    return root;
  }
};
