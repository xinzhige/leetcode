// time: O(n^2)
class Solution {
public:
    typedef vector<int>::iterator Iter;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTreeRecur(inorder.begin(), inorder.end(), preorder.begin(), preorder.end());
    }
    TreeNode *buildTreeRecur(Iter istart, Iter iend, Iter pstart, Iter pend) {
        if(istart == iend) {
            return nullptr;
        }
        int rootval = *pstart;
        Iter iterroot = find(istart, iend, rootval);
        TreeNode *res = new TreeNode(rootval);
        res->left = buildTreeRecur(istart, iterroot, pstart + 1, pstart + 1 + (iterroot - istart));
        res->right = buildTreeRecur(iterroot + 1, iend, pstart + 1 + (iterroot - istart), pend);
        return res;
    }
};