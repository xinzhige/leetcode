class Solution {
public:
    void binaryTreePathsHelper(TreeNode* root, vector<int> solution, vector<string>& result) {
        if (root == nullptr) {
            return;
        }
        solution.emplace_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            stringstream ss;
            for (int i = 0; i < solution.size(); i++) {
                ss << solution[i] << ((i < solution.size() - 1) ? "->" : "");
            }
            result.emplace_back(ss.str());
            return;
        }
        binaryTreePathsHelper(root->left, solution, result);
        binaryTreePathsHelper(root->right, solution, result);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> solution;
        binaryTreePathsHelper(root, solution, result);
        return result;
    }
};
