class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int> > result;
    queue<TreeNode *> myqueue;
    if (root) {
      myqueue.push(root);
    }
    while (!myqueue.empty()) {
      vector<int> level;
      for (int i = myqueue.size(); i > 0; i--) {
	TreeNode* node = myqueue.front();
	myqueue.pop();
	level.push_back(node->val);
	if (node->left) {
	  myqueue.push(node->left);	      
	}
	if (node->right) {
	  myqueue.push(node->right);	      
	}
      }
      result.push_back(level);
    }
    return result;
  }
};
