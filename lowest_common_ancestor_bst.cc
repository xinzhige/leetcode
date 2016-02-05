class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root != nullptr) {
      if (root->val < p->val && root->val < q->val) {
        root = root->right;
      }	   
      if (root->val > p->val && root->val > q->val) {
        root = root->left;
      }
      return root;
    }
    return nullptr;
  }
};
