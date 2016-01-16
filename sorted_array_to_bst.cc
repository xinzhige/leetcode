class Solution {
public:
  TreeNode *SortedArrayToBSTHelper(vector<int> &num, int begin, int end) {
    if (begin > end) {
      return NULL;
    }
    int mid = begin + (end-begin)/2;
    TreeNode *root = new TreeNode(num[mid]);
    root->left = SortedArrayToBSTHelper(num, begin, mid-1);
    root->right = SortedArrayToBSTHelper(num, mid+1, end);
    return root;
  }
  TreeNode *sortedArrayToBST(vector<int> &num) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    if (num.size() == 0) {
      return NULL;
    }
    return SortedArrayToBSTHelper(num, 0, num.size()-1);
  }
};
