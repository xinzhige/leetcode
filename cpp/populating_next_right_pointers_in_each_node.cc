/* There are two links need to connected:
 * 1. from left child to right child
 * 2. from right child to left child of right sibling
 */
class Solution {
public:
  void connect(TreeLinkNode *root) {
    if (root != nullptr) {
      if (root->left != nullptr) {
        root->left->next = root->right;
      }
      if (root->right != nullptr && root->next != nullptr) {
        root->right->next = root->next->left;
      }
      connect(root->left);
      connect(root->right);
    }
  }
};


// Iterative
class Solution {
public:
  void connect(TreeLinkNode *root) {
    if (root != nullptr) {
      for (TreeLinkNode *pre = root; pre->left != nullptr; pre = pre->left) {
        for (TreeLinkNode *cur = pre; cur != nullptr; cur = cur->next) {
          if (cur->left != nullptr) {
            cur->left->next = cur->right;
          }
          if (cur->right != nullptr && cur->next != nullptr) {
            cur->right->next = cur->next->left;
          }
        }
      }
    }
  }
};
