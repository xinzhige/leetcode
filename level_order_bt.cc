class Solution {
public:
  vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > result;
    queue<TreeNode*> curr_level, next_level;
    vector<int> curr_values;
    if (root != nullptr) {
      curr_level.push(root);
    }
    while (!curr_level.empty()) {
      TreeNode* curr_node = curr_level.front();
      curr_level.pop();
      curr_values.push_back(curr_node->val);
      if (curr_node->left != nullptr) {
	next_level.push(curr_node->left);
      }
      if (curr_node->right != nullptr) {	
	next_level.push(curr_node->right);
      }               
      if (curr_level.empty()) {
	result.push_back(curr_values);
	curr_values.clear();
	swap(curr_level, next_level);
      }
    }
    return result;
  }
};
