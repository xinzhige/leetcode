// Recursive, dfs, preorder traversal like.
class Path {
public:
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    dfs(root, "", result);
    return result;
  }
  void dfs(TreeNode* root, string path, vector<string>& result) {
    if (root != nullptr) {
      path += to_string(root->val);
      if (root->left == nullptr && root->right == nullptr) {
        result.push_back(path);
      } else {
        path += "->";
        dfs(root->left, path, result);
        dfs(root->right, path, result);
      }
    }
  }
};


// Iterative, two stacks, one is for nodes and the other one is for paths
class Path {
public:
  vector<string> binaryTreePaths(TreeNode* root) {
    if (root == nullptr) {
      return {};
    }
    vector<string> result;
    stack<TreeNode *> nodes;
    stack<string> paths;
    nodes.push(root);
    paths.push(to_string(root->val));
    while (!nodes.empty()) {
      auto node = nodes.top();
      nodes.pop();
      string path = paths.top();
      paths.pop();
      if (node->left == nullptr && node->right == nullptr) {
        result.push_back(path);
      }
      if (node->left != nullptr) {
        nodes.push(node->left);
        paths.push(path + "->" + to_string(node->left->val));
      }
      if (node->right != nullptr) {
        nodes.push(node->right);
        paths.push(path + "->" + to_string(node->right->val));
      }
    }
    return result;
  }
};
