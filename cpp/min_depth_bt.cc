// If one node has not left child, then its minDepth must be the minDepth of its right child and so does its right child.
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int left_height = minDepth(root->left);
        int right_height = minDepth(root->right);
        if (root->left == nullptr) {
            return 1 + right_height;
        }
        if (root->right == nullptr) {
            return 1 + left_height;
        }
        return left_height < right_height ? 1 + left_height : 1 + right_height;
    }
};


// By level traversal
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0; 
        }
        queue<DepthNode> q;
        DepthNode curr(root, 1); 
        q.emplace(curr);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            TreeNode* node = curr.node;   
            if (node->left == nullptr && node->right == nullptr) {
                return curr.depth; 
            } 
            if (node->left != nullptr) {
                DepthNode curr_left(node->left, 1 + curr.depth);
                q.emplace(curr_left);
            }
            if (node->right != nullptr) {
                DepthNode curr_right(node->right, 1 + curr.depth);
                q.emplace(curr_right);
            }
        }
        return 0;
    }
private:
    struct DepthNode {
        TreeNode* node;
        int depth;
        DepthNode(TreeNode* n, int d) : node(n), depth(d) { }
    };
};
