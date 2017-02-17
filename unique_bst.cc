class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> result;
        if (n > 0) {
            result = generate(1, n);
        }
        return result;
    }

private:
    vector<TreeNode *> generate(int begin, int end) {
        vector<TreeNode *> v;
        if (begin > end) {
            v.emplace_back(nullptr);
            return v;
        }
        for (int k = begin; k <= end; k++) {
            vector<TreeNode *> left_tree = generate(begin, k - 1);
            vector<TreeNode *> right_tree = generate(k + 1, end);
            for (auto i : left_tree) {
                for (auto j : right_tree) {
                    TreeNode *curr = new TreeNode(k);
                    curr->left = i;
                    curr->right =j;
                    v.emplace_back(curr);
                }
            }
        }
        return v;
    }
};
