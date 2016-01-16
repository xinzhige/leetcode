// recursive way
class Solution {
public:
  bool isSymmetricHelper(TreeNode* a, TreeNode* b) {
    if (a == nullptr && b == nullptr) {
      return true;
    }
    if (a == nullptr || b == nullptr) {
      return false;
    }
    if (a->val == b->val) {
      return isSymmetricHelper(a->left, b->right) && 
	isSymmetricHelper(a->right, b->left);
    }
    return false;
  }
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    return isSymmetricHelper(root->left, root->right);
  }
};

// iterative way, by queue
class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    queue<TreeNode*> my_queue;
    my_queue.push(root->left);
    my_queue.push(root->right);
    while (!my_queue.empty()) {
      TreeNode *left_child = my_queue.front();
      my_queue.pop();
      TreeNode *right_child = my_queue.front();
      my_queue.pop();
      if (left_child == nullptr && right_child == nullptr) {
	continue;
      }
      if (left_child == nullptr || right_child == nullptr || 
	  (left_child->val != right_child->val)) {
	return false;
      }
      my_queue.push(left_child->left);
      my_queue.push(right_child->right);
      my_queue.push(left_child->right);
      my_queue.push(right_child->left);
    }
    return true;
  }
};

// iterative way by 2 stacks and the idea is the same as the method 2
class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    s1.push(root->left);
    s2.push(root->right);
    while (!s1.empty() && !s2.empty()) {
      TreeNode* n1 = s1.top();
      s1.pop();
      TreeNode* n2 = s2.top();
      s2.pop();
      if (n1 == nullptr && n2 == nullptr) {
	continue;
      }
      if (n1 == nullptr || n2 == nullptr) {
	return false;
      }
      if (n1->val != n2->val) {
	return false;
      }
      s1.push(n1->left);
      s2.push(n2->right);
      s1.push(n1->right);
      s2.push(n2->left);
    }
    return true;
  }
};
