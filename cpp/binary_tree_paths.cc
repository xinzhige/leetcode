// Recursive
class Path {
public:
  void constructPaths(TreeNode* root, string path, vector<string>& result) {
    if (root != nullptr) {
      path = path + to_string(root->val);
      if (root->left == nullptr && root->right == nullptr) {
        result.push_back(path);
      } else {
        path = path + "->";
        constructPaths(root->left, path, result);
        constructPaths(root->right, path, result);
      }
    }
  }
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    string path;
    constructPaths(root, path, result);
    return result;
  }
};


// Iterative
class Path {
public:
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if (root == nullptr) {
      return result;
    }
    stack<TreeNode *> node_st;
    stack<string> path_st;
    node_st.push(root);
    path_st.push(to_string(root->val));
    while (!node_st.empty()) {
      TreeNode *node = node_st.top();
      node_st.pop();
      string path = path_st.top();
      path_st.pop();
      if (node->left == nullptr && node->right == nullptr) {
        result.push_back(path);
      }
      if (node->left != nullptr) {
        node_st.push(node->left);
        path_st.push(path + "->" + to_string(node->left->val));
      }
      if (node->right != nullptr) {
        node_st.push(node->right);
        path_st.push(path + "->" + to_string(node->right->val));
      }
    }
    return result;
  }
};
