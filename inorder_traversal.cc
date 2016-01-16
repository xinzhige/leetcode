// recursive
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        if (root->left != NULL) {
            vector<int> result_left = inorderTraversal(root->left);
            for (int i = 0; i < result_left.size(); i++) {
                result.push_back(result_left.at(i));
            }
        }
        result.push_back(root->val);
        if (root->right != NULL) {
            vector<int> result_right = inorderTraversal(root->right);
            for (int i = 0; i < result_right.size(); i++) {
                result.push_back(result_right.at(i));
            }
        }
        return result;
    }
};

// iterative
class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode*> my_stack;
    TreeNode* curr_node = root;
    while (!my_stack.empty() || curr_node != NULL) {
      if (curr_node != NULL) {
	my_stack.push(curr_node);
	curr_node = curr_node->left;
      } else {
	curr_node = my_stack.top();
	my_stack.pop();
	result.push_back(curr_node->val);
	curr_node = curr_node->right;
      }
    }
    return result;
  }
};
