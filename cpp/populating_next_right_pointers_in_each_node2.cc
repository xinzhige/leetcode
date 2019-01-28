class Solution {
public:
  void connect(TreeLinkNode *root) {
    TreeLinkNode *dummy = new TreeLinkNode(0);
    TreeLinkNode *cur = dummy;
    while (root != nullptr) {
      if (root->left != nullptr) {
        cur->next = root->left;
        cur = cur->next;
      }
      if (root->right != nullptr) {
        cur->next = root->right;
        cur = cur->next;
      }
      root = root->next;
      if (root == nullptr) {
        cur = dummy;
        root = dummy->next;
        dummy->next = nullptr;
      }
    }
  }
};
