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
    stack<TreeNode *> mystack;
    TreeNode *last_visited = nullptr;
    TreeNode *node = root;
    while (!mystack.empty() || node != nullptr) {
      if (node != nullptr) {
        mystack.push(node);
	node = node->left;
      } else {
        TreeNode *curr = mystack.top(); 
	if (curr->right != nullptr && last_visited != curr->right) {
          node = curr->right;		
        } else {
	  result.push_back(curr->val);
	  mystack.pop();
	  last_visited = curr;
        } 
      } 
    }
    return result;
  }
};
