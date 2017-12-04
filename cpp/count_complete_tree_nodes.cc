class Solution {
public:
  int countNodes(TreeNode* root) {
    int hleft = 0;
    int hright = 0;
    for (TreeNode *pleft = root; pleft; pleft = pleft->left) {
      ++hleft;
    }
    for (TreeNode *pright = root; pright; pright = pright->right) {
      ++hright;
    }
    if (hleft == hright) {
      return pow(2, hleft) - 1;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
  }
};
