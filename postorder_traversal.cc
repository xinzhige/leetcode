// Use a stack and a list
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> mystack;
        list<int> mylist;
        if (root != nullptr) {
            mystack.push(root);
        }
        while (!mystack.empty()) {
            TreeNode* node = mystack.top();
            mystack.pop();
            mylist.emplace_front(node->val);
            if (node->left != nullptr) {
                mystack.push(node->left);
            }
            if (node->right != nullptr) {
                mystack.push(node->right);
            }
        }
        for (auto value : mylist) {
            result.emplace_back(value); 
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
