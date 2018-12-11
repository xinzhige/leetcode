// Idea: use stack and do inorder traversal.
class BSTIterator {
public:
  BSTIterator(TreeNode *root) {
    pushAll(root);
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !nodes.empty();
  }

  /** @return the next smallest number */
  int next() {
    auto tmp = nodes.top();
    nodes.pop();
    pushAll(tmp->right);
    return tmp->val;
  }
  void pushAll(TreeNode *node) {
    for (; node != nullptr; node = node->left) {
      nodes.push(node);
    }
  }
private:
  stack<TreeNode *> nodes;
};
