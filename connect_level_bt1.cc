struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
  void connect(TreeLinkNode *root) {
    if (root == nullptr) {
      return;
    }
    if (root->left != nullptr) {
      root->left->next = root->right;
    }
    if (root->right != nullptr) {
      if (root->next == nullptr) {
	root->right->next = nullptr;
      } else {
	root->right->next = root->next->left;
      }
    }
    connect(root->left);
    connect(root->right);
  }
};
