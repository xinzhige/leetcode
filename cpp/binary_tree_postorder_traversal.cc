// Two stacks
class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode*> mystack;
    stack<int> nums;
    if (root != nullptr) {
      mystack.push(root);
    }
    while (!mystack.empty()) {
      TreeNode* node = mystack.top();
      mystack.pop();
      nums.emplace(node->val);
      if (node->left != nullptr) {
        mystack.push(node->left);
      }
      if (node->right != nullptr) {
        mystack.push(node->right);
      }
    }
    for (; !nums.empty(); nums.pop()) {
      result.emplace_back(nums.top());
    }
    return result;
  }
};


// Morris traversal, space: O(1)
class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    TreeNode dump(0);
    dump.left = root;
    TreeNode *curr = &dump;
    TreeNode *prev = nullptr;
    vector<int> result;
    while (curr != nullptr) {
      if (curr->left == nullptr) {
        curr = curr->right;
      } else {
        prev = curr->left;
        while (prev->right != nullptr && prev->right != curr)
          prev = prev->right;
        if (prev->right == nullptr) {
          prev->right = curr;
          curr = curr->left;
        } else {
          printReverse(result, curr->left, prev);
          prev->right = nullptr;
          curr = curr->right;
        }
      }
    }
    return result;
  }
  void reverse(TreeNode *from, TreeNode *to) {
    if (from == to) {
      return;
    }
    TreeNode *x = from;
    TreeNode *y = from->right;
    TreeNode *z;
    while (true) {
      z = y->right;
      y->right = x;
      x = y;
      y = z;
      if (x == to) {
        break;
      }
    }
  }
  void printReverse(vector<int> &result, TreeNode* from, TreeNode *to) {
    reverse(from, to);
    TreeNode *p = to;
    while (true) {
      result.push_back(p->val);
      if (p == from) {
        break;
      }
      p = p->right;
    }
    reverse(to, from);
  }
};
