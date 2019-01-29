class Solution {
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return build(inorder, 0, inorder.size() - 1,
                 postorder, 0, postorder.size() - 1);
  }
  TreeNode* build(vector<int> &inorder, int iLeft, int iRight,
                  vector<int> &postorder, int pLeft, int pRight) {
    if (iLeft > iRight || pLeft > pRight) {
      return nullptr;
    }
    int i = iLeft;
    for (; i <= iRight; ++i) {
      if (postorder[pRight] == inorder[i]) {
        break;
      }
    }
    TreeNode *node = new TreeNode(postorder[pRight]);
    node->left = build(inorder, iLeft, i - 1,
                       postorder, pLeft, pLeft + i - iLeft - 1);
    node->right = build(inorder, i + 1, iRight,
                        postorder, pRight + i - iLeft, pRight - 1);
    return node;
  }
};
