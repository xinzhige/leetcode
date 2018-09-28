class Solution {
public:
  Node* treeToDoublyList(Node* root) {
    if (root == nullptr) {
      return nullptr;
    }
    Node *dummy = new Node(0, nullptr, nullptr);
    prev = dummy;
    inorder(root);
    prev->right = dummy->right;
    dummy->right->left = prev;
    return dummy->right;
  }
  void inorder(Node *curr) {
    if (curr == nullptr) {
      return;
    }
    inorder(curr->left);
    prev->right = curr;
    curr->left = prev;
    prev = curr;
    inorder(curr->right);
  }
private:
  Node *prev = nullptr;
};
