// Idea: use stack and do inorder traversal.
// Note: by amortized analysis, in average, next() runs O(n)/n=O(1).
class BSTIterator {
public:
  BSTIterator(TreeNode *root) {
    pushAll(root);
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !st.empty();
  }

  /** @return the next smallest number */
  int next() {
    auto tmp = st.top();
    st.pop();
    pushAll(tmp->right);
    return tmp->val;
  }

  void pushAll(TreeNode *node) {
    while (node != nullptr) {
      st.push(node);
      node = node->left;
    }
  }

private:
  stack<TreeNode *> st;
};
