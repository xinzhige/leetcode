class Solution {
public:
  int maxDepth(Node* root) {
    if (root == nullptr) {
      return 0;
    }
    if (root->children.empty()) {
      return 1;
    }
    int curr_depth = INT_MIN;
    for (const auto &it : root->children) {
      curr_depth = max(curr_depth, maxDepth(it));
    }
    return 1 + curr_depth;
  }
};
