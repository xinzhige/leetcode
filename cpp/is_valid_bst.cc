// inorder solution, recursive version
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        TreeNode* prev = nullptr;
        return  validate(root, prev);
    }

private:
    bool validate(TreeNode* root, TreeNode* &prev) {
        if (root == nullptr) {
            return true;
        }
        if (!validate(root->left, prev)) {
            return false;
        }
        if (prev != nullptr && root->val <= prev->val) {
            return false;
        }
        prev = root;
        return validate(root->right, prev);
    }
};

// In C
int validate(node* root, node* minNode, node* maxNode) {
  if(root == NULL) {
    return 1;
  }
  if((minNode && root->val <= minNode->val) ||
     (maxNode && root->val >= maxNode->val)) {
    return 0;
  }
  return validate(root->left, minNode, root) &&
    validate(root->right, root, maxNode);
}

int isValidBST(node* root) {
  return validate(root, NULL, NULL);
}
