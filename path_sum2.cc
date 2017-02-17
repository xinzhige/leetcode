class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> result;
        vector<int> tmp;
        dfs(root, sum, tmp, result);
        return result;
    }

private:
    void dfs(TreeNode* root, int sum, vector<int>& tmp, vector<vector<int>>& result) {
        if (root == nullptr) {
            return; 
        }
        if (root->left == nullptr && root->right == nullptr && 
            root->val == sum) { 
            tmp.emplace_back(root->val); 
            result.emplace_back(tmp);
            return;    
        }
        tmp.emplace_back(root->val);
        if (root->left != nullptr) {
            dfs(root->left, sum - root->val, tmp, result);
            tmp.pop_back();
        }
        if (root->right != nullptr) {
            dfs(root->right, sum - root->val, tmp, result);    
            tmp.pop_back();
        }
    }
};
