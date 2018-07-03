class Solution {
public:
  int countUnivalSubtrees(TreeNode* root) {
    int count = 0;       
    countUnivalSubtreesHelper(root, count);
    return count;
  }
  
  bool countUnivalSubtreesHelper(TreeNode* root, int &count) {
    if (root == nullptr) {
      return true; 
    } 
    auto leftSubtree = countUnivalSubtreesHelper(root->left, count);
    auto rightSubtree = countUnivalSubtreesHelper(root->right, count);
    if (leftSubtree && rightSubtree &&
        (root->left == nullptr || root->val == root->left->val) &&
        (root->right == nullptr || root->val == root->right->val)) {
      count += 1;
      return true;
    }
    return false;
  }
};
