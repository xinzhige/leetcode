class BSTIterator {
public:
  BSTIterator(TreeNode *root) : curr(root) {

  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !nodes.empty() || curr != nullptr;
  }

  /** @return the next smallest number */
  int next() {
    for (; curr != nullptr; curr = curr->left) {
      nodes.push(curr);
    }
    auto tmp = nodes.top();
    nodes.pop();
    curr = tmp->right;
    return tmp->val;
  }
private:
  stack<TreeNode *> nodes;
  TreeNode *curr;
};
