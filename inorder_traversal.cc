// iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> my_stack;
        while (root != nullptr || !my_stack.empty()) {
            if (root != nullptr) {
                my_stack.emplace(root);
                root = root>left;
            } else {
                root = my_stack.top();
                my_stack.pop();
                result.emplace_back(root->val);
                root = root->right;
            }
        }
        return result;
    }
};
