// recursive
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p == nullptr || q == nullptr || p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) 
            && isSameTree(p->right, q->right);
    }
};

// Iterative
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        queue<TreeNode *> queue1, queue2;
        queue1.emplace(p);
        queue2.emplace(q);
        while (!queue1.empty() && !queue2.empty()) {
            auto node1 = queue1.front();
            auto node2 = queue2.front();
            queue1.pop();
            queue2.pop();
            if (node1 == nullptr && node2 == nullptr) {
                continue; 
            }
            if (node1 == nullptr || node2 == nullptr) {
                return false;	      
            }
            if (node1->val != node2->val) {
                return false;	      
            }
            queue1.emplace(node1->left);
            queue2.emplace(node2->left);
            queue1.emplace(node1->right);
            queue2.emplace(node2->right);
        }
        return true;
    }
};
