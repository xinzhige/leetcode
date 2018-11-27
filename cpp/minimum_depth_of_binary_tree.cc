// If one node has not left child, then its minDepth must be the minDepth of its right child and so does its right child.
class Solution {
public:
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int left_depth = minDepth(root->left);
    int right_depth = minDepth(root->right);
    if (root->left == nullptr) {
      return 1 + right_depth;
    }
    if (root->right == nullptr) {
      return 1 + left_depth;
    }
    return 1 + min(left_depth, right_depth);
  }
};


// By level traversal
class Solution {
public:
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    queue<DepthNode> q;
    DepthNode curr(root, 1);
    q.emplace(curr);
    while (!q.empty()) {
      auto curr = q.front();
      q.pop();
      TreeNode* node = curr.node;
      if (node->left == nullptr && node->right == nullptr) {
        return curr.depth;
      }
      if (node->left != nullptr) {
        DepthNode curr_left(node->left, 1 + curr.depth);
        q.emplace(curr_left);
      }
      if (node->right != nullptr) {
        DepthNode curr_right(node->right, 1 + curr.depth);
        q.emplace(curr_right);
      }
    }
    return 0;
  }
private:
  struct DepthNode {
    TreeNode* node;
    int depth;
    DepthNode(TreeNode* n, int d) : node(n), depth(d) { }
  };
};
