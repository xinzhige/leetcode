// Idea: there should not be any node after empty one.
// Once meeting null node, stop the first loop and if any node's left is
// empty but right is not, return false. The second loop is used to decide
// if there is any node after the empty node in the last level.
class Solution {
public:
  bool isCompleteTree(TreeNode* root) {
    list<TreeNode*> q;
    q.emplace_back(root);
    while (true) {
      auto node = q.front();
      q.pop_front();
      if (node->left == nullptr) {
        if (node->right != nullptr) {
          return false;
        }
        break;
      }
      q.emplace_back(node->left);
      if (node->right == nullptr) {
        break;
      }
      q.emplace_back(node->right);
    }
    while (!q.empty()) {
      auto node = q.front();
      q.pop_front();
      if (node->left != nullptr || node->right != nullptr) {
        return false;
      }
    }
    return true;
  }
};
