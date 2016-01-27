class Solution {
public:
  vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int> > result;
    if (root == nullptr) {
      return result;	    
    }
    TreeNode *tmp = nullptr;
    int curr_level_count = 0;
    queue<TreeNode *> myqueue;
    myqueue.push(root);
    while (!myqueue.empty()) {
      curr_level_count = myqueue.size();
      vector<int> curr_level;
      while (curr_level_count) {
        tmp = myqueue.front();
	curr_level.push_back(tmp->val);
	if (tmp->left != nullptr) {
          myqueue.push(tmp->left);		
        }
	if (tmp->right != nullptr) {
          myqueue.push(tmp->right);		
	}
	myqueue.pop();
	curr_level_count -= 1;
      }
      result.insert(result.begin(), curr_level);
    }
    return result;
  }
};
