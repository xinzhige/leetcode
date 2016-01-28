class BSTIterator {
private:
  stack<TreeNode *> mystack;
public:
  BSTIterator(TreeNode *root) {
    TreeNode *current = root;
    while (current != nullptr) {
      mystack.push(current);
      current = current->left;
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !mystack.empty(); 
  }
  
  /** @return the next smallest number */
  int next() {
    TreeNode *top = mystack.top();
    mystack.pop();
    if (top->right != nullptr) {
      TreeNode *current = top->right;
      while (current != nullptr) {
        mystack.push(current); 
	current = current->left; 
      }
    }
    return top->val;
  }
};

// use more space--one more array to store all the values of nodes but 
// more efficient on next()
class BSTIterator {
private:
  vector<int> values;
  int pos;
public:
  BSTIterator(TreeNode *root) {
    pos = 0;
    stack<TreeNode *> mystack;
    while (!mystack.empty() || root != nullptr) {
      if (root != nullptr) {
        mystack.push(root);
	root = root->left;
      }	else {
        root = mystack.top();
	mystack.pop();
        values.push_back(root->val);
	root = root->right;
      }   
    }
  }
  
  bool hasNext() {
    return pos < values.size(); 
  }
  
  int next() {
    pos += 1;
    return v[pos - 1];
  }
};
