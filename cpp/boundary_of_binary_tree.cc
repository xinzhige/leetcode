// Idea: from left side, leaves and right side.
class Solution {
public:
  vector<int> boundaryOfBinaryTree(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) {
      return result;
    }
    if (root->left != nullptr || root->right != nullptr) {
      result.push_back(root->val);
    }
    leftBoundary(root->left, result);
    leaves(root, result);
    rightBoundary(root->right, result);
    return result;
  }
  void leftBoundary(TreeNode* node, vector<int>& result) {
    if (node != nullptr &&
        (node->left != nullptr || node->right != nullptr)) {
      result.push_back(node->val);
      if (node->left == nullptr) {
        leftBoundary(node->right, result);
      } else {
        leftBoundary(node->left, result);
      }
    }
  }
  void rightBoundary(TreeNode* node, vector<int>& result) {
    if (node != nullptr &&
        (node->left != nullptr || node->right != nullptr)) {
      if (node->right == nullptr) {
        rightBoundary(node->left, result);
      } else {
        rightBoundary(node->right, result);
      }
      result.push_back(node->val);
    }
  }
  void leaves(TreeNode* node, vector<int>& result) {
    if (node != nullptr) {
      if (node->left == nullptr && node->right == nullptr) {
        result.push_back(node->val);
      }
      leaves(node->left, result);
      leaves(node->right, result);
    }
  }
};


class Solution {
public:
  vector<int> boundaryOfBinaryTree(TreeNode* root) {
    vector<int> bounds;
    if (root != nullptr) {
      bounds.push_back(root->val);
      getBounds(root->left, bounds, true, false);
      getBounds(root->right, bounds, false, true);
    }
    return bounds;
  }
  void getBounds(TreeNode* node, vector<int>& result, bool lb, bool rb) {
    if (node != nullptr) {
      if (node->left == nullptr && node->right == nullptr) {
        result.push_back(node->val);
        return;
      }
      if (lb) {
        result.push_back(node->val);
      }
      getBounds(node->left, result, lb, rb && node->right == nullptr);
      getBounds(node->right, result, lb && node->left == nullptr, rb);
      if (rb) {
        result.push_back(node->val);
      }
    }
  }
};


// Iterative
class Solution {
public:
  vector<int> boundaryOfBinaryTree(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) {
      return result;
    }
    vector<int> right;
    TreeNode *l = root->left;
    TreeNode *r = root->right;
    TreeNode *p = root;
    if (root->left != nullptr || root->right != nullptr) {
      result.push_back(root->val);
    }
    while (l != nullptr && (l->left != nullptr || l->right != nullptr)) {
      result.push_back(l->val);
      if (l->left != nullptr) {
        l = l->left;
      } else {
        l = l->right;
      }
    }
    stack<TreeNode*> st;
    while (p != nullptr || !st.empty()) {
      if (p != nullptr) {
        st.push(p);
        if (p->left == nullptr && p->right == nullptr) {
          result.push_back(p->val);
        }
        p = p->left;
      } else {
        p = st.top();
        st.pop();
        p = p->right;
      }
    }
    while (r != nullptr && (r->left != nullptr || r->right != nullptr)) {
      right.push_back(r->val);
      if (r->right != nullptr) {
        r = r->right;
      } else {
        r = r->left;
      }
    }
    result.insert(result.end(), right.rbegin(), right.rend());
    return result;
  }
};
