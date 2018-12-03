// Idea: go down to the left most leaf and the right leaf and compare them,
// if equal, then it is perfect binary tree. Otherwise, recursively count nodes.
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


// Idea: iterative, calculate height of right tree, if the same as height,
// go to right tree (plus 1 to result), otherwise go to left
// tree (plus 0 to result).
class Solution {
public:
  int countNodes(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    int height = 0;
    TreeNode* p = root;
    for (; p != nullptr; p = p->left) {
      height += 1;
    }
    int result = 1;
    int rheight = 0;
    TreeNode* visited = root;
    height -= 1;
    for (; height > 0; height -= 1) {
      result *= 2;
      rheight = 0;
      p = visited->right;
      for (; p != nullptr; p = p->left) {
        rheight += 1;
      }
      if (rheight < height) {
        visited = visited->left;
      } else {
        result += 1;
        visited = visited->right;
      }
    }
    return result;
  }
};
