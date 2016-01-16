// recursive
class Solution {
public:
  void flatten(TreeNode *root) {
    if (root == NULL) {
      return;
    }
    flatten(root->left);
    flatten(root->right);
    if (root->left == NULL) {
      return;
    }
    TreeNode *p = root->left;
    while (p->right) {
            p = p->right;
    }
    p->right = root->right;
    root->right = root->left;
    root->left = NULL;
  }
};

// iterative
class Solution {
public:
  void flatten(TreeNode *root) {
    if (root == NULL) {
      return;
    }
    stack<TreeNode*> my_stack;
    my_stack.push(root);
    while (!my_stack.empty()) {
      TreeNode *curr = my_stack.top();
      my_stack.pop();
      if (curr->right != NULL) {
	my_stack.push(curr->right);
      }
      if (curr->left != NULL) {
	my_stack.push(curr->left);
      }
      curr->left = NULL;
      if (!my_stack.empty()) {
	curr->right = my_stack.top();
      }
    }
  }
};
