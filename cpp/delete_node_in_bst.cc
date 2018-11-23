// Recursive, idea: use binary search to find the key node,
// change its value to be its minimum of the right subtree,
// recursively delete the minimum node of the right subtree.
class Solution {
public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
      return nullptr;
    }
    if (root->val > key) {
      root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
      root->right = deleteNode(root->right, key);
    } else {
      if (root->left == nullptr) {
        return root->right;
      } else if (root->right == nullptr) {
        return root->left;
      } else {
        TreeNode *minNode = root->right;
        for (; minNode->left != nullptr; minNode = minNode->left);
        root->val = minNode->val;
        root->right = deleteNode(root->right, minNode->val);
      }
    }
    return root;
  }
};


// Iterative
class Solution {
public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode* curr = root;
    TreeNode* prev = nullptr;
    while (curr != nullptr && curr->val != key) {
      prev = curr;
      if (curr->val > key) {
        curr = curr->left;
      } else if (curr->val < key) {
        curr = curr->right;
      }
    }
    if (prev == nullptr) {
      return deleteRootNode(curr);
    }
    if (prev->left == curr) {
      prev->left = deleteRootNode(curr);
    } else {
      prev->right = deleteRootNode(curr);
    }
    return root;
  }
  TreeNode* deleteRootNode(TreeNode* root) {
    if (root == nullptr) {
      return nullptr;
    }
    if (root->left == nullptr) {
      return root->right;
    }
    if (root->right == nullptr) {
      return root->left;
    }
    TreeNode* next = root->right;
    TreeNode* prev = nullptr;
    for (; next->left != nullptr; prev = next, next = next->left);
    next->left = root->left;
    if (root->right != next) {
      prev->left = next->right;
      next->right = root->right;
    }
    return next;
  }
};


// Delete a node in binary tree
class Solution {
public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
      return nullptr;
    }
    if (root->val == key) {
      if (root->right == nullptr) {
        return root->left;
      } else {
        TreeNode *curr = root->right;
        for (; curr->left; curr = curr->left);
        swap(root->val, curr->val);
      }
    }
    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);
    return root;
  }
};
