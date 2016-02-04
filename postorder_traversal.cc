// simple but time consuming because of vector insertion
class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode*> mystack;
    if (root != nullptr) {
      mystack.push(root);
    }
    while (!mystack.empty()) {
      TreeNode* curr_node = mystack.top();
      mystack.pop();
      result.insert(result.begin(), curr_node->val);
      if (curr_node->left != nullptr) {
	mystack.push(curr_node->left);
      }
      if (curr_node->right != nullptr) {
	mystack.push(curr_node->right);
      }
    }
    return result;
  }
};

// traditional way by tracking a last node visited
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
      vector<int> result;
      if (root == nullptr) {
        return result;	  
      }
      stack<TreeNode *> mystack;
      TreeNode* last_visited = nullptr;
      while (!mystack.empty() || root != nullptr) {
        if (root != nullptr) {
          mystack.push(root);
          root = root->left;
        } else {
          TreeNode* node = mystack.top();
          if (node->right != nullptr &&
    	  last_visited != node->right) {
            root = node->right; 
          } else {
            mystack.pop();
    	    result.push_back(node->val);
    	    last_visited = node;
          }
        }
      }
      return result;
    }
};
