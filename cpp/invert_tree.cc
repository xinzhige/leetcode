// Recursive: invert left tree and store it then invert right tree and assign it to left child lastly assign the temp to right child
class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
      return root;
    }
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
  }
};

// Iterative
class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
      return root;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* curr = q.front();
      q.pop();
      swap(curr->left, curr->right);
      if (curr->left != nullptr) {
        q.push(curr->left);
      }
      if (curr->right != nullptr) {
        q.push(curr->right);
      }
    }
    return root;
  }
};
