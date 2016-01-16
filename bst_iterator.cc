/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
