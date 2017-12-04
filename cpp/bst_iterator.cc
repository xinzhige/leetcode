class BSTIterator {
public:
    BSTIterator(TreeNode *root) : curr(root) {
    }

  /** @return whether we have a next smallest number */
    bool hasNext() {
        return !mystack.empty() || curr != nullptr; 
    }
  
  /** @return the next smallest number */
    int next() {
        while (curr != nullptr) {
            mystack.emplace(curr); 
	        curr = curr->left; 
        }
        auto tmp = mystack.top();
        mystack.pop();
        curr = tmp->right;
        return tmp->val;
    }
private:
    stack<TreeNode *> mystack;
    TreeNode *curr;
};
