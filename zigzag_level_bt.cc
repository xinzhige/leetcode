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
    if (nullptr == root) {
      return result;
    }
    queue<TreeNode*> q;
    bool left_to_right = true;
    vector<int> level;
    q.push(root);
    q.push(nullptr);  // level separator
    while (!q.empty()) {
      TreeNode *curr = q.front();
      q.pop();
      if (curr) {
	level.push_back(curr->val);
	if (curr->left) {
	  q.push(curr->left);
	}
	if (curr->right) {
	  q.push(curr->right);
	}
      } else {
	if (left_to_right) {
	  result.push_back(level);
	} else {
	  reverse(level.begin(), level.end());
	  result.push_back(level);
	}
	level.clear();
	left_to_right = !left_to_right;
	if (q.size() > 0) {
	  q.push(nullptr);
	}
      }
    }
    return result;
  }
};
