class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            bool cousin = false;
            bool sibling = false;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                if (node == nullptr) {
                    sibling = false;
                } else {
                    if (node->val == x || node->val == y) {
                        if (!cousin) {
                            cousin = true;
                            sibling = true;
                        } else {
                            return !sibling;
                        }
                    }
                    if (node->left != nullptr) {
                        q.push(node->left);
                    }
                    if (node->right != nullptr) {
                        q.push(node->right);
                    }
                    q.push(nullptr);
                }
            }
            if (cousin) {
                return false;
            }
        }
        return false;
    }
};