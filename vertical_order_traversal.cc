/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        unordered_map<int, vector<int>> cols;
        queue<pair<TreeNode *, int>> q;
        q.emplace(root, 0);
        for (; !q.empty(); q.pop()) {
            TreeNode *node;
            int j;
            tie(node, j) = q.front();
            if (node != nullptr) {
                cols[j].emplace_back(node->val);
                q.emplace(node->left, j - 1);
                q.emplace(node->right, j + 1);
            }
        }
        int min_idx = numeric_limits<int>::max();
        int max_idx = numeric_limits<int>::min();
        for (const auto& col : cols) {
            min_idx = min(min_idx, col.first);
            max_idx = max(max_idx, col.first);
        }
        vector<vector<int>> result;
        for (int i = min_idx; i <= max_idx; ++i) {
            result.emplace_back(cols[i]);
        }
        return result;        
    }
};
