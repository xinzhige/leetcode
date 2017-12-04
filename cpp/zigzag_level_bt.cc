// 2 stacks
class Solution {
public:
  vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> > result;
    if(root == nullptr) {
      return result;
    }
    vector<int> tmp;
    stack<TreeNode*> current_level, next_level;
    bool left_to_right = true;
    current_level.push(root);
    while (!current_level.empty()) {
      TreeNode *current_node = current_level.top();
      current_level.pop();
      tmp.push_back(current_node->val);
      if (left_to_right) {
    	if (current_node->left != nullptr) {
    	  next_level.push(current_node->left);
    	}
    	if (current_node->right != nullptr) {
    	  next_level.push(current_node->right);
    	}
      } else {
    	if (current_node->right != nullptr) {
    	  next_level.push(current_node->right);
    	}
    	if (current_node->left != nullptr) {
    	  next_level.push(current_node->left);
    	}
      }
      if (current_level.empty()) {
    	result.push_back(tmp);
    	tmp.clear();
    	left_to_right = !left_to_right;
    	current_level.swap(next_level);
      } 
    }
    return result;
  }
};

// 1 queue
class Solution {
public:
  vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> > result;
    if (root == nullptr) {
      return result;	    
    }
    int level = 0;
    TreeNode *last = root;
    queue<TreeNode *> myqueue;
    myqueue.push(root);
    result.push_back(vector<int> ());
    while (!myqueue.empty()) {
      TreeNode *curr = myqueue.front();
      myqueue.pop();
      result[level].insert((level % 2) ? result[level].begin() : result[level].end(), curr->val); 
      if (curr->left) {
        myqueue.push(curr->left);	      
      }
      if (curr->right) {
        myqueue.push(curr->right);	      
      }
      if (curr == last) {
        level += 1;
	last = myqueue.back();
	result.push_back(vector<int> ());
      } 
    }
    result.pop_back();
    return result;
  }
};
