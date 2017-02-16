// Recursive: invert left tree and store it then invert right tree and assign it to left child lastly assign the temp to right child
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;	    
        } 
        swap(root->left, root->right); 
        invertTree(root->left);
        invertTree(root->right);
        return root; 
    }
};

// Non-recursive
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        stack<TreeNode *> mystack;
        mystack.emplace(root);
        while (!mystack.empty()) {
            TreeNode* curr = mystack.top();
            mystack.pop();
            swap(curr->left, curr->right);
            if (curr->left != nullptr) {
                mystack.emplace(curr->left);
            }
            if (curr->right != nullptr) {
                mystack.emplace(curr->right);
            }
        }
        return root;
    }
};
