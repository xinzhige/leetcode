class Solution {
public:
  vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int> > result;
    queue<TreeNode *> myqueue;
    if (root != nullptr) {
      myqueue.push(root);	    
    }
    while (!myqueue.empty()) {
      vector<int> level;
      for (int i = myqueue.size(); i > 0; i--) {
        TreeNode* node = myqueue.front();
	level.push_back(node->val);
	if (node->left != nullptr) {
          myqueue.push(node->left);		
        }
	if (node->right != nullptr) {
          myqueue.push(node->right);		
	}
	myqueue.pop();
      }
      result.push_back(level);
    }
    reverse(result.begin(), result.end()); 
    return result;
  }
};
