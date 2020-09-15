// time: O(n)
class Solution {
public:
  vector<int> closestKValues(TreeNode* root, double target, int k) {
      queue<int> q;
      vector<int> res;
      inorder(root, target, k, q);
      for (; !q.empty(); q.pop()) {
          res.push_back(q.front());
      }
      return res;
  }
private:
    void inorder(TreeNode* root, double target, int k, queue<int> &q) {
        if (root != nullptr) {
            inorder(root->left, target, k, q);
            if (q.size() == k) {
                if (abs(target - root->val) < abs(target - q.front())) {
                    q.pop();
                } else {
                    return;
                }
            }
            q.push(root->val);
            inorder(root->right, target, k, q);
        }
    }
};

// time: O(logn)
class Solution {
public:
  vector<int> closestKValues(TreeNode* root, double target, int k) {
      stack<TreeNode *> smaller;
      stack<TreeNode *> larger;
      build_pre(root, target, smaller);
      build_suc(root, target, larger);
      if (!smaller.empty() && !larger.empty() && smaller.top() == larger.top()) {
          get_pre(smaller);
      }
      vector<int> res;
      for (int i = 0; i < k; i++) {
          if (smaller.empty()) {
              res.push_back(get_suc(larger));
          } else if (larger.empty()) {
              res.push_back(get_pre(smaller));
          } else {
              double pre_diff = fabs(smaller.top()->val - target);
              double suc_diff = fabs(larger.top()->val - target);
              res.push_back(pre_diff < suc_diff ? get_pre(smaller) : get_suc(larger));
          }
      }
      return res;
  }
private:
  void build_pre(TreeNode* root, double target, stack<TreeNode *> &s) {
      while (root != nullptr) {
          if (root->val == target) {
              s.push(root);
              break;
          } else if (root->val < target) {
              s.push(root);
              root = root->right;
          } else {
              root = root->left;
          }
      }
  }
  void build_suc(TreeNode* root, double target, stack<TreeNode *> &s) {
      while (root != nullptr) {
          if (root->val == target) {
              s.push(root);
              break;
          } else if (root->val > target) {
              s.push(root);
              root = root->left;
          } else {
              root = root->right;
          }
      }
  }
  int get_pre(stack<TreeNode* > &s) {
      TreeNode* node = s.top(); 
      s.pop();
      int res = node->val;
      node = node->left;
      while (node != nullptr) {
          s.push(node);
          node = node->right;
      }
      return res;
  }
  int get_suc(stack<TreeNode* > &s) {
      TreeNode* node = s.top();
      s.pop();
      int res = node->val;
      node = node->right;
      while (node != nullptr) {
          s.push(node);
          node = node->left;
      }
      return res;
  }
};