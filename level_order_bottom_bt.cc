class Solution {
public:
  vector<vector<int> > levelOrderBottom(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<TreeNode *> curr_level_nodes, next_level_nodes;
    vector<int> curr_level_values;
    vector<vector<int> > result;
    if (root != NULL) {
      curr_level_nodes.push_back(root);
    }
    while (!curr_level_nodes.empty()) {
      for (int i = 0; i < curr_level_nodes.size(); ++i) {
	TreeNode* curr_node = curr_level_nodes[i];
	curr_level_values.push_back(curr_node->val);
	if (curr_node->left != NULL) {
	  next_level_nodes.push_back(curr_node->left);
	}
	if (curr_node->right != NULL) {
	  next_level_nodes.push_back(curr_node->right);
	}
      }
      result.insert(result.begin(), curr_level_values);
      curr_level_values.clear();
      curr_level_nodes.clear();
      swap(curr_level_nodes, next_level_nodes);
    }
    return result;
  }
};
