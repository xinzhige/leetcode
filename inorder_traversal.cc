// recursive
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        if (root->left != NULL) {
            vector<int> result_left = inorderTraversal(root->left);
            for (int i = 0; i < result_left.size(); i++) {
                result.push_back(result_left.at(i));
            }
        }
        result.push_back(root->val);
        if (root->right != NULL) {
            vector<int> result_right = inorderTraversal(root->right);
            for (int i = 0; i < result_right.size(); i++) {
                result.push_back(result_right.at(i));
            }
        }
        return result;
    }
};

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
