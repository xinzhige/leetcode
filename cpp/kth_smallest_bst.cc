// Recursive
class Solution {
public:
  int kthSmallestHelper(TreeNode* root, int& k) {
    if (root == nullptr) {
      return INT_MIN;    
    }
    int result = kthSmallestHelper(root->left, k);
    if (k == 0) {
      return result;	    
    }
    k -= 1;
    if (k == 0) {
      return root->val;	    
    }
    return kthSmallestHelper(root->right, k);
  }
  int kthSmallest(TreeNode* root, int k) {
    return kthSmallestHelper(root, k);
  }
};


// Non-recursive
class Solution {
public:
  int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> mystack;
    while (!mystack.empty() || root != nullptr) {
      while (root != nullptr) {
        mystack.push(root);
	root = root->left;
      }	   
      TreeNode* curr = mystack.top();      
      k -= 1;
      if (k == 0) {
        return curr->val;    
      }
      root = curr->right;
      mystack.pop();
    }
    return INT_MIN;
  }
};
