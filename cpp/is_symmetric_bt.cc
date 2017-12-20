// recursive way
class Solution {
public:
    bool isSymmetricHelper(TreeNode* l, TreeNode* r) {
        if (l == nullptr && r == nullptr) {
            return true;
        }
        if (l == nullptr || r == nullptr) {
            return false;
        }
        if (l->val == r->val) {
            return isSymmetricHelper(l->left, r->right) && 
	            isSymmetricHelper(l->right, r->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        return isSymmetricHelper(root->left, root->right);
    }
};

// iterative way, by queue
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        queue<TreeNode*> my_queue;
        my_queue.push(root->left);
        my_queue.push(root->right);
        while (!my_queue.empty()) {
            TreeNode *left_child = my_queue.front();
            my_queue.pop();
            TreeNode *right_child = my_queue.front();
            my_queue.pop();
            if (left_child == nullptr && right_child == nullptr) {
                continue;
            }
            if (left_child == nullptr || right_child == nullptr || 
                (left_child->val != right_child->val)) {
                return false;
            }
            my_queue.push(left_child->left);
            my_queue.push(right_child->right);
            my_queue.push(left_child->right);
            my_queue.push(right_child->left);
        }
        return true;
    }
};