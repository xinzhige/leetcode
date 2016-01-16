class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode*> my_stack;
    if (root != NULL) {
            my_stack.push(root);
    }
    while (!my_stack.empty()) {
      TreeNode* curr_node = my_stack.top();
      my_stack.pop();
      result.insert(result.begin(), curr_node->val);
      if (curr_node->left != NULL) {
	my_stack.push(curr_node->left);
      }
      if (curr_node->right != NULL) {
	my_stack.push(curr_node->right);
      }
    }
    return result;
  }
};
