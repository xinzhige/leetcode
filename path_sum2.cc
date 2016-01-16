class Solution {
public:
  void findSol(TreeNode* root, int sum, vector<vector<int> > &all_sol, vector<int> &sol){
    if ( (root->left == NULL) && (root->right == NULL) && (sum-root->val == 0) ) { 
      sol.push_back(root->val); 
      all_sol.push_back(sol);
      return;    
    }
    sol.push_back(root->val);
    if (root->left != NULL){
      findSol(root->left, sum-root->val, all_sol, sol);
      sol.pop_back();
    }
    if (root->right != NULL){
      findSol(root->right, sum-root->val, all_sol, sol);    
      sol.pop_back();
    }
  }
  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > all_sol;
    vector<int> sol;
    if (root == NULL) {
      return all_sol;
    }
    findSol(root, sum, all_sol, sol);
    return all_sol;
  }
};
