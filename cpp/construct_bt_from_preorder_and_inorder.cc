class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return buildTree(preorder, 0, preorder.size() - 1, inorder, 0,
                     inorder.size() - 1);
  }
  TreeNode *buildTree(vector<int> &preorder, int pLeft, int pRight,
                      vector<int> &inorder, int iLeft, int iRight) {
    if (pLeft > pRight || iLeft > iRight) {
      return nullptr;
    }
    int i = iLeft;
    for (; i <= iRight; ++i) {
      if (preorder[pLeft] == inorder[i]) {
        break;
      }
    }
    TreeNode *cur = new TreeNode(preorder[pLeft]);
    cur->left = buildTree(preorder, pLeft + 1, pLeft + i - iLeft, inorder,
                          iLeft, i - 1);
    cur->right = buildTree(preorder, pLeft + i - iLeft + 1, pRight, inorder,
                           i + 1, iRight);
    return cur;
  }
};
