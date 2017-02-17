// Two stacks
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> mystack;
        stack<int> nums;
        if (root != nullptr) {
            mystack.push(root);
        }
        while (!mystack.empty()) {
            TreeNode* node = mystack.top();
            mystack.pop();
            nums.emplace(node->val);
            if (node->left != nullptr) {
                mystack.push(node->left);
            }
            if (node->right != nullptr) {
                mystack.push(node->right);
            }
        }
        for (; !nums.empty(); nums.pop()) {
            result.emplace_back(nums.top()); 
        }
        return result;
    }
};

// Tracking a last visited node
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> mystack;
        TreeNode* last_visited = nullptr;
        while (!mystack.empty() || root != nullptr) {
            if (root != nullptr) {
                mystack.emplace(root);
                root = root->left;
            } else {
                TreeNode* node = mystack.top();
                if (node->right != nullptr &&
                    last_visited != node->right) {
                    root = node->right; 
                } else {
                    mystack.pop();
                    result.emplace_back(node->val);
                    last_visited = node;
                }
            }
        }
        return result;
    }
};
