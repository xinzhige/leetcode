class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode *> myqueue;
        if (root != nullptr) {
            myqueue.push(root);
        }
        TreeNode *temp = nullptr;
        int curr_level_count = 0;
        while (!myqueue.empty())
        {
            curr_level_count = myqueue.size();
            vector<int> curr_level;
            while (curr_level_count > 0)
            {
                temp = myqueue.front();
                curr_level.push_back(temp->val);
                if (temp->left != nullptr) {
                    myqueue.push(temp->left);
                }
                if (temp->right != nullptr) {
                    myqueue.push(temp->right);
                }
                myqueue.pop();
                curr_level_count -= 1;
            }
            result.push_back(curr_level);
        }

        return result;
    }
};
