class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
      return root;
    }
    TreeNode *leftNode = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightNode = lowestCommonAncestor(root->right, p, q);
    if (leftNode == nullptr) {
      return rightNode;
    }
    if (rightNode == nullptr) {
      return leftNode;
    }
    return root;
  }
};


// Iterative
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *cur = root;
    TreeNode *last = nullptr;
    vector<TreeNode*> pathp;
    vector<TreeNode*> pathq;
    vector<TreeNode*> temp;
    while (pathp.empty() || pathq.empty()) {
      if (cur != nullptr) {
        temp.push_back(cur);
        if (temp.back() == p) {
          pathp = temp;
        }
        if (temp.back() == q) {
          pathq = temp;
        }
        cur = cur->left;
      } else {
        if (temp.back()->right != nullptr && temp.back()->right != last) {
          cur = temp.back()->right;
        } else {
          last = temp.back();
          temp.pop_back();
        }
      }
    }
    int n = min(pathp.size(), pathq.size());
    for (int i = 1; i < n; ++i) {
      if (pathp[i] != pathq[i]) {
        return pathp[i - 1];
      }
    }
    return pathp[n - 1];
  }
};
